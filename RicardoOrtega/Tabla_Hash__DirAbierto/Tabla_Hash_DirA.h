#ifndef TABLA_HASH_DIRA_H_INCLUDED
#define TABLA_HASH_DIRA_H_INCLUDED

#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <limits>
#include <stdexcept>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::numeric_limits;
using std::max;
using std::string;
using std::setw;
using std::ws;

/**
 * @brief Clase TablaHashDirA que implementa una tabla hash con direccionamiento abierto.
 *
 * @tparam C Tipo de las claves.
 * @tparam V Tipo de los valores.
 */
template<typename C, typename V>
class TablaHashDirA {
public:
    /**
     * @brief Constructor que inicializa la tabla hash.
     *
     * @param tamH Tamaño inicial de la tabla.
     * @param funcHash Puntero a la función de hash que será utilizada.
     */
    TablaHashDirA(int tamH, int (*funcHash)(const C&));

    /**
     * @brief Destructor que libera los recursos de la tabla hash.
     */
    ~TablaHashDirA();

    /**
     * @brief Constructor de copia.
     *
     * @param otro Objeto de tipo TablaHashDirA a copiar.
     */
    TablaHashDirA(const TablaHashDirA& otro);

    /**
     * @brief Operador de asignación.
     *
     * @param otro Objeto de tipo TablaHashDirA a asignar.
     * @return Referencia a esta tabla hash.
     */
    TablaHashDirA& operator=(const TablaHashDirA& otro);

    /**
     * @brief Agrega un nuevo elemento a la tabla hash.
     *
     * @param clave Clave del elemento a agregar.
     * @param valor Valor del elemento a agregar.
     */
    void Agregar(const C& clave, const V& valor);

    /**
     * @brief Busca un valor en la tabla hash por su clave.
     *
     * @param clave Clave del elemento a buscar.
     * @return Valor del elemento encontrado.
     * @throws std::runtime_error Si la clave no se encuentra.
     */
    V Buscar(const C& clave) const;

    /**
     * @brief Captura una clave del usuario.
     *
     * @return Clave capturada.
     */
    C CapturaClave();

    /**
     * @brief Captura un valor del usuario.
     *
     * @return Valor capturado.
     */
    V CapturaValor();

    /**
     * @brief Verifica si una clave existe en la tabla hash.
     *
     * @param clave Clave a buscar.
     * @return true Si la clave existe, false en caso contrario.
     */
    bool BuscarClave(const C& clave) const;

    /**
     * @brief Elimina un elemento de la tabla hash por su clave.
     *
     * @param clave Clave del elemento a eliminar.
     */
    void Eliminar(const C& clave);

    /**
     * @brief Imprime todos los elementos de la tabla hash.
     */
    void Imprimir() const;

    /**
     * @brief Vacía la tabla hash, eliminando todos sus elementos.
     */
    void Vaciar();

    /**
     * @brief Cuenta el número de colisiones en la tabla hash.
     *
     * @return Número de colisiones.
     */
    int ContarColisiones() const;

    /**
     * @brief Muestra las colisiones de la tabla hash.
     *
     * @param tabla Referencia a otra tabla hash para comparar colisiones.
     */
    void MostrarColisiones(const TablaHashDirA<C, V>& tabla);

    /**
     * @brief Obtiene el número de elementos en la tabla hash.
     *
     * @return Número de elementos.
     */
    int ObtenerNumElementos() const;

    /**
     * @brief Verifica si la tabla hash está vacía.
     *
     * @return true Si la tabla está vacía, false en caso contrario.
     */
    bool EstaVacio();

private:
    /**
     * @brief Estructura para representar un elemento en la tabla hash.
     */
    struct Elemento {
        Elemento(const C& c, const V& val) : clave(c), valor(val) {}
        C clave;
        V valor;
    };

    int tam; /**< Tamaño de la tabla hash. */
    Elemento** tabla; /**< Puntero a un arreglo de punteros a elementos. */
    int numElementos; /**< Número de elementos en la tabla hash. */
    int (*funcionHash)(const C&); /**< Puntero a la función de hash utilizada. */

    /**
     * @brief Calcula el índice hash de una clave.
     *
     * @param clave Clave para la cual calcular el índice.
     * @return Índice hash.
     */
    int IndiceHash(const C& clave) const;

    /**
     * @brief Redimensiona la tabla hash a un nuevo tamaño.
     *
     * @param nuevoTam Nuevo tamaño de la tabla.
     */
    void Redimensionar(int nuevoTam);

    /**
     * @brief Verifica si un índice de la tabla está vacío.
     *
     * @param indice Índice a verificar.
     * @return true Si el índice está vacío, false en caso contrario.
     */
    bool IndiceVacio(int indice) const;

    /**
     * @brief Obtiene el número primo mayor que un número dado.
     *
     * @param n Número base.
     * @return Número primo mayor que n.
     */
    int ObtenerPrimoMayor(int n);
};

#include "Tabla_Hash_DirA.tpp"

#endif // TABLA_HASH_DIRA_H_INCLUDED
