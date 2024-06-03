#include "Tabla_Hash_DirA.h"
#include "Menu.h"
#include "Gestiones.h"

int TipoTabla() {
    int tipoTabla = 0;

    cout << "1.- Cadena-Entero" << endl;
    cout << "2.- Entero-Entero" << endl;
    cout << "3.- Cadena-Cadena" << endl;
    cout << "4.- Entero-Cadena" << endl;
    cout << "5.- Salir" << endl;

    cout << "Seleccione el tipo de la tabla." << endl;
    do
    {
        cout << "Opci\242n: ";
        cin >> tipoTabla;

        if(tipoTabla < CAD_ENT || tipoTabla > SALIRTIPO)
            cout << "La opci\242n no existe." << endl;

    }while(tipoTabla < CAD_ENT || tipoTabla > SALIRTIPO);
    system("cls");
    return tipoTabla;
}

template <typename C, typename V>
void MenuOperaciones(TablaHashDirA<C, V> &T)
{
    int operacion = 0;

    do{
        cout << endl;
        cout << "1.- Agregar un elemento" << endl;
        cout << "2.- Eliminar un elemento de la tabla" << endl;
        cout << "3.- Buscar una clave en la tabla" << endl;
        cout << "4.- Buscar un valor mediante una clave en la tabla" << endl;
        cout << "5.- Contar Colisiones" << endl;
        cout << "6.- Obtener el n\243mero de elementos de la tablas" << endl;
        cout << "7.- Vaciar la tabla" << endl;
        cout << "8.- Cambiar de tipo de tabla"<<endl;
        cout << "9.- Salir" << endl;


        cout << "Seleccione una operacion a realizar en la tabla. " << endl << endl;

        do{
            cout << "Opci\242n: ";
            cin >> operacion;
            if(operacion < AGREGAR || operacion> SALIR)
                cout << "La opci\242n no existe." << endl;
        }while(operacion < AGREGAR || operacion > SALIR);

        C clave;

        switch (operacion)
        {
            case AGREGAR:
            {
                system("cls");
                int n;
                cout << "Teclea el n\243mero de elementos a agregar: ";
                cin >> n;

                for (int i = 0; i < n; i++)
                {
                    clave = CapturaClave<C>();
                    do
                    {
                        if (T.BuscarClave(clave))
                        {
                            cout << "La clave ya se encuentra en la tabla. Ingrese una clave diferente." << endl;
                            clave = CapturaClave<C>();
                        }
                    }while(T.BuscarClave(clave));
                    V valor = CapturaValor<V>();
                    T.Agregar(clave, valor);
                    cout << "Elemento agregado correctamente." << endl;
                }

                break;
            }
            case ELIMINAR:
            {
                system("cls");
                cout << "Ingrese la clave: ";
                clave = CapturaClave<C>();

                if (T.BuscarClave(clave))
                {
                    T.Eliminar(clave);
                    cout << "Elemento eliminado correctamente." << endl;
                }
                else
                {
                    cout << "La clave no se encuentra en la tabla." << endl;
                }
                system("cls");
                break;
            }
            case BUSCAR:
            {
                C clave;
                cout << "Ingrese la clave: ";
                cin >> clave;

                if (T.BuscarClave(clave))
                {
                    cout << "La clave " << clave <<" si se encuentra en la tabla" << endl;
                }
                else
                {
                    cout << "La clave " << clave <<" no se encuentra en la tabla" << endl;
                }
                break;

            }
            case BUSCAR_VALOR:
            {
                system("cls");
                cout << "Ingrese la clave: ";
                cin >> clave;

                V valorEncontrado = T.Buscar(clave);

                if (valorEncontrado != V())
                {
                    cout << "Valor encontrado perteneciente a esa clave: " << valorEncontrado << endl;
                }
                else
                {
                    cout << "La clave no se encuentra en la tabla." << endl;
                }

                break;
            }
            case COLISIONES:
            {
                system("cls");
               cout << "El n\243mero de colisiones es: " << T.ContarColisiones();
               T.MostrarColisiones(T);
               break;
            }
            case NUMELEMENTOS:
            {
                system("cls");
               cout << "El n\243mero de elementos es: " << T.ObtenerNumElementos();
                //system("cls");
               break;
            }
            case VACIAR:
            {
                system("cls");
               T.Vaciar();
               cout << "Ahora la tabla se encuentra vac\241a" << endl;

               break;
            }
            case SEL_TABLA:
            {
                MenuTipo();
                break;
            }
            case SALIR:
            {
                exit(0);
            }
        }
        cout << endl;
        T.Imprimir();

    }while(operacion != SALIR);
}

void MenuTipo()
{
    system("cls");

	cout << "Equipo: Migos. \n\n";
    cout << "Integrantes: \n";
    cout << "Ricardo Emanuel Ortega Caudillo \n";
    cout << "Brayan Alexis Perez Cordova \n";
    cout << "Pablo Andres González Arguelles \n";
    cout << "Jorge Alberto Luna Munguia\n\n";

    int tipo = TipoTabla();

    switch(tipo)
    {
        case CAD_ENT:
        {
            cout << "Tabla Hash de tipo Cadena-Entero:" << endl;
            TablaHashDirA<string, int> tabla(5, IndiceCad);
            MenuOperaciones(tabla);

            break;
        }
        case ENT_ENT:
        {
            cout << "Tabla Hash de tipo Entero-Entero:" << endl;
            TablaHashDirA<int, int> tabla(5, IndiceEnt);
            MenuOperaciones(tabla);

            break;
        }
        case CAD_CAD:
        {
            cout << "Tabla Hash de tipo Cadena_Cadena:" << endl;
            TablaHashDirA<string, string> tabla(5, IndiceCad);
            MenuOperaciones(tabla);

            break;
        }
        case ENT_CAD:
        {
            cout << "Tabla Hash de tipo Entero-Cadena:" << endl;
            TablaHashDirA<int, string> tabla(5, IndiceEnt);
            MenuOperaciones(tabla);

            break;
        }
        case SALIRTIPO:
        {
            exit(0);
        }
    }
}

