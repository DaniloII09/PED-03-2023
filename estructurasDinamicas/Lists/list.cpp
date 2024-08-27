#include <iostream>

using namespace std;

struct User
{
    string name;
    int age;
};

struct Node
{
    struct User data;
    struct Node *next;
};

struct Node *list = nullptr;

void InsertBeggining(User u);
void InsertEnd(User u);
void InsertPosition(User u, int position);
void Print();
void DeleteBeggining();
void DeleteEnd();
void DeletePosition(int position);
bool Empty();
void Verification();
int DataCounter();

int main()
{
    User u;
    bool flag = true;
    int option = 0;
    int position = 0;

    while (flag)
    {
        cout << "Escoja una opcion:\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Insertar en una posicion\n";
        cout << "4. Imprimir\n";
        cout << "5. Eliminar al inicio\n";
        cout << "6. Eliminar al final\n";
        cout<<"7. Eliminar en una posicion\n";
        cout<<"8. Salir\n";
        cout << "Opcion: ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            cout << "Ingresar nombre: ";
            getline(cin, u.name);

            cout << "Ingresar edad: ";
            cin >> u.age;
            cin.ignore();

            InsertBeggining(u);

            break;

        case 2:
            cout << "Ingresar nombre: ";
            getline(cin, u.name);

            cout << "Ingresar edad: ";
            cin >> u.age;
            cin.ignore();

            InsertEnd(u);

            break;

        case 3:
            Print();
            cout<<"Ingresar posicion donde se ingresara el dato: ";
            cin>>position;
            cin.ignore();

            cout << "Ingresar nombre: ";
            getline(cin, u.name);

            cout << "Ingresar edad: ";
            cin >> u.age;
            cin.ignore();

            InsertPosition(u, position);

            break;

        case 4:
            Print();
            break;

        case 5:
            DeleteBeggining();
            break;

        case 6:
            DeleteEnd();
            break;

        case 7:
            Print();
            cout<<"Ingrese la posicion que eliminara: ";
            cin>>position;
            cin.ignore();
            DeletePosition(position);
            break;

        case 8:
            flag = false;
            break;

        default:
            cout << "Opcion no valida!\n";
            break;
        }
    }

    return 0;
}

void InsertBeggining(User u)
{
    struct Node *newNode = new Node();

    newNode->data = u;
    newNode->next = nullptr;

    if (list == nullptr)
    {
        list = newNode;
    }
    else
    {
        newNode->next = list;
        list = newNode;
    }   
}

void InsertEnd(User u)
{
    struct Node *newNode = new Node();

    newNode->data = u;
    newNode->next = nullptr;

    if (list == nullptr)
    {
        list = newNode;
    }
    else
    {
        struct Node *temporary = list;
        
        while (temporary->next != nullptr)
        {
            temporary = temporary->next;
        }
        
        temporary->next = newNode;
    }
}

void InsertPosition(User u, int position)
{
    int lastPosition = DataCounter() + 1;

    if ((position <= 0) || (position > lastPosition))
    {
        cout<<"Posicion no valida\n";
        return;
    }
    else
    {
        switch (position)
        {
        case 1:
            InsertBeggining(u);
            break;
        default:
            {
                struct Node *newNode = new Node();
                struct Node *temporary = list;

                newNode->data = u;
                newNode->next = nullptr;

                position--;

                while (position != 1)
                {
                    temporary = temporary->next;
                    position--;
                }
            
                newNode->next = temporary->next;
                temporary->next = newNode;
            }
            break;
        }
    }
}

void Print()
{
    if (Empty())
    {
        Verification();
    }
    else
    {
        struct Node *temporary = list;
        int counter = 1;
        cout<<"Elementos de la lista:\n";
        while (temporary != nullptr)
        {
            cout<<"#"<<counter<<" - Nombre: "<<temporary->data.name<<" - Edad: "<<temporary->data.age<<"\n";
            counter++;
            temporary = temporary->next;
        }
    }
}

void DeleteBeggining()
{
    if (Empty())
    {
        Verification();
        return;
    }
    else if (list->next = nullptr)
    {
        delete list;
        list = nullptr;
    }
    else
    {
        struct Node *temporary = list;

        list = temporary->next;

        delete temporary;
        temporary = nullptr;
    } 
}

void DeleteEnd()
{
    if (Empty())
    {
        Verification();
        return;
    }
    else if (list->next = nullptr)
    {
        delete list;
        list = nullptr;
    }
    else
    {
        struct Node *temporary = list;
        struct Node *temporaryBefore = temporary;

        while (temporary->next != nullptr)
        {
            temporaryBefore = temporary;   
            temporary = temporary->next;
        }

        temporaryBefore->next = nullptr;

        delete temporary;
        temporary = nullptr;
    }
}

void DeletePosition(int position)
{   
    if (Empty())
    {
        Verification();
    }
    else if ((position <= 0) || (position > DataCounter()))
    {
        cout<<"Posicion no valida\n";
        return;
    }
    else
    {
        switch (position)
        {
        case 1:
            DeleteBeggining();
            break;
        default:
            {
                struct Node *temporary = list;
                struct Node *temporaryBefore = temporary;
                struct Node *temporaryAfter = temporary;

                position--;

                while (position != 1)
                {
                    temporaryBefore = temporary;
                    temporary = temporary->next;
                    temporaryAfter = temporary->next;
                    position--;
                }

                temporaryBefore->next = temporaryAfter;
                delete temporary;
                temporary = nullptr;                
            }
            break;
        }
    }
}

bool Empty()
{
    if (list == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Verification()
{
    cout<<"Lista vacia!\n";
}

int DataCounter()
{
    int dataCounter = 0;
    struct Node *temporary = list;

    while (temporary != nullptr)
    {
        dataCounter++;
        temporary = temporary->next;
    }
    
    return dataCounter;
}
