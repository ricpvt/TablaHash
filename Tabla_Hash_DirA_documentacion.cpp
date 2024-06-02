/**
 * \file Tabla_Hash_DirA.h
 * \brief Tabla Hash de direccionamiento abierto.
 * \author Ricardo.
 * \author Brayan Alexis P&eacute;rez Cordova.
 * \author Jose.
 * \author Pablo Andr&eacute;s Gonz&aacute;lez Arg&uuml;elles.
 *
 * \date 3/06/2024
 *
 */

#ifndef TABLA_HASH_DIRA_H_INCLUDED
#define TABLA_HASH_DIRA_H_INCLUDED

/** \class TablaHashDirA
 * Creaci&oacute;n de una tabla Hash de direccionamiento abierto
 *
 */
template<typename C, template V>
class TablaHashDirA{
public:
    /* Constructor por default */
    /** \brief Construye una objeto Grafica */
    TablaHashDirA();

    /* Destructor por default */
    /** \brief Destructor del objeto Grafica */
    ~TablaHashDirA();

    /* Constructor de copias */

    /** \brief Constructor de copias
     *
     * \param otro const TablaHashDirA& Referencia de una TablaHashDirA constante para crear copia.
     *
     */
    TablaHashDirA(const TablaHashDirA& otro);

    /* Operador de asignacion */

    /** \brief Operador de asignaci&oacute;n para TablaHashDirA.
     *
     * \param otro const TablaHashDirA& Referencia de una TablaHashDirA constante que se desea igualar.
     * \return TablaHashDirA& Devuelve una referencia de un objeto de tipo TablaHashDirA.
     *
     */
    TablaHashDirA& operator=(const TablaHashDirA& otro);

    /* Agregar Clave y Valor (valor asociado a la clave) */
    /** \brief Agregar Clave y Valor (valor asociado a la clave)
     *
     * \param clave const &C Referencia constante utilizada como clave.
     * \param valor const &V Referencia constante utilizada como valor al que se le asigna una clave.
     *
     */
    void Agregar(const &C clave, const &V valor);

    /* Buscar Valor por Clave */
    /** \brief Busca un valor por medio de la clave
     *
     * \param clave const &C Referencia constante utilizada para buscar el valor.
     * \return V Retorna un valor tipo V
     *
     */
    V BuscarValor(const &C clave) const;

    /* Capturar Clave */
    /** \brief Captura una clave
     *
     * \return C Retorna un clave tipo C
     *
     */
    C CapturarClave();

    /* Capturar Valor */
    /** \brief Captura un valor
     *
     * \return V Retorna un valor tipo V
     *
     */
    V CapturarValor();

    /* Buscar si Existe la Clave */
    /** \brief Buscar si existe la Clave
     *
     * \param clave const &C Referencia constante utilizada para buscar la clave.
     * \return bool Retorna verdadero (true) si encuentra la clave.
     *
     */
    bool BuscarClave(const &C clave) const;

    /* Eliminar Clave y Valor */
    /** \brief Elimina la clave y el valor.
     *
     * \param clave const &C Referencia utilizada para eliminar una clave y su valor.
     *
     */
    void Eliminar(const &C clave);

    /* Imprimir los elementos de la tabla */
    /** \brief Imprimir los elementos de la tabla
     *
     */
    void Imprimir();

    /* Vaciar todo el contenido de la tabla */
    /** \brief Vac&iacute;a todo el contenido de la tabla
     */
    void Vaciar();

    /* Contar cuantas Colisiones Ocurrieron */
    /** \brief Contar cuantas colisiones ocurrieron
     *
     * \return int Retorna un n&uacute;mero entero.
     *
     */
    int ContarColisiones() const;

    /* Mostrar Colisiones en la Tabla Hash */
    /** \brief Muestra colisiones en la tabla de Hash
     *
     * \param TablaHashDirA<C const
     * \param otro V>&
     *
     */
    void MostrarColisiones(const TablaHashDirA<C, V>& otro);

    /* Obtener el Numero de Elementos */
    /** \brief  Obtiene el n&uacute;mero de elementos en la tabla
     *
     * \return int Retorna el n&uacute;mero de elementos en la tabla.
     *
     */
    int ObtenerNumElementos() const;

    /* Verifica si la Tabla Esta Vacia  */
    /** \brief Verifica si la tabla esta vac&iacute;a.
     *
     * \return bool Retorna verdadero (true) si la tabla esta vac&iacute;a.
     *
     */
    bool EstaVacia();


private:

    /** \brief Elemento
     */
    struct Elemento{
        /* Constructor de la Estructura Elemento */
        /** \brief Constructor de la estructura elemento
         *
         * \param v
         * \param c
         * \return Elemento(const C& c, const V& v) : clave(c), valor(v)
         *
         */
        Elemento(const C& c, const V& v) : clave(c), valor(v) {}

        C clave;/**< Clave de la tabla */ /* Clave de la Tabla */
        V valor; /**< Valor de la tabla *//* Valor de la Tabla */
    };
    int tam; /**< Tamaño del arreglo */
    Elemento** tabla; /**< Puntero a un arreglo de punteros */
    int NumElementos; /**< N&uacute;mero de elementos en la tabla Hash */

    /* Puntero a Funcion Hash que se Utilizara Para Calcular el Indice de una Clave en la Tabla Hash */
    /** \brief Puntero a funci&oacute;n Hash que se utilizara para calcular el &iacute;ndice de una clave en la tabla Hash.
     *
     * \param C& const Referencia constante de una clave.
     * \return int Retorna un n&uacute;mero entero.
     *
     */
    int (*funcionHash)(const C&);

    /* Calcula el Indice Hash para una Clave */
    /** \brief Calcula el &iacute;ndice Hash para una Clave.
     *
     * \param clave const C& Referencia constante de una clave.
     * \return int Retorna el n&uacute;mero utilizado como indice en la tabla.
     *
     */
    int IndiceHash(const C& clave) const;

    /* Redimensionar la Tabla Hash a un Nuevo Tamaño */
    /** \brief Redimensiona la tabla Hash.
     *
     * \param nuevoTam int Nuevo tama&ntilde;o que tendr&aacute; la tabla.
     *
     */
    void Redimensionar(int nuevoTam);

    /* Verifica si el Indice del Arreglo Esta Vacio */
    /** \brief Verifica si el &iacute;ndice del arreglo esta vac&iacute;o
     *
     * \param indice int N&uacute;mero utilizado como indice de la tabla.
     * \return bool Si el &iacute;ndice esta vac&iacute;o regresa verdadero (true).
     *
     */
    bool IndiceVacio(int indice);

    /* Obtener el n-esimo numero primo para redimensionar */
    /** \brief Obtener el n-esimo n&uacute;mero primo para redimensionar
     *
     * \param n int N&uacute;mero entero.
     * \return int  Retorna un n&uacute;mero primo mayor.
     *
     */
    int ObtenerPrimoMayor(int n);
};

#include "Tabla_Hash_DirA.tpp"

#endif // TABLA_HASH_DIRA_H_INCLUDED
