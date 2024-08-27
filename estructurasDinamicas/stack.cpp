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

struct Node *stack = nullptr;

void Insert(User u);
void Print();
void Delete();
bool Empty();
void FirstElement();
void LastElement();
void Verification();

int main()
{
    User u;
    bool flag = true;
    int option = 0;

    while (flag)
    {
        cout << "Escoja una opcion:\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Imprimir toda la pila\n";
        cout << "4. Imprimir primer elemento\n";
        cout << "5. Imprimir ultimo elemento\n";
        cout << "6. Salir\n";
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

            Insert(u);

            break;

        case 2:
            Delete();
            break;

        case 3:
            Print();
            break;

        case 4:
            LastElement();
            break;

        case 5:
            break;

        case 6:
            flag = false;
            break;

        default:
            cout << "Opcion no valida!\n";
            break;
        }
    }

    return 0;
}

void Insert(User u)
{
    struct Node *newNode = new Node();

    newNode->data = u;
    newNode->next = stack;
    stack = newNode;
}

void Print()
{
    if (Empty())
    {
        Verification();
    }
    else
    {
        struct Node *temporary = stack;
        int counter = 1;

        cout << "Elementos de la pila:\n";
        while (temporary != nullptr)
        {
            cout << "#" << counter << " - Nombre: " << temporary->data.name << " - Edad: " << temporary->data.age << "\n";
            counter++;
            temporary = temporary->next;
        }
    }
}

void Delete()
{
    if (Empty())
    {
        Verification();
    }
    else
    {
        struct Node *temporary = stack;

        stack = temporary->next;

        delete temporary;
    }
}

bool Empty()
{
    if (stack == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void FirstElement()
{
    if (Empty())
    {
        Verification();
    }
    else
    {
        struct Node *temporary = stack;

        while (temporary->next != nullptr)
        {
            temporary = temporary->next;
        }

        cout << "Nombre: " << temporary->data.name << " - Edad: " << temporary->data.age << "\n";
    }
}

void LastElement()
{
    if (Empty())
    {
        Verification();
    }
    else
    {
        struct Node *temporary = stack;
        cout << "Nombre: " << temporary->data.name << " - Edad: " << temporary->data.age << "\n";
    }
}

void Verification()
{
    cout << "Pila vacia!\n";
}