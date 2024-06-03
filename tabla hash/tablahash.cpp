#include "TablaHash.h"

// Constante para indicar un Elemento eliminado
const Element TablaHash::MARCA_ELIMINADO = {"", -1};

// Constructor de la clase TablaHash
TablaHash::TablaHash(int capacidad) : Capacidad(capacidad), NumeroDeElementos(0)
{
    tabla = new Element*[Capacidad];
    for (int i = 0; i < Capacidad; ++i)
    {
        tabla[i] = nullptr;
    }
}

// Constructor de copia de la clase TablaHash
TablaHash::TablaHash(const TablaHash& otraTabla) : Capacidad(otraTabla.Capacidad), NumeroDeElementos(otraTabla.NumeroDeElementos)
{
    tabla = new Element*[Capacidad];
    for (int i = 0; i < Capacidad; ++i)
    {
        if (otraTabla.tabla[i] != nullptr && otraTabla.tabla[i] != &MARCA_ELIMINADO)
        {
            tabla[i] = new Element(*otraTabla.tabla[i]);
        }
        else
        {
            tabla[i] = otraTabla.tabla[i];
        }
    }
}

// Sobrecarga del operador de asignación (=) de la clase TablaHash
TablaHash& TablaHash::operator=(const TablaHash& otraTabla)
{
    if (this == &otraTabla)
    {
        return *this;
    }

    for (int i = 0; i < Capacidad; ++i)
    {
        delete tabla[i];
    }
    delete[] tabla;

    Capacidad = otraTabla.Capacidad;
    NumeroDeElementos = otraTabla.NumeroDeElementos;

    tabla = new Element*[Capacidad];
    for (int i = 0; i < Capacidad; ++i)
    {
        if (otraTabla.tabla[i] != nullptr && otraTabla.tabla[i] != &MARCA_ELIMINADO)
        {
            tabla[i] = new Element(*otraTabla.tabla[i]);
        }
        else
        {
            tabla[i] = otraTabla.tabla[i];
        }
    }

    return *this;
}

// Destructor de la clase TablaHash
TablaHash::~TablaHash()
{
    for (int i = 0; i < Capacidad; ++i)
    {
        delete tabla[i];
    }
    delete[] tabla;
}

// Inserta un Elemento en la tabla hash
void TablaHash::InsertarElemento(const Element& elemento)
{
    if (NumeroDeElementos >= Capacidad * 0.7) // Factor de carga del 70%
    {
        RedimensionarTabla();
    }

    int indice = FuncionHash(elemento.Id);
    while (tabla[indice] != nullptr && tabla[indice]->Id != elemento.Id && tabla[indice] != &MARCA_ELIMINADO)
    {
        indice = (indice + 1) % Capacidad;
    }

    if (tabla[indice] == nullptr || tabla[indice] == &MARCA_ELIMINADO)
    {
        delete tabla[indice]; // Elimina el marcador de eliminado si existe
        tabla[indice] = new Element(elemento);
        ++NumeroDeElementos;
    }
}

// Elimina un Elemento de la tabla hash por su id
void TablaHash::EliminarElemento(int id)
{
    int indice = FuncionHash(id);
    while (tabla[indice] != nullptr)
    {
        if (tabla[indice]->Id == id)
        {
            delete tabla[indice];
            tabla[indice] = const_cast<Element*>(&MARCA_ELIMINADO);
            --NumeroDeElementos;
            return;
        }
        indice = (indice + 1) % Capacidad;
    }
}

// Vacía la tabla hash, eliminando todos los Elementos
void TablaHash::VaciarTabla()
{
    for (int i = 0; i < Capacidad; ++i)
    {
        delete tabla[i];
        tabla[i] = nullptr;
    }
    NumeroDeElementos = 0;
}

// Imprime los Elementos de la tabla hash
void TablaHash::ImprimirTabla() const
{
    for (int i = 0; i < Capacidad; ++i)
    {
        if (tabla[i] != nullptr && tabla[i] != &MARCA_ELIMINADO)
        {
            std::cout << "Indice " << i << ": [" << tabla[i]->Nombre << "] (ID: " << tabla[i]->Id << ")\n";
        }
    }
}

// Obtiene el nombre de un Elemento por su id
std::string TablaHash::ObtenerNombreElemento(int id) const
{
    int indice = FuncionHash(id);
    while (tabla[indice] != nullptr)
    {
        if (tabla[indice]->Id == id)
        {
            return tabla[indice]->Nombre;
        }
        indice = (indice + 1) % Capacidad;
    }
    return "";
}

// Obtiene el número de Elementos en la tabla hash
int TablaHash::ObtenerNumeroDeElementos() const
{
    return NumeroDeElementos;
}

// Verifica si la tabla hash está vacía
bool TablaHash::EstaVacia() const
{
    return NumeroDeElementos == 0;
}

// Busca un Elemento en la tabla hash por su id
bool TablaHash::Buscar(int id) const
{
    int indice = FuncionHash(id);
    while (tabla[indice] != nullptr)
    {
        if (tabla[indice]->Id == id)
        {
            return true;
        }
        indice = (indice + 1) % Capacidad;
    }
    return false;
}

// Obtiene la capacidad actual de la tabla hash
int TablaHash::ObtenerCapacidad() const
{
    return Capacidad;
}

// Calcula la función hash para un id
int TablaHash::FuncionHash(int id) const
{
    return id % Capacidad;
}

// Redimensiona la tabla hash cuando se alcanza la capacidad máxima
void TablaHash::RedimensionarTabla()
{
    int nuevaCap = Capacidad * 2;
    Element** nuevaTabla = new Element*[nuevaCap];
    for (int i = 0; i < nuevaCap; ++i)
    {
        nuevaTabla[i] = nullptr;
    }

    for (int i = 0; i < Capacidad; ++i)
    {
        if (tabla[i] != nullptr && tabla[i] != &MARCA_ELIMINADO)
        {
            int indice = tabla[i]->Id % nuevaCap;
            while (nuevaTabla[indice] != nullptr)
            {
                indice = (indice + 1) % nuevaCap;
            }
            nuevaTabla[indice] = tabla[i];
        }
    }

    delete[] tabla;
    tabla = nuevaTabla;
    Capacidad = nuevaCap;
}

// Reorganiza la tabla hash para llenar el hueco dejado por una eliminación
void TablaHash::ReorganizarTabla(int indice)
{
    int original = indice;
    int current = (indice + 1) % Capacidad;

    while (tabla[current] != nullptr)
    {
        int hashedIndex = FuncionHash(tabla[current]->Id);
        if ((current > original && (hashedIndex <= original || hashedIndex > current)) ||
            (current < original && (hashedIndex <= original && hashedIndex > current)))
        {
            tabla[original] = tabla[current];
            tabla[current] = nullptr;
            original = current;
        }
        current = (current + 1) % Capacidad;
    }
}

