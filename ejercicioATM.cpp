#include <iostream>

using namespace std;

class ATM
{
private:
    string TipoATM;
    string Banco;
    int CantidadDineroAlmacenada;
    string Ubicacion;

public:
    ATM();
    ATM(string _TipoATM, string _Banco, int _CantidadDineroAlmacenada, string _Ubicacion);

    void setTipoATM(string);
    string getTipoATM();
    void setBanco(string);
    string getBanco();
    void setCantidadDineroAlmacenada(int);
    int getCantidadDineroAlmacenada();
    void setUbicacion(string);
    string getUbicacion();

    int Retirar(int);
    void verEstadoCuenta();
    int Depositar(int);    
};

ATM::ATM() {}
ATM::ATM(string _TipoATM, string _Banco, int _CantidadDineroAlmacenada, string _Ubicacion)
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

void ATM::setCantidadDineroAlmacenada(int _CantidadDineroAlmacenada)
{
    CantidadDineroAlmacenada = _CantidadDineroAlmacenada;
}
int ATM::getCantidadDineroAlmacenada()
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

int ATM::Depositar(int CantidadDineroIngresado)
{
    return CantidadDineroAlmacenada += CantidadDineroIngresado;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

int main()
{
    //CONSTRUIR DOS OBJETOS, UNO FULL Y OTRO TRADICIONAL
    //SI SE SELECCIONA EL FULL, ENTONCES QUE ACCEDA A TODOS LOS METODOS
    //PERO SINO SOLO A METODOS RETIRAR Y VER ESTADO DE CUENTA
    ATM Full;
    ATM Tradicional;
    int opcionATM, opcionFull, opcionTrad;

    string TipoATM;
    string Banco;
    int CantidadDineroAlmacenada;
    string Ubicacion;
    int DineroRetirado;
    float DineroIngresado;

    cout<<"TIPO DE CAJERO\n";
    cout<<"1. Full.\n2. Tradicional.\n";
    cout<<"Opcion: ";
    cin>>opcionATM;
    while (opcionATM != 1 && opcionATM != 2)
    {
        cout<<"\nERROR, opcion no valida.\n";
        cout<<"TIPO DE CAJERO\n";
        cout<<"1. Full.\n2. Tradicional.\n";
        cout<<"Opcion: ";
        cin>>opcionATM;
    }

    if (opcionATM == 1)
    {
        Full.setTipoATM("Full");

        cout<<"\nIniciando sesion...\n";
        
        cin.ignore();
        cout<<"Banco: ";
        getline(cin, Banco);
        Full.setBanco(Banco);

        cout<<"Ubicacion: ";
        getline(cin, Ubicacion);
        Full.setUbicacion(Ubicacion);

        cout<<"Dinero Almacenado: $";
        cin>>CantidadDineroAlmacenada;
        while (CantidadDineroAlmacenada < 0)
        {
            cout<<"ERROR, cantidad no valida.\n";
            cout<<"Dinero Almacenado: $";
            cin>>CantidadDineroAlmacenada;
        }
        Full.setCantidadDineroAlmacenada(CantidadDineroAlmacenada);

        do
        {
            cout<<"\nCAJERO ATM FULL\n\n";
            cout<<"OPCIONES\n";
            cout<<"1. Retirar dinero.\n";
            cout<<"2. Ver estado de cuenta.\n";
            cout<<"3. Depositar.\n";
            cout<<"4. Salir.\n";
            cout<<"Su opcion es: ";
            cin>>opcionFull;

            switch (opcionFull)
            {
                case 1:
                {
                    cout<<"Cantidad a retirar: $";
                    cin>>DineroRetirado;
                    while (DineroRetirado < 0 || DineroRetirado > Full.getCantidadDineroAlmacenada())
                    {
                        cout<<"ERROR, cantidad no valida.\n";
                        cout<<"Cantidad a retirar: $";
                        cin>>DineroRetirado;
                    }

                    cout<<"Ha retirado $"<<Full.Retirar(DineroRetirado)<<".\n";
                }
                break;

                case 2:
                {
                    Full.verEstadoCuenta();
                }
                break;

                case 3:
                {
                    cout<<"Cantidad a depositar: $";
                    cin>>DineroIngresado;
                    while (DineroIngresado < 0)
                    {
                        cout<<"ERROR, cantidad no valida.\n";
                        cout<<"Cantidad a depositar: $";
                        cin>>DineroIngresado;
                    }
                    
                    Full.setCantidadDineroAlmacenada(Full.Depositar(DineroIngresado));
                }
                break;
            
                case 4:
                {
                    cout<<"Saliendo...";
                }
                break;

                default:
                break;
            }

        } while (opcionFull != 4);
    }
    else
    {
        Tradicional.setTipoATM("Tradicional");

        cout<<"\nIniciando sesion...\n";
        
        cin.ignore();
        cout<<"Banco: ";
        getline(cin, Banco);
        Tradicional.setBanco(Banco);

        cout<<"Ubicacion: ";
        getline(cin, Ubicacion);
        Tradicional.setUbicacion(Ubicacion);

        cout<<"Dinero Almacenado: $";
        cin>>CantidadDineroAlmacenada;
        while (CantidadDineroAlmacenada < 0)
        {
            cout<<"ERROR, cantidad no valida.\n";
            cout<<"Dinero Almacenado: $";
            cin>>CantidadDineroAlmacenada;
        }
        Tradicional.setCantidadDineroAlmacenada(CantidadDineroAlmacenada);

        do
        {
            cout<<"\nCAJERO ATM TRADICIONAL\n\n";
            cout<<"OPCIONES\n";
            cout<<"1. Retirar dinero.\n";
            cout<<"2. Ver estado de cuenta.\n";
            cout<<"3. Salir.\n";
            cout<<"Su opcion es: ";
            cin>>opcionTrad;

            switch (opcionTrad)
            {
                case 1:
                {
                    cout<<"Cantidad a retirar: $";
                    cin>>DineroRetirado;
                    while (DineroRetirado < 0 || DineroRetirado > Tradicional.getCantidadDineroAlmacenada())
                    {
                        cout<<"ERROR, cantidad no valida.\n";
                        cout<<"Cantidad a retirar: $";
                        cin>>DineroRetirado;
                    }

                    cout<<"Ha retirado $"<<Tradicional.Retirar(DineroRetirado)<<".\n";
                }
                break;

                case 2:
                {
                    Tradicional.verEstadoCuenta();
                }
                break;
            
                case 3:
                {
                    cout<<"Saliendo...";
                }
                break;

                default:
                break;
            }

        } while (opcionTrad != 3);
    }

    system("pause");
    return 0;
}
