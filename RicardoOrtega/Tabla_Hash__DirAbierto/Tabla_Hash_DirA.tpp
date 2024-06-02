//********************//Construcor//****************************************************************************************************************************************
template<typename C, typename V>
TablaHashDirA<C, V>::TablaHashDirA(int tamH, int (*funcHash)(const C&)) : tam(tamH), tabla(new Elemento*[tam]), numElementos(0), funcionHash(funcHash)
{
    for(int i = 0; i < tam; ++i)
        Tabla[i] = nullptr;
}
//*********************//Destructor//***************************************************************************************************************************************
template<typename C, typename V>
TablaHashDirA<C, V>::~TablaHashDirA()
{
    Vaciar();
    delete[] tabla;
}
//**********************//Constructor de Copias//**************************************************************************************************************************************
template<typename C, typename V>
TablaHashDirA<C, V>::TablaHashDirA(const TablaHashDirA& otro) : tam(otro.tam), tabla(new Elemento*[tam]), numElemento(otro.Elemento), funcionHash(otro.funcionHash)
{
    for(int i = 0; i < tam; ++i){
        if(otro.tabla[i] != nullptr)
            tabla[i] = new Elemento(otro.tabla[i]->clave, otro.tabla[i]->valor);
        else
            tabla[i] = nullptr;
    }
}
//**********************//Operador de Asignacion//**************************************************************************************************************************************
template<typename C, typename V>
TablaHashDirA<C, V>& TablaHashDirA<C, V>:operator=(const TablaHash& otro)
{
    if(this != &otro)
    {
        Vaciar();
        delete[] tabla; // Libera memoria dinamica para el arreglo de punteros a Elemento

        tam = otro.tam; // Asigna el tamaño de la tabla del objeto otro
        tabla = new Elemento*[tam]; // Crea un nuevo arreglo de punteros con el tamaño de la tabla de otro
        numElementos = otro.numElementos; // Asigna el numero de Elementos

        for(int i = 0; i < tam; ++i){
            if(otro.tabla[i] != nullptr)
                tabla[i] = new Elemento(otro.tabla[i]->clave, otro.tabla[i]->valor);
            else
                tabla[i] = nullptr;
        }
    }
    return *this; // Devuelve una referencia
}
//**********************//Funcion Hash//**************************************************************************************************************************************
template<typename C, typename V>
int TablaHashDirA<C, V>::IndiceHash(const C& clave) const
{
    return funcionHash(clave) % tam;
}
//***********************//Redimensionar//*************************************************************************************************************************************
template<typename C, typename V>
void TablaHashDirA<C, V>::Redimensionar(int nuevoTam)
{
    // Crea un Nueva Instancia Para la Memoria
    Elemento** nuevaTabla = new Elemento*[nuevoTam];
    for(int i = 0; i < nuevotam; ++i){
        // Asigna nullptr a todos los elementos de la nueva tabla
        nuevaTabla[i] = nullptr;
    }

    int anteriorTam = tam; // Guarda el anterior tamaño antes de cambiarlo
    tam = nuevoTam; // Actualiza el tamaño de la tabla

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
//Regresa true si el indice tiene un valor asignado en la tabla
template<typename C, typename V>
bool TablaHashDirA<C, V>::IndiceVacio(int indice) const{
    return (tabla[indice] == nullptr);
}
//************************************************************************************************************************************************************
//Crea una entrada en la table con el valor aplicando la funcion hash a la clave
template<typename C, typename V>
void TablaHashDirA<C, V>::Agregar(const C& clave, const V& valor) {
    if(ObtenerNumElementos() >= (round(tam) * 0.80)) {
        int nuevoTam = ObtenerPrimoMayor(tam * 2);
        Redimensionar(nuevoTam);
    }
    int indice = IndiceHash(clave);  //Indice utilizando la funcion hash
    int conteo = 1;

    //Verifica si el indice esta vacio
    while(!IndiceVacio(indice)) {
        if (tabla[indice]->clave == clave) {
            tabla[indice]->valor = valor;
            return;
        }
        indice = (indice + conteo) % tam;  //sondeo lineal
        conteo++;
    }
    tabla[indice] = new Elementos(clave, valor);
    numElementos++;
}
//************************************************************************************************************************************************************
//Regresa un valor de la tabla dada su clave
template<typename C, typename V>
V TablaHashDirA<C, V>::Buscar(const C& clave) const{
    int indice = IndiceHash(clave);
    int conteo = 1;
    while(!IndiceVacio(indice)) {
        if(tabla[indice]->clave == clave) return tabla[indice]->valor;
        indice = (indice + conteo) % tam;// Aplica sondeo lineal si hay colisión
        conteo++;
    }
    indice = (indice + conteo) % tam;// Aplica sondeo lineal si hay colisión
    
    cout << "No se encontro el valor con la clave " << clave << "." << endl;
    return 0; //Valor predeterminado si no se encuentra la clave
}
//************************************************************************************************************************************************************
//Regresa true sin existe la clave en la tabla hash
template<typename C, typename V>
bool TablaHashDirA<C, V>::BuscarClave(const C& clave) const{
    int indice = IndiceHash(clave);
    int conteo = 1;
    
    while (!IndiceVacio(indice)) {
        if (tabla[indice]->clave == clave) return true;

        indice = (indice + conteo) % tam;
        conteo++;
    }

    return false;
}
//************************************************************************************************************************************************************
//Elimina una entrada de la tabla dada su clave
template<typename C, typename V>
void TablaHashDirA<C, V>::Eliminar(const C& clave) {
    int indice = IndiceHash(clave);
    int intentos = 1;

    while(!IndiceVacio(indice)) {
        if(tabla[indice]->clave == clave) {
            delete tabla[indice];
            tabla[indice] = nullptr;
            numElementos--;

            // Reorganizar los elementos restantes en la tabla
            int siguienteIndice = (indice + intentos) % tam;
            while (!IndiceVacio(siguienteIndice)) {
                Elementos* elementoActual = tabla[siguienteIndice];
                tabla[siguienteIndice] = nullptr;
                numElementos--;

                Agregar(elementoActual->clave, elementoActual->valor);

                delete elementoActual;

                intentos++;
                siguienteIndice = (indice + intentos) % tam; //Aplica sondeo lineal si hay colision
            }
            return;
        }
        indice = (indice + intentos) % tam;
        intentos++;
    }
}
//************************************************************************************************************************************************************
template<typename C, typename V>
void TablaHashDirA<C, V>::Imprimir() const
{
    cout << "Tabla Hash:" << endl;
    cout << "+-------------+-----------+--------+" << endl;
    cout << "| Posici\242n |   Clave   |   Valor    |" << endl;
    cout << "+-------------+-----------+--------+" << endl;

    for (int i = 0; i < tam; ++i)
    {
        if (tabla[i] != nullptr)
        {
            cout << "| " << setw(9) << i << " | " << setw(9) <<tabla[i]->clave << " | " << setw(9) << tabla[i]->valor << " |" << endl;
        }
        else
        {
            cout << "|" << setw(9) << i << "  |    Vac\241a  |   Vac\241o   |" << endl;
        }
    }

    cout << "+-------------+-----------+--------+" << endl;
}
//************************************************************************************************************************************************************
template<typename C, typename V>
void TablaHashDirA<C, V>::Vaciar() {
    for(int i = 0; i < tam; ++i) {
        if(tabla[i] != nullptr) {
            delete tabla[i];
            tabla[i] = nullptr;
        }
    }
    numElementos = 0;
}
//************************************************************************************************************************************************************
template<typename C, typename V>
int TablaHashDirA<C, V>::ContarColisiones() const
{
    int colisiones = 0;
    for(int i = 0; i < tam; ++i)
    {
        if(tabla[i] != nullptr && !IndiceVacio((i + 1) % tam))
        {
            colisiones++;
        }

    }
    return colisiones;
}
//************************************************************************************************************************************************************
template<typename C, typename V>
int TablaHashDirA<C, V>::ObtenerNumElementos() const
{
    return numElementos;
}
//************************************************************************************************************************************************************
template<typename C, typename V>
bool TablaHashDirA<C, V>::EstaVacio()
{
    for (int i = 0; i < tam; ++i)
    {
        if (tabla[i] != nullptr)
        {
            return false; // Si se encuentra al menos un elemento no nulo, el arreglo no está vacío
        }
    }
    return true; // Si no se encuentra ningún elemento, el arreglo está vacío
}
//************************************************************************************************************************************************************
template<typename C, typename V>
void TablaHashDirA<C, V>::MostrarColisiones(const TablaHashDirA<C, V>& tabla)
{
    for(int i = 0; i < tabla.tam; ++i)
    {
        // Verifica si hay un elemento en el indice actual y si el siguiente índice esta lleno
        if(tabla.tabla[i] != nullptr && !tabla.IndiceVacio((i + 1) % tabla.tam))
        {
            cout << "Colisi\240n en el \241ndice " << i << ":" << endl;
            cout << "Elemento 1: Clave = " << tabla.tabla[i]->clave << ", Valor = " << tabla.tabla[i]->valor << endl;

            int siguienteIndice = (i + 1) % tabla.tam;
            while(!tabla.IndiceVacio(siguienteIndice))
            {
                // Recorre los índices siguientes hasta encontrar un indice vacio
                cout << "Elemento 2: Clave = " << tabla.tabla[siguienteIndice]->clave << ", Valor = " << tabla.tabla[siguienteIndice]->valor << endl;
                siguienteIndice = (siguienteIndice + 1) % tabla.tam;
            }
            cout << "-----------------------" << endl;
        }
    }
}
//************************************************************************************************************************************************************
template<typename C>
C CapturaClave()
{
    C clave;
    cout << "Ingrese la clave: ";
    cin >> clave;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return clave;
}
//************************************************************************************************************************************************************
template<typename V>
V CapturaValor()
{
    V valor;
    cout << "Ingrese el valor: ";
    cin >> valor;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do{
        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error: Tipo de valor incorrecto." << endl;
            cout << "Ingrese el valor: ";
            cin >> valor;
        }
    }while(cin.fail());


    return valor;
}
//************************************************************************************************************************************************************
template<typename C, typename V>
int TablaHashDirA<C, V>::ObtenerPrimoMayor(int n)
{
    if (n <= 1) return 2;

    bool esPrimo = false;
    int primoMayor = n;
    while(!esPrimo)
    {
        primoMayor++;
        esPrimo = true;
        for(int i = 2; i <= sqrt(primoMayor); ++i)
        {
            if(primoMayor % i == 0)
            {
                esPrimo = false;
                break;
            }
        }
    }
    return primoMayor;
}