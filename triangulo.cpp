#include <iostream>
#include <math.h>

using namespace std;

class Triangulo
{
private:
    string Color;
    float MedidaLado1;
    float MedidaLado2;
    float MedidaLado3;
    string TipoTriangulo;
public:
    Triangulo();
    Triangulo(string _Color, float _MedidaLado1, float _MedidaLado2, float _MedidaLado3, string _TipoTriangulo);

    void setColor(string);
    string getColor();
    void setMedidaLado1(float);
    float getMedidaLado1();
    void setMedidaLado2(float);
    float getMedidaLado2();
    void setMedidaLado3(float);
    float getMedidaLado3();
    void setTipoTriangulo(string);
    string getTipoTriangulo();

    string ClasificarTriangulo(float, float, float);
    float CalcularHipotenusa(float, float);
};

Triangulo::Triangulo()
{}

Triangulo::Triangulo(string _Color, float _MedidaLado1, float _MedidaLado2, float _MedidaLado3, string _TipoTriangulo)
{
    Color = _Color;
    MedidaLado1 = _MedidaLado1;
    MedidaLado2 = _MedidaLado2;
    MedidaLado3 = _MedidaLado3;
    TipoTriangulo = _TipoTriangulo;
}

void Triangulo::setColor(string _Color)
{
    Color = _Color;
}
string Triangulo::getColor()
{
    return Color;
}

void Triangulo::setMedidaLado1(float _MedidaLado1)
{
    MedidaLado1 = _MedidaLado1;
}
float Triangulo::getMedidaLado1()
{
    return MedidaLado1;
}

void Triangulo::setMedidaLado2(float _MedidaLado2)
{
    MedidaLado2 = _MedidaLado2;
}
float Triangulo::getMedidaLado2()
{
    return MedidaLado2;
}

void Triangulo::setMedidaLado3(float _MedidaLado3)
{
    MedidaLado3 = _MedidaLado3;
}
float Triangulo::getMedidaLado3()
{
    return MedidaLado3;
}

void Triangulo::setTipoTriangulo(string _TipoTriangulo)
{
    TipoTriangulo = _TipoTriangulo;
}    
string Triangulo::getTipoTriangulo()
{
    return TipoTriangulo;
}

string Triangulo::ClasificarTriangulo(float MedidaLado1, float MedidaLado2, float MedidaLado3)
{
    if ((MedidaLado1 == MedidaLado2) && (MedidaLado2 == MedidaLado3))
    {
        return TipoTriangulo = "equilatero";
    }
    else if ((MedidaLado1 == MedidaLado2) || (MedidaLado2 == MedidaLado3) || (MedidaLado1 == MedidaLado3))
    {
        return TipoTriangulo = "isosceles";
    }
    else
    {
        return TipoTriangulo = "escaleno";
    }
}

float Triangulo::CalcularHipotenusa(float MedidaLado1, float MedidaLado2)
{
    return MedidaLado3 = (sqrt((pow(MedidaLado1, 2)) + (pow(MedidaLado2, 2))));
}

int main() 
{
    int opcion;
    Triangulo triangulo1, triangulo2, triangulo3;
    string Color;
    float MedidaLado1;
    float MedidaLado2;
    float MedidaLado3;
    string TipoTriangulo;

    do
    {
        cout<<"Escoja una opcion: \n";
        cout<<"1. Insertar datos.\n";
        cout<<"2. Clasificacion de triangulo.\n";
        cout<<"3. Salir.\n";

        switch (opcion)
        {
            case 1:
            {
                cin.ignore();
                cout<<"Color: ";
                getline(cin, Color);
                triangulo1.setColor(Color);

                cout<<"Medida lado 1: ";
                cin>>MedidaLado1;
                while (MedidaLado1 < 0)
                {
                    cout<<"ERROR, Intentelo de nuevo.\n";
                    cout<<"Medida lado 1: ";
                    cin>>MedidaLado1;
                }
                triangulo1.setMedidaLado1(MedidaLado1);

                cout<<"Medida lado 2: ";
                cin>>MedidaLado2;
                while (MedidaLado2 < 0)
                {
                    cout<<"ERROR, Intentelo de nuevo.\n";
                    cout<<"Medida lado 2: ";
                    cin>>MedidaLado2;
                }
                triangulo1.setMedidaLado2(MedidaLado2);

                cout<<"Medida lado 3: ";
                cin>>MedidaLado3;
                while (MedidaLado3 < 0)
                {
                    cout<<"ERROR, Intentelo de nuevo.\n";
                    cout<<"Medida lado 3: ";
                    cin>>MedidaLado3;
                }
                triangulo1.setMedidaLado3(MedidaLado3);
            }
            break;
        
            case 2:
            {
                triangulo1.setTipoTriangulo(triangulo1.ClasificarTriangulo(triangulo1.getMedidaLado1(), triangulo1.getMedidaLado2(), triangulo1.getMedidaLado3()));
                cout<<"Su triangulo es "<<triangulo1.getTipoTriangulo()<<".\n";

                if ((triangulo1.getTipoTriangulo() == "isosceles") || (triangulo1.getTipoTriangulo() == "escaleno"));
                {
                    
                }
                
            }
            break;

            default:
            break;
        }


    } 
    while (opcion != 3);
    

    return 0;
}