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

int main()
{
    int n;

    cout<<"Cuantos datos desea guardar: ";
    cin>>n;

    struct yo D;

    for (int i=0; i<n; i++)
    {
        cout<<"Ingresa tu nombre: ";
        cin>>D.nombre;
        cout<<"Ingresa tu edad: ";
        cin>>D.edad;

        InsertarFinal(D);
    }
    cout<<"----------------------\n";

    Imprimir();

    system("pause");
    return 0;
}

// Insertar nodo al inicio de la lista
void InsertarInicio(struct yo D)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    nuevoNodo->inf = D;
    nuevoNodo->siguiente = nullptr;
    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al inicio
        nuevoNodo->siguiente = lista;
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
    }
}

void InsertarIntermedio(struct yo D, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->inf = D;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    //conexion del nuevoNodo con el resto de nodos de la lista
     nuevoNodo->siguiente = temporal->siguiente;
    //asignar el nuevoNodo a la lista
    temporal->siguiente = nuevoNodo;
}

void EliminarInicio(){
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        lista = temporal->siguiente;
        delete temporal;
    }
    else if (temporal->siguiente == nullptr)
    {
        delete lista;
        lista = nullptr;
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
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            temporal2->siguiente = nullptr;
            delete temporal;
            temporal = nullptr;
        }
    }
}

void EliminarIntermedio(int posicion)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2; 
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        posicion--;
    }
    //conexion del nuevoNodo con el resto de nodos de la lista
    temporal2->siguiente = temporal->siguiente;
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
            cout << "Lista = Nombre: " << temporal->inf.nombre << ". Edad: " << temporal->inf.edad << ".\n Direccion: " << temporal << ". Dir nodo siguiente: " << temporal->siguiente << ".\n";
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia.\n";
    }
}