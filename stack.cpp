#include <iostream>
#include <stack>

using namespace std;

struct Persona
{
    string nombre;
    int edad;
};


int main()
{
    struct Persona p;
    stack <Persona> pila; //declaracion de pila

    cout<<"Ingresa tu nombre: ";
    cin>>p.nombre;
    cout<<"Ingresa tu edad: ";
    cin>>p.edad;

    pila.push(p);

    return 0;
}