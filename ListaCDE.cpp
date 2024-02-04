#include <iostream>

using namespace std;

struct PremierLeague
{
    string club;
    int puntos;
};

struct Nodo
{
    PremierLeague premier;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

void InsertarInicio(struct PremierLeague pl);
void InsertarFinal(struct PremierLeague pl);
void InsertarIntermedio(struct PremierLeague pl, int pos);
void EliminarInico();
void EliminarFinal();
void EliminarIntermedio(int pos);
void Imprimir();

int main()
{
    PremierLeague pl;
    int opcion = 0, n = 0, pos = 0, n_datos = 0;

    cout<<"-------------------------------\n";
    cout<<"---------BIENVENIDO/A----------\n";
    cout<<"-------------------------------\n";

    do
    {
        cout<<"\n-------------------------------\n";
        cout<<"Elija una opcion.\n";
        cout<<"1. Insertar al inicio.\n";
        cout<<"2. Insertar al final.\n";
        cout<<"3. Insertar al Intermedio.\n";
        cout<<"4. Eliminar al inicio.\n";
        cout<<"5. Eliminar al final.\n";
        cout<<"6. Eliminar al Intermedio.\n";
        cout<<"7. Imprimir.\n";
        cout<<"8. Salir.\n";
        cout<<"Su opcion es: ";
        cin>>opcion;
        cout<<"-------------------------------\n\n";

        switch (opcion)
        {
            case 1:
            {
                cout<<"Cantidad a ingresar: ";
                cin>>n;
                while (n <= 0)
                {
                    cout<<"ERROR, intentelo de nuevo.\n";
                    cout<<"Cantidad a ingresar: ";
                    cin>>n;
                }

                for (int i = 0; i < n; i++)
                {
                    cout<<"\n Dato #"<<(i+1)<<".\n";
                    cout<<"Club: ";
                    getline(cin, pl.club);
                    cout<<"Puntos: ";
                    cin>>pl.puntos;

                    InsertarInicio(pl);
                    n_datos++;
                }
                cout<<"\n";          
            }
            break;

            case 2:
            {
                cout<<"Cantidad a ingresar: ";
                cin>>n;
                while (n <= 0)
                {
                    cout<<"ERROR, intentelo de nuevo.\n";
                    cout<<"Cantidad a ingresar: ";
                    cin>>n;
                }

                for (int i = 0; i < n; i++)
                {
                    cout<<"\n Dato #"<<(i+1)<<".\n";
                    cout<<"Club: ";
                    getline(cin, pl.club);
                    cout<<"Puntos: ";
                    cin>>pl.puntos;

                    InsertarFinal(pl);
                    n_datos++;
                }
                cout<<"\n";
            }
            break;

            case 3:
            {
                Imprimir();
                cout<<"Ingrese la posicion a insertar: ";
                cin>>pos;

                n_datos++;
                while (pos < n_datos || pos != n_datos)
                {
                    cout<<"ERROR, intentelo de nuevo.\n";
                    cout<<"Posicion a insertar: ";
                    cin>>pos;
                }

                cout<<"Club: ";
                getline(cin, pl.club);
                cout<<"Puntos: ";
                cin>>pl.puntos;

                InsertarIntermedio(pl, pos);
                
                cout<<"\n";
            }
            break;

            case 4:
            {
                EliminarInico();
                if (n_datos >= 1)
                {
                    n_datos--;
                    cout<<"Dato eliminado.\n";
                }
            }
            break;

            case 5:
            {
                EliminarFinal();
                if (n_datos >= 1)
                {
                    n_datos--;
                    cout<<"Dato eliminado.\n";
                }
            }
            break;

            case 6:
            {
                if (n_datos <= 0)
                {
                    cout<<"Lista vacia.\n";
                    break;
                }
                
                Imprimir();
                cout<<"Ingrese la posicion a eliminar: ";
                cin>>pos;

                while (pos < n_datos || pos != n_datos)
                {
                    cout<<"ERROR, intentelo de nuevo.\n";
                    cout<<"Posicion a insertar: ";
                    cin>>pos;
                }

                EliminarIntermedio(pos);
                n_datos--;
                cout<<"Dato eliminado.\n";
            }
            break;

            case 7:
            {
                Imprimir();
            }
            break;

            case 8:
            {
                cout<<"Saliendo... ";
            }
            break;

            default:
            {
                cout<<"ERROR, opcion no valida.\n";
            }
            break;
        }
    } while (opcion != 8);

    system("pause");
    return 0;
}

void InsertarInicio(struct PremierLeague pl)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal;

    nuevoNodo->premier = pl;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = nuevoNodo;
        lista->anterior = nuevoNodo;
        temporal = lista;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        lista = nuevoNodo;
        temporal->siguiente = lista;
        lista->anterior = temporal;
    }
}

void InsertarFinal(struct PremierLeague pl)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal;

    nuevoNodo->premier = pl;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = nuevoNodo;
        lista->anterior = nuevoNodo;
        temporal = lista;
    }
    else
    {
        temporal->siguiente = nuevoNodo;
        nuevoNodo->anterior = temporal;
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        temporal = nuevoNodo;
    }
}

void InsertarIntermedio(struct PremierLeague pl, int pos)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = nuevoNodo;
        lista->anterior = nuevoNodo;
    }
    else
    {
        while (pos != 1)
        {
            temporal2 = temporal;
            temporal = temporal->siguiente;
            pos--;
        }
        nuevoNodo->siguiente = temporal;
        nuevoNodo->anterior = temporal2;
        temporal2->siguiente = nuevoNodo;
        temporal->anterior = nuevoNodo;
    }
}

void EliminarInico()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        if (temporal->siguiente != lista)
        {
            while (temporal->siguiente != lista)
            {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = lista->siguiente;
            delete lista;
            lista = temporal->siguiente;
            lista->anterior = temporal;
        }
        else
        {
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        cout<<"Lista vacia.\n";
    }
}

void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        if(temporal->siguiente != lista)
        {
            while (temporal->siguiente != lista)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            temporal2->siguiente = lista;
            lista->anterior = temporal2;
            delete temporal;
        }
        else
        {
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        cout<<"Lista vacia.\n";
    } 
}

void EliminarIntermedio(int pos)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;

    if (temporal->siguiente != lista)
    {
        while (pos != 1)
        {
            temporal2 = temporal;
            temporal = temporal->siguiente;
            temporal3 = temporal->siguiente;
            pos--;
        }
        temporal2->siguiente = temporal3;
        temporal3->anterior = temporal2;
        delete temporal;
    }
    else
    {
        delete lista;
        lista = nullptr;
    }
}

void Imprimir()
{
    int contador = 1;
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        do
        {
            cout<<contador<<". Club: "<<temporal->premier.club<<". Puntos: "<<temporal->premier.puntos<<".\n"<<"Direccion anterior: "<<temporal->anterior<<" Direccion siguiente: "<<temporal->siguiente<<"\n\n";
            temporal = temporal->siguiente;
            contador ++;
        } 
        while (temporal != lista);
    }
    else
    {
        cout<<"Lista vacia.\n";
    }
}