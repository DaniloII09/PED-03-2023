#include <iostream>

using namespace std;

struct yo
{
    int edad;
    string nombre;
};

struct Nodo
{
    struct yo inf;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

struct Nodo *lista = nullptr;

// Declaración de funciones
void InsertarInicio(struct yo D);
void InsertarFinal(struct yo D);
void InsertarIntermedio(struct yo D, int);
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int);
void Imprimir();

void EliminarIntermedio2 (int);

int main()
{
    struct yo D;
    int opcion=0, opcion_insertar=0, opcion_eliminar=0, pos=0;

    cout<<"\n-------BIENVENIDO/A---------\n";

    do
    {
        cout<<"\nEscoja una opcion del siguiente menu:\n    1. Insertar.\n    2. Eliminar.\n    3. Imprimir.\n    4. Salir.\nSu opcion es: ";
        cin>>opcion;

        switch (opcion)
        {
            case 1:
                
                cout<<"\nEscoja una opcion del siguiente menu:\n    1. Insertar Inicio.\n    2. Insertar Final.\n    3. Insertar Intermedio.\n    4. Regresar.\nSu opcion es: ";
                cin>>opcion_insertar;
                
                switch (opcion_insertar)
                {
                    case 1:
                    cout<<"Ingresar nombre: ";
                    cin>>D.nombre;
                    cout<<"Ingresar edad: ";
                    cin>>D.edad;
                    InsertarInicio(D);
                    break;
            
                    case 2:
                    cout<<"Ingresar nombre: ";
                    cin>>D.nombre;
                    cout<<"Ingresar edad: ";
                    cin>>D.edad;
                    InsertarFinal(D);
                    break;

                    case 3:
                    cout<<"Ingrese la posicion: ";
                    cin>>pos;
                    cout<<"Ingresar nombre: ";
                    cin>>D.nombre;
                    cout<<"Ingresar edad: ";
                    cin>>D.edad;
                    InsertarIntermedio(D, pos);
                    break;

                    case 4:
                    break;

                    default:
                    cout<<"Opcion no valida.\n";
                    break;
                }
            break;
        
            case 2:
                
                cout<<"\nEscoja una opcion del siguiente menu:\n    1. Eliminar Inicio.\n    2. Eliminar Final.\n    3. Eliminar Intermedio.\n    4. Regresar.\nSu opcion es: ";
                cin>>opcion_eliminar;

                switch (opcion_eliminar)
                {
                    case 1:
                    EliminarInicio();
                    break;
            
                    case 2:
                    EliminarFinal();
                    break;

                    case 3:
                    cout<<"Ingrese la posicion: ";
                    cin>>pos;
                    EliminarIntermedio(pos);

                    case 4:
                    break;

                    default:
                    cout<<"Opcion no valida.\n";
                    break;
                }
            break;

            case 3:
                Imprimir();
            break;

            case 4:
            break;
        
            default:
                cout<<"ERROR, intentelo de nuevo.\n";
            break;
        }
    } 
    while (opcion!=4);

}

// Insertar nodo al inicio de la lista
void InsertarInicio(struct yo D)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    
    nuevoNodo->inf = D;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    
    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al inicio
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        lista = nuevoNodo;
    }
}

// Insertar nodo al final de la lista
void InsertarFinal(struct yo D)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->inf = D;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al final
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
        nuevoNodo->anterior = temporal;
    }
}

void InsertarIntermedio(struct yo D, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    nuevoNodo->inf = D;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    //conexion del nuevoNodo con el resto de nodos de la lista
    temporal2 = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
    temporal2->anterior = nuevoNodo;
    nuevoNodo->siguiente = temporal2;
    nuevoNodo->anterior = temporal;
}

void EliminarInicio()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        if(temporal->siguiente != nullptr)
        {
            lista = lista->siguiente;
            delete temporal;
            temporal = nullptr;
            lista->anterior = nullptr;
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
        if (temporal->siguiente != nullptr)
        {
            while (temporal->siguiente != nullptr)
            {
                temporal = temporal->siguiente;
            }

            temporal2 = temporal->anterior;
            temporal2->siguiente = nullptr;
            delete temporal;
            temporal = nullptr;
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

void EliminarIntermedio(int posicion)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;

    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        temporal3 = temporal->siguiente;
        posicion--;
    }
    //conexion del nuevoNodo con el resto de nodos de la lista
    temporal2->siguiente = temporal3;
    temporal3->anterior = temporal2;
    delete temporal;
    temporal = nullptr;
   
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout << "Lista = Nombre: " << temporal->inf.nombre << ". Edad: " << temporal->inf.edad << ".\n Direccion: " << temporal << ".\n Dir nodo siguiente: " << temporal->siguiente << ". Dir nodo anterior: " << temporal->anterior << ".\n\n";
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia.\n";
    }
}

void EliminarIntermedio2 (int pos)
{
    struct Nodo *temporal = lista;
    int i = 1;
    while (temporal != nullptr && i < pos)
    {
        temporal = temporal->siguiente;
        i++;
    }

    if (temporal !=nullptr)
    {
        temporal->anterior->siguiente = temporal->siguiente;
        temporal->siguiente->anterior = temporal->anterior;
        delete temporal;
    }
    else
    {
        cout<<"Lista vacia.\n";
    }
}