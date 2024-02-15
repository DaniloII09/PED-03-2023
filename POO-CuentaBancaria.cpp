#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Simular los fondos del banco
float FondoBanco = 5000;

// Clase 1
class CuentaBancaria
{
private:
    string NumCuenta = "A12345678910";
    int pin;
    string nombrePersona;
    float balance = 0;

public:
    // DECLARACIONES
    // Constructores
    CuentaBancaria();
    CuentaBancaria(string, int, string, float);
    // Set y Get

    void setNumCuenta(string);
    string getNumCuenta();
    void setPin(int);
    int getPin();
    void setNPersona(string);
    string getNPersona();
    void setBalance(float);
    float getBalance();
};
// DEFINICIONES
//  Constructores
CuentaBancaria::CuentaBancaria() {}
CuentaBancaria::CuentaBancaria(string _NumCuenta, int _pin, string _nombrePersona, float _balance)
{
    NumCuenta = _NumCuenta;
    pin = _pin;
    nombrePersona = _nombrePersona;
    balance = _balance;
}

// SET
void CuentaBancaria::setNumCuenta(string _NumCuenta)
{
    NumCuenta = _NumCuenta;
}
void CuentaBancaria::setPin(int _pin)
{
    pin = _pin;
}
void CuentaBancaria::setNPersona(string _nombrePersona)
{
    nombrePersona = _nombrePersona;
}

void CuentaBancaria::setBalance(float _balance)
{
    balance = _balance;
}

// GET
string CuentaBancaria::getNumCuenta()
{
    return NumCuenta;
}
int CuentaBancaria::getPin()
{
    return pin;
}

string CuentaBancaria::getNPersona()
{
    return nombrePersona;
}
float CuentaBancaria::getBalance()
{
    return balance;
}

// Clase 2
class Transaccion
{
private:
    int idTransaccion;
    string tipoTransaccion;

public:
    // DECLARACIONES
    // Constructores
    Transaccion();
    Transaccion(int, string);
    void setIdTransaccion(int);
    int getIdTransaccion();
    void setTipoTransaccion(string);
    string getTipoTransaccion();

    // Metodos
    int CalcularRetiroCuenta(CuentaBancaria, int);
    int CalcularDepositoCuenta(CuentaBancaria, int);
    void ImprimirTicket(CuentaBancaria);
};

// DEFINICIONES
// Constructores
Transaccion::Transaccion() {}
Transaccion::Transaccion(int _idTransaccion, string _tipoTransaccion)
{
    idTransaccion = _idTransaccion;
    tipoTransaccion = _tipoTransaccion;
}

// SET
void Transaccion::setIdTransaccion(int _idTransaccion)
{
    idTransaccion = _idTransaccion;
}
void Transaccion::setTipoTransaccion(string _tipoTransaccion)
{
    tipoTransaccion = _tipoTransaccion;
}
// GET
int Transaccion::getIdTransaccion()
{
    return idTransaccion;
}
string Transaccion::getTipoTransaccion()
{
    return tipoTransaccion;
}

/* Calcular el retiro tomando en cuenta el valor
  el fondoBanco menos lo del balance del usuario menos el monto */

int Transaccion::CalcularRetiroCuenta(CuentaBancaria cuenta, int monto)
{
    return cuenta.getBalance() - monto;
}

// Calcular el deposito a la cuenta del usuario
int Transaccion::CalcularDepositoCuenta(CuentaBancaria cuenta, int monto)
{
    return cuenta.getBalance() + monto;
}

void Transaccion::ImprimirTicket(CuentaBancaria cuenta)
{
    cout<<"\n-------------------------------------------\n";
    cout<<" Nombre: "<<cuenta.getNPersona()<<"\n";
    cout<<" Tipo de transaccion: "<<getTipoTransaccion()<<"\n";
    cout<<" ID de transaccion: "<<getIdTransaccion()<<"\n";
    cout<<" Saldo: $" <<cuenta.getBalance()<<"\n";
    cout<<"-------------------------------------------";
}

int numeroRandom();

int main()
{
    // Creando al objeto con manejo de memoria automatico
    CuentaBancaria cuenta1;
    Transaccion trans1;

    string nombrePersona;

    // Variables
    int pin;
    int op;
    int monto;

    /*  Si el usuario no tiene PIN que se cree un acceso
     Solicitando los datos nombrePersona, cuentaBancaria y PIN
     el pin pueden generarlo aleatorio conformado por 4 digitos o
     se le pide al usuario
     valores se deben almacenar en los atributos de la clase  */
    cout << "BIENVENIDO/A, crea tu usuario de cuenta bancaria!\n";
    cout << "Ingresa tu nombre: ";
    getline(cin, nombrePersona);
    cuenta1.setNPersona(nombrePersona);
    cout << "Crea tu PIN de cuatro numeros: ";
    cin >> pin;
    cuenta1.setPin(pin);
    cout << "Ya estas listo/a para entrar al sistema.\n\n";

    // Si ya tiene pin, pasa a lo siguiente
    cout << "Ingresa tu PIN: ";
    cin >> pin;

    if (pin == cuenta1.getPin())
    {
        do
        {
            cout << "\nIngresa la opcion \n 1. Depositar dinero \n 2. Retirar Dinero \n 3. Mostrar estado cuenta o balance  \n 4. Salir del sistema \n";
            cin >> op;
            switch (op)
            {
            case 1: // Depositar
                cout << "Ingresa el monto a depositar: $";
                cin >> monto;
                cuenta1.setBalance(trans1.CalcularDepositoCuenta(cuenta1, monto));
                
                /* Mostrar un tiquete despues de la transaccion que detalle
                Id_transaccion - valor aleatorio
                tipo_Transaccion (retiro o deposito o mostrar balance)
                Estos valores se deben guardar en los atributos de la clase Transaccion */
                trans1.setIdTransaccion(numeroRandom());
                trans1.setTipoTransaccion("Deposito");

                trans1.ImprimirTicket(cuenta1);
                break;
            case 2: // Retirar
                cout << "Ingresa el monto a retirar: $";
                cin >> monto;
                cuenta1.setBalance(trans1.CalcularRetiroCuenta(cuenta1, monto));
                
                /* Mostrar un tiquete despues de la transaccion que detalle
                Id_transaccion - valor aleatorio
                tipo_Transaccion (retiro o deposito o mostrar balance)
                Estos valores se deben guardar en los atributos de la clase Transaccion */
                trans1.setIdTransaccion(numeroRandom());
                trans1.setTipoTransaccion("Retiro");

                trans1.ImprimirTicket(cuenta1);
                break;
            case 3: // Estado Cuenta
                trans1.setIdTransaccion(numeroRandom());
                trans1.setTipoTransaccion("Mostrar Estado de Cuenta");

                trans1.ImprimirTicket(cuenta1);
                break;
            case 4: // Salir
                cout << "Saliendo...";
                break;
            default:
                cout << "Opcion no valida.";
                break;
            }

        } while (op != 4);
    }
    else
    {
        cout << "PIN, incorrecto.";
    }

    system("pause");
    return 0;
}

int numeroRandom()
{
    srand(time(nullptr));
    return rand() % 90000 + 10000;
}