#ifndef TABLA_HASH_DIRA_H_INCLUDED
#define TABLA_HASH_DIRA_H_INCLUDED

template<typename K, template V>
class TablaHashDirA{
public:
    /* Constructor por default */
    TablaHashDirA();

    /* Destructor por default */
    ~TablaHashDirA();

    /* Constructor de copias */
    TablaHashDirA(const TablaHashDirA& otro);

    /* Operador de asignacion */
    TablaHashDirA& operator=(const TablaHashDirA& otro);

    /* Agregar Clave y Valor (valor asociado a la clave) */
    void Agregar(const &K clave, const &V valor);

    /* Buscar Valor por Clave */
    V BuscarValor(const &K clave) const;

    /* Capturar Clave */
    K CapturarClave();

    /* Capturar Valor */
    V CapturarValor();

    /* Buscar si Existe la Clave */
    bool BuscarClave(const &K clave) const;

    /* Eliminar Clave y Valor */
    void Eliminar(const &K clave);

    /* Imprimir los elementos de la tabla */
    void Imprimir();

    /* Vaciar todo el contenido de la tabla */
    void Vaciar();

    /* Contar cuantas Colisiones Ocurrieron */
    int ContarColisiones() const;

    /* Mostrar Colisiones en la Tabla Hash */
    void MostrarColisiones(const TablaHashDirA<K, V>& otro);

    /* Obtener el Numero de Elementos */
    int ObtenerNumElementos() const;

    /* Verifica si la Tabla Esta Vacia  */
    bool EstaVacia();


private:

    struct Elemento{
        /* Constructor de la Estructura Elemento */
        Elemento(const K& c, const V& v) : clave(c), valor(v) {}

        K clave; /* Clave de la Tabla */
        V valor; /* Valor de la Tabla */
    };
    int tam; // Tamaño del Arreglo */
    Elemento** tabla; /* Puntero a un Arreglo de Punteros */
    int NumElementos; /* Numero de Elementos en la Tabla Hash */

    /* Puntero a Funcion Hash que se Utilizara Para Calcular el Indice de una Clave en la Tabla Hash */
    int (*funcionHash)(const K&);

    /* Calcula el Indice Hash para una Clave */
    int IndiceHash(const K& clave) const;

    /* Redimensionar la Tabla Hash a un Nuevo Tamaño */
    void Redimensionar(int nuevoTam);

    /* Verifica si el Indice del Arreglo Esta Vacio */
    bool IndiceVacio(int indice);

    /* Obtener el n-esimo numero primo para redimensionar */
    int ObtenerPrimoMayor(int n);
};

#include "Tabla_Hash_DirA.tpp"

#endif // TABLA_HASH_DIRA_H_INCLUDED
