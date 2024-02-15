/*Ejercicio 1: Sistema de Gestión de Productos
Implementar un sistema básico de gestión de inventario para una tienda que vende productos.
Requerimientos:
Crear una clase llamada Producto que contenga los siguientes atributos: id, nombre, precio y cantidad en stock.
Implementar métodos necesarios en la clase Producto
Implementar un método que permita calcular descuento al producto(según las especificaciones)
Además debe crear una función(que reciba el objeto) que permita calcular el precio final del producto tomando
en cuenta que si el producto supera los $100 deberá descontar el 4%, si supera los $200 deberá descontar el 8%
y si el producto supera los $500 no se le aplicará ningún descuento.  También deberá verificar la cantidad en
stock(Si es 0 debe mostrar un mensaje que diga que el producto no está disponible sino debe decirle que está
disponible)

Agregar una función que muestre la información de los objetos(esta no debe pertenecer a la clase)(Para que
funcione debe recibir el objeto)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Producto
{
private:
    int IdProducto;
    string Nombre;
    float Precio;
    int Stock;

public:
    Producto();
    Producto(int, string, float, int);

    void setIdProducto(int);
    int getIdProducto();
    void setNombre(string);
    string getNombre();
    void setPrecio(float);
    float getPrecio();
    void setStock(int);
    int getStock();

    float CalcularDescuento();
};

Producto::Producto()
{
}

Producto::Producto(int _IdProducto, string _Nombre, float _Precio, int _Stock)
{
    IdProducto = _IdProducto;
    Nombre = _Nombre;
    Precio = _Precio;
    Stock = _Stock;
}

void Producto::setIdProducto(int _IdProducto)
{
    IdProducto = _IdProducto;
}
int Producto::getIdProducto()
{
    return IdProducto;
}

void Producto::setNombre(string _Nombre)
{
    Nombre = _Nombre;
}
string Producto::getNombre()
{
    return Nombre;
}

void Producto::setPrecio(float _Precio)
{
    Precio = _Precio;
}
float Producto::getPrecio()
{
    return Precio;
}

void Producto::setStock(int _Stock)
{
    Stock = _Stock;
}
int Producto::getStock()
{
    return Stock;
}

float Producto::CalcularDescuento()
{
    if (getPrecio() > 500)
    {
        return 0.00;
    }
    else if (getPrecio() > 200)
    {
        return 0.80;
    }
    else if (getPrecio() > 100)
    {
        return 0.40;
    }
    else
    {
        return 0.00;
    }
}

struct Nodo
{
    Producto producto;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

void Insertar(Producto p);
void EliminarPorPosicion(int pos);
void EliminarInicio();
void Imprimir();
void CalcularCantidadesStock();
float AplicarDescuento(int pos);
int numeroRandom();

int main()
{
    Producto producto;
    int opcion;
    int pos;

    string Nombre;
    float Precio;
    int Stock;

    cout<<"BIENVENIDO/A\n";

    do
    {
        cout<<"\nEscoja una opcion:\n";
        cout<<"1. Insertar.\n";
        cout<<"2. Eliminar.\n";
        cout<<"3. Imprimir.\n";
        cout<<"4. Disponibilidad de stock.\n";
        cout<<"5. Descuentos.\n";
        cout<<"6. Salir.\n";
        cout<<"Su opcion es: ";
        cin>>opcion;

        switch (opcion)
        {
            case 1:
            {
                producto.setIdProducto(numeroRandom());

                cin.ignore();
                cout<<"\nIngrese el nombre del producto: ";
                getline(cin, Nombre);
                producto.setNombre(Nombre);

                cout<<"Ingrese el precio: $";
                cin>>Precio;
                while (Precio <= 0)
                {
                    cout<<"ERROR, ingrese un valor valido.\n";
                    cout<<"Ingrese el precio: $";
                    cin>>Precio;
                }
                producto.setPrecio(Precio);

                cout<<"Ingrese el stock: ";
                cin>>Stock;
                while (Stock < 0)
                {
                    cout<<"ERROR, ingrese un valor valido.\n";
                    cout<<"Ingrese el stock: ";
                    cin>>Stock;
                }
                producto.setStock(Stock);

                Insertar(producto);
            }
            break;

            case 2:
            {
                cout<<"\nEscoja la opcion que quiera eliminar:\n";
                Imprimir();
                cout<<"Su opcion es: ";
                cin>>pos;
                EliminarPorPosicion(pos);
            }
            break;

            case 3:
            {
                cout<<"\nDatos Ingresados: \n";
                Imprimir();
            }
            break;

            case 4:
            {
                cout<<"\nDisponibilidad: \n";
                CalcularCantidadesStock();
            }
            break;

            case 5:
            {
                cout<<"\nEscoja el producto para aplicar el descuento: \n";
                Imprimir();
                cout<<"Su opcion es:";
                cin>>pos;
                cout<<"Precio con descuento: $"<<AplicarDescuento(pos)<<".\n";
            }
            break;

            case 6:
            {
                cout<<"\nSaliendo...";
            }
            break;

            default:
            {
                cout<<"\nOpcion no valida, intentelo de nuevo\n";
            }
            break;
        }

    } while (opcion != 6);
    
    system("pause");
    return 0;
}

void Insertar(Producto p)
{
    struct Nodo *nuevoNodo = new Nodo();
    nuevoNodo->producto = p;
    nuevoNodo->siguiente = nullptr;

    struct Nodo *temporal = lista;
    if (temporal == nullptr)
    {
        lista = nuevoNodo;
        nuevoNodo->siguiente = nullptr;
    }
    else
    {
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }

        temporal->siguiente = nuevoNodo;
        nuevoNodo->siguiente = nullptr;
    }
}

void EliminarPorPosicion(int pos)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporalAnt;
    struct Nodo *temporalSig;
    if (temporal == nullptr)
    {
        cout << "Lista vacia.\n";
        return;
    }
    else
    {
        if (pos == 1)
        {
            EliminarInicio();
            return;
        }

        while (pos != 1)
        {
            temporalAnt = temporal;
            temporal = temporal->siguiente;
            temporalSig = temporal->siguiente;
            pos--;
        }

        temporalAnt->siguiente = temporalSig;
        delete temporal;
        temporal = nullptr;
    }
}

void EliminarInicio()
{
    struct Nodo *temporal = lista;
    if (temporal->siguiente != nullptr)
    {
        lista = temporal->siguiente;
        delete temporal;
        temporal = nullptr;
    }
    else
    {
        delete lista;
        lista = nullptr;
    }
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    int contador = 1;
    if (temporal == nullptr)
    {
        cout << "Lista vacia.\n";
    }
    else
    {
        while (temporal != nullptr)
        {
            cout << contador << ". ID: " << temporal->producto.getIdProducto() << ". Nombre: " << temporal->producto.getNombre() << ". Precio: $" << temporal->producto.getPrecio() << ". Stock: " << temporal->producto.getStock() << ".\n";
            contador++;
            temporal = temporal->siguiente;
        }
    }
}

void CalcularCantidadesStock()
{
    struct Nodo *temporal = lista;
    int contador = 1;
    if (temporal == nullptr)
    {
        cout << "Lista vacia.\n";
    }
    else
    {
        while (temporal != nullptr)
        {
            if (temporal->producto.getStock() == 0)
            {
                cout << contador << ". Nombre: " << temporal->producto.getNombre() << ". Producto no disponible.\n";
            }
            else
            {
                cout << contador << ". Nombre: " << temporal->producto.getNombre() << ". Producto disponible.\n";
            }

            contador++;
            temporal = temporal->siguiente;
        }
    }
}

float AplicarDescuento(int pos)
{
    struct Nodo *temporal = lista;
    while (pos != 1)
    {
        temporal = temporal->siguiente;
        pos--;
    }

    if (temporal->producto.CalcularDescuento() == 0.00)
    {
        return temporal->producto.getPrecio();
    }
    else
    {
        return((temporal->producto.getPrecio()) * (temporal->producto.CalcularDescuento()));
    }
}

int numeroRandom()
{
    srand(time(nullptr));
    return rand() % 90000 + 10000;
}