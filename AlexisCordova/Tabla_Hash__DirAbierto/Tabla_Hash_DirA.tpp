//********************//Construcor//****************************************************************************************************************************************
template<typename K, typename V>
TablaHashDirA<K, V>::TablaHashDirA(int tam, int (*funcHash)(const K&)) : tamanio(tam), tabla(new Elemento*[tamanio]), numElementos(0), funcionHash(funcHash)
{
    for(int i = 0; i < tamanio; ++i)
        Tabla[i] = nullptr;
}
//*********************//Destructor//***************************************************************************************************************************************
template<typename K, typename V>
TablaHashDirA<K, V>::~TablaHashDirA()
{
    Vaciar();
    delete[] tabla; // Libera Memoria Para el Arreglo de Punteros a Elementos
}
//**********************//Constructor de Copias//**************************************************************************************************************************************
template<typename K, typename V>
TablaHashDirA<K, V>::TablaHashDirA(const TablaHashDirA& otro) : tamanio(otro.tamanio), tabla(new Elemento*[tamnio]), numElemento(otro.Elemento), funcionHash(otro.funcionHash)
{
    for(int i = 0; i < tamanio; ++i){
        if(otro.tabla[i] != nullptr)
            tabla[i] = new Elemento(otro.tabla[i]->clave, otro.tabla[i]->valor);
        else
            tabla[i] = nullptr;
    }
}
//**********************//Operador de Asignacion//**************************************************************************************************************************************
template<typename K, typename V>
TablaHashDirA<K, V>& TablaHashDirA<K, V>:operator=(const TablaHash& otro)
{
    if(this != &otro)
    {
        Vaciar();
        delete[] tabla; // Libera memoria dinamica para el arreglo de punteros a Elemento

        tamanio = otro.tamanio; // Asigna el tamaño de la tabla del objeto otro
        tabla = new Elemento*[tamanio]; // Crea un nuevo arreglo de punteros con el tamaño de la tabla de otro
        numElementos = otro.numElementos; // Asigna el numero de Elementos

        for(int i = 0; i < tamanio; ++i){
            if(otro.tabla[i] != nullptr)
                tabla[i] = new Elemento(otro.tabla[i]->clave, otro.tabla[i]->valor);
            else
                tabla[i] = nullptr;
        }
    }
    return *this; // Devuelve una referencia
}
//**********************//Funcion Hash//**************************************************************************************************************************************
template<typename K, typename V>
int TablaHashDirA<K, V>::IndiceHash(const K& clave) const
{
    return funcionHash(clave) % tamanio; // Se Aplica la Funcion Hash a la Clave y se calcula el Indice Dentro del Rango [0,tamanio-1]
}
//***********************//Redimensionar//*************************************************************************************************************************************
template<typename K, typename V>
void TablaHashDirA<K, V>::Redimensionar(int nuevoTam)
{
    // Crea un Nueva Instancia Para la Memoria
    Elemento** nuevaTabla = new Elemento*[nuevoTam];
    for(int i = 0; i < nuevotam; ++i){
        // Asigna nullptr a todos los elementos de la nueva tabla
        nuevaTabla[i] = nullptr;
    }

    int anteriorTamanio = tamanio; // Guarda el anterior tamaño antes de cambiarlo
    tamanio = nuevoTam; // Actualiza el tamaño de la tabla

    for(int i = 0; i < anteriorTam; ++i){
        if(tabla[i] != nullptr)
        {
            int nuevoIndice = indiceHash(tabla[i]->clave); // Se calcula un nuevo indice para el elemento actual
            int iteraciones = 1;
            while(nuevaTabla[nuevoIndice] != nullptr)
            {
                nuevoIndice = (nuevoIndice + iteraciones) % nuevoTam; // Sondeo Lineal
                iteraciones++;
            }
            nuevaTabla[nuevoIndice] = tabla[i]; // Elemento actual a la nueva tabla al nuevo indice
        }
    }
    delete[] tabla;
    tabla = nuevaTabla;
}
//************************************************************************************************************************************************************
template<typename K, typename V>

//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
template<typename K, typename V>
//************************************************************************************************************************************************************
//************************************************************************************************************************************************************
//************************************************************************************************************************************************************
//************************************************************************************************************************************************************
