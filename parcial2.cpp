#include <iostream>

using namespace std;

//declarando estructuras
struct missUniverso
{
    string nombre;
    string pais;
    float altura;
    int edad;
    float peso;
};

//al ser una lista simpre, solo se necesita el Nodo *siguiente
struct Nodo
{
    missUniverso universo;
    struct Nodo *siguiente;
};

//inicializacion de lista
struct Nodo *lista = nullptr;

//declaracion de funciones
void InsertarInicio(struct missUniverso mU);
void Imprimir();
void ImprimirEdad();
void EliminarPorPosicion(int pos);

int main()
{
    missUniverso mU;
    int opcion = 0, pos = 0, n = 0;

    cout<<"-------- BIENVENIDO/A ---------\n";
    cout<<"-------------------------------\n";

    do
    {
        cout<<"\n-------------------------------\n";
        cout<<"Elija una opcion.\n";
        cout<<"1. Insertar al Inicio.\n";
        cout<<"2. Imprimir.\n";
        cout<<"3. Imprimir por edad.\n";
        cout<<"4. Eliminar por posicion.\n";
        cout<<"5. Salir.\n";
        cout<<"Su opcion es: ";
        cin>>opcion;

        switch (opcion)
        {
            case 1:
            {
                cout<<"Ingrese el numero de concursantes: ";
                cin>>n;

                for (int i = 0; i < n; i++)
                {
                    cout<<"\nConcursante "<<(i+1)<<".\n";
                    cout<<"Nombre: ";
                    cin>>mU.nombre;
                    cout<<"Pais: ";
                    cin>>mU.pais;
                    cout<<"Altura(m): ";
                    cin>>mU.altura;
                    cout<<"Edad: ";
                    cin>>mU.edad;
                    cout<<"Peso: ";
                    cin>>mU.peso;

                    InsertarInicio(mU);
                }
            }
            break;
        
            case 2:
            {
                cout<<"\n";
                Imprimir();
            }
            break;

            case 3:
            {
                cout<<"\n";
                ImprimirEdad();
            }
            break;

            case 4:
            {
                cout<<"\n";
                Imprimir();
                cout<<"\nIngrese la posicion a eliminar: ";
                cin>>pos;
                EliminarPorPosicion(pos);
            }
            break;

            case 5:
            {
                cout<<"\nSaliendo... ";
            }
            break;

            default:
            {
                cout<<"\nOpcion no valida.\n";
            }
            break;
        }
    } while (opcion != 5);
    
    system("pause");
    return 0;
}

void InsertarInicio(struct missUniverso mU)
{
    //reservando memoria para nuevo nodo
    struct Nodo *nuevoNodo = new Nodo();

    //guardando valores del nuevo nodo
    nuevoNodo->universo = mU;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        //si la lista esta vacia, el nuevo nodo sera el unico valor en ella
        lista = nuevoNodo;
    }
    else
    {
        //sino, el nuevo nodo se mueve al frente de la lista
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    int contador = 1;

    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout<<contador<<". Nombre: "<<temporal->universo.nombre<<". Pais: "<<temporal->universo.pais<<". Altura(m): "<<temporal->universo.altura<<". Edad: "<<temporal->universo.edad<<" anios. Peso(lb): "<<temporal->universo.peso<<".\n";
            contador ++;
            //recorre por toda la lista
            temporal = temporal->siguiente;
        }   
    }
    else
    {
        cout<<"Lista vacia.\n";
    }
}

void ImprimirEdad()
{
    struct Nodo *temporal = lista;
    int contador = 1;

    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout<<contador<<". Nombre: "<<temporal->universo.nombre<<". Edad: "<<temporal->universo.edad<<".\n";
            contador ++;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout<<"Lista vacia.\n";
    }
}

void EliminarPorPosicion(int pos)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            while (pos != 1)
            {
                //se busca la posicion y el que esta antes de esa posicion
                temporal2 = temporal;
                temporal = temporal->siguiente;
                pos--;
            }
            //el que esta antes de la posicion a borrar, apuntara al valor que va despues de la posicion a borrar
            temporal2->siguiente = temporal->siguiente;
            //se elimina
            delete temporal;
            temporal = nullptr;
        }
        else
        {
            //si solo hay un valor en la lista se borra la lista
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        cout<<"Lista vacia.\n";
    }
}