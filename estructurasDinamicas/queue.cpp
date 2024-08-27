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

struct Node *front = nullptr;
struct Node *back = nullptr;

bool Empty();
void Insert(User u);
void Delete();
void Print();
void PrintFront();
void PrintBack();
void Verification();

int main()
{
    struct User u;
    bool flag = true;
    int option = 0;

    while (flag)
    {
        cout << "Escoja una opcion:\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Imprimir toda la cola\n";
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
            PrintFront();
            break;

        case 5:
            PrintBack();
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

bool Empty()
{
    if (front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Insert(User u)
{
    struct Node *newNode = new Node();

    newNode->data = u;
    newNode->next = nullptr;

    if (front == nullptr)
    {
        front = newNode;
    }
    else
    {
        back->next = newNode;
    }

    back = newNode;
}

void Delete()
{
    if (Empty())
    {
        Verification();
        return;
    }
    else
    {
        struct Node *temporary = front;

        if (front == back)
        {
            front = nullptr;
            back = nullptr;
        }
        else
        {
            front = temporary->next;
            temporary = nullptr;
        }

        delete temporary;
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
        struct Node *temporary = front;
        int counter = 1;
        cout << "Elementos de la cola:\n";
        while (temporary != nullptr)
        {
            cout << "#" << counter << " - Nombre: " << temporary->data.name << " - Edad: " << temporary->data.age << "\n";
            temporary = temporary->next;
            counter++;
        }
    }
}

void PrintFront()
{
    if (Empty())
    {
        Verification();
    }
    else
    {
        struct Node *temporary = front;
        cout << "\nFrente de cola:\n";
        cout << "Nombre: " << temporary->data.name << " - Edad: " << temporary->data.age << "\n";
    }
}

void PrintBack()
{
    if (Empty())
    {
        Verification();
    }
    else
    {
        struct Node *temporary = back;
        cout << "\nFinal de cola:\n";
        cout << "Nombre: " << temporary->data.name << " - Edad: " << temporary->data.age << "\n";
    }
}

void Verification()
{
    cout << "Cola vacia!\n";
}