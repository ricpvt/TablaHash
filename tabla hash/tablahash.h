#ifndef TablaHash_H_INCLUDED
#define TablaHash_H_INCLUDED

#include <iostream>
#include <string>

/**
 * \struct Element
 * \brief Estructura que representa un Elemento de la tabla hash.
 */
struct Element
{
    std::string Nombre; /**< Nombre del Elemento */
    int Id; /**< Identificador del Elemento */
};

/**
 * \class TablaHash
 * \brief Clase que representa una tabla hash con resolución de colisiones mediante direccionamiento abierto.
 */
class TablaHash
{
public:
    /**
     * \brief Constructor de la clase TablaHash.
     * \param capacidad La capacidad inicial de la tabla hash.
     */
    TablaHash(int capacidad);

    /**
     * \brief Constructor de copia de la clase TablaHash.
     * \param otraTabla La tabla hash a copiar.
     */
    TablaHash(const TablaHash& otraTabla);

    /**
     * \brief Operador de asignación de la clase TablaHash.
     * \param otraTabla La tabla hash a asignar.
     * \return Una referencia a la tabla hash actualizada.
     */
    TablaHash& operator=(const TablaHash& otraTabla);

    /**
     * \brief Destructor de la clase TablaHash.
     */
    ~TablaHash();

    /**
     * \brief Inserta un Elemento en la tabla hash.
     * \param elemento El Elemento a insertar.
     */
    void InsertarElemento(const Element& elemento);

    /**
     * \brief Elimina un Elemento de la tabla hash por su id.
     * \param id El id del Elemento a eliminar.
     */
    void EliminarElemento(int id);

    /**
     * \brief Vacía la tabla hash, eliminando todos los Elementos.
     */
    void VaciarTabla();

    /**
     * \brief Imprime los Elementos de la tabla hash.
     */
    void ImprimirTabla() const;

    /**
     * \brief Obtiene el nombre de un Elemento por su id.
     * \param id El id del Elemento.
     * \return El nombre del Elemento.
     */
    std::string ObtenerNombreElemento(int id) const;

    /**
     * \brief Obtiene el número de Elementos en la tabla hash.
     * \return El número de Elementos.
     */
    int ObtenerNumeroDeElementos() const;

    /**
     * \brief Verifica si la tabla hash está vacía.
     * \return true si la tabla está vacía, false en caso contrario.
     */
    bool EstaVacia() const;

    /**
     * \brief Busca un Elemento en la tabla hash por su id.
     * \param id El id del Elemento a buscar.
     * \return true si el Elemento se encuentra en la tabla, false en caso contrario.
     */
    bool Buscar(int id) const;

    /**
     * \brief Obtiene la capacidad actual de la tabla hash.
     * \return La capacidad de la tabla hash.
     */
    int ObtenerCapacidad() const;

private:
    /**
     * \brief Calcula la función hash para un id.
     * \param id El id del Elemento.
     * \return El valor hash calculado.
     */
    int FuncionHash(int id) const;

    /**
     * \brief Redimensiona la tabla hash cuando se alcanza la capacidad máxima.
     */
    void RedimensionarTabla();

    /**
     * \brief Reorganiza la tabla hash para llenar el hueco dejado por una eliminación.
     * \param indice El índice del hueco dejado por la eliminación.
     */
    void ReorganizarTabla(int indice);

    Element** tabla; /**< Array que almacena los Elementos de la tabla hash */
    int Capacidad; /**< Capacidad actual de la tabla hash */
    int NumeroDeElementos; /**< Número de Elementos en la tabla hash */
    static const Element MARCA_ELIMINADO; /**< Constante para indicar un Elemento eliminado */
};

#endif // TablaHash_H_INCLUDED
