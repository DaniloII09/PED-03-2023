#include <iostream>

using namespace std;

class ATM
{
private:
    string TipoATM;
    string Banco;
    float CantidadDineroAlmacenada;
    string Ubicacion;

public:
    ATM();
    ATM(string _TipoATM, string _Banco, float _CantidadDineroAlmacenada, string _Ubicacion);

    void setTipoATM(string);
    string getTipoATM();
    void setBanco(string);
    string getBanco();
    void setCantidadDineroAlmacenada(float);
    float getCantidadDineroAlmacenada();
    void setUbicacion(string);
    string getUbicacion();

    int Retirar(int);
    void verEstadoCuenta();
    float Depositar(float);    
};

ATM::ATM() {}
ATM::ATM(string _TipoATM, string _Banco, float _CantidadDineroAlmacenada, string _Ubicacion)
{
    TipoATM = _TipoATM;
    Banco = _Banco;
    CantidadDineroAlmacenada = _CantidadDineroAlmacenada;
    Ubicacion = _Ubicacion;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ATM::setTipoATM(string _TipoATM)
{
    TipoATM = _TipoATM;
}
string ATM::getTipoATM()
{
    return TipoATM;
}

void ATM::setBanco(string _Banco)
{
    Banco = _Banco;
}
string ATM::getBanco()
{
    return Banco;
}

void ATM::setCantidadDineroAlmacenada(float _CantidadDineroAlmacenada)
{
    CantidadDineroAlmacenada = _CantidadDineroAlmacenada;
}
float ATM::getCantidadDineroAlmacenada()
{
    return CantidadDineroAlmacenada;
}

void ATM::setUbicacion(string _Ubicacion)
{
    Ubicacion = _Ubicacion;
}
string ATM::getUbicacion()
{
    return Ubicacion;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ATM::Retirar(int CantidadDineroIngresado)
{
    CantidadDineroAlmacenada -= CantidadDineroIngresado;
    return CantidadDineroIngresado;
}

void ATM::verEstadoCuenta()
{
    cout << "Banco " << Banco << ".\n Dinero Almacenado: $" << CantidadDineroAlmacenada << ".\n Ubicacion: " << Ubicacion << ".\n";
}

float ATM::Depositar(float CantidadDineroIngresado)
{
    return CantidadDineroAlmacenada += CantidadDineroIngresado;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

int main()
{
    //CONSTRUIR DOS OBJETOS, UNO FULL Y OTRO TRADICIONAL
    //SI SE SELECCIONA EL FULL, ENTONCES QUE ACCEDA A TODOS LOS METODOS
    //PERO SINO SOLO A METODOS RETIRAR Y VER ESTADO DE CUENTA

    return 0;
}
