#include <iostream>

using namespace std;

int main()
{
    int opcion=8;
    do{
        system("cls");
        cout << "Tabla hash " << endl;
        cout << "0) Agregar un dato " << endl;
        cout << "1) Eliminar un dato " << endl;
        cout << "2) Vaciar " << endl;
        cout << "3) Salir" << endl;
        cout << "Elija una opcion: " << endl;
        cin >> opcion;


        switch(opcion)
        {
        case 0:
            cout << "Ingrese el dato que desea agregar:"<<endl;
            
            
            break;
        case 1:
            cout << "" << endl;

            break;
        case 2:

            break;
        case 3:

            break;

        }

    system ("pause");

    }while(opcion != 3);

    return 0;
}
