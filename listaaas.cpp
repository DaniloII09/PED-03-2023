#include <iostream>

using namespace std;

struct Base
{
    int numero;
    char letra;
};

struct Nodo
{
    Base base;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

void InsertarInicio(struct Base b);
void InsertarFinal(struct Base b);
void InsertarIntermedio(struct Base b, int pos);
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int pos);
void EliminarIntermedio2(int pos);
void Imprimir();

int main()
{
    system("pause");
    return 0;
}

void InsertarInicio(struct Base b)
{
    struct Nodo *nuevoNodo = new Nodo();
    nuevoNodo->base = b;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        lista = nuevoNodo;
    }
}

void InsertarFinal(struct Base b)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->base = b;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
        nuevoNodo->anterior = temporal;
    }
}

void InsertarIntermedio(struct Base b, int pos)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    nuevoNodo->base = b;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        while (pos != 1)
        {
            temporal2 = temporal;
            temporal = temporal->siguiente;
            pos--;
        }
        temporal2->siguiente = nuevoNodo;
        nuevoNodo->siguiente = temporal;
        temporal->anterior = nuevoNodo;
        nuevoNodo->anterior = temporal2;
    }
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
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
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

void EliminarIntermedio(int pos)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;

    if (lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            while (pos != 1)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
                temporal3 = temporal->siguiente;
                pos--;
            }
            temporal2->siguiente=temporal3;
            temporal3->anterior=temporal2;

            delete temporal;
            temporal=nullptr;
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

void EliminarIntermedio2(int pos)
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            while (pos != 1)
            {
                temporal = temporal->siguiente;
                pos--;
            }
            temporal->anterior->siguiente=temporal->siguiente;
            temporal->siguiente->anterior=temporal->anterior;

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

void Imprimir()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout<<"Numero: "<<temporal->base.numero<<".\n";
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout<<"Lista vacia.\n";
    }
}