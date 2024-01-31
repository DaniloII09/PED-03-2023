#include <iostream>

using namespace std;

int fibonacci(int n);

int main()
{
    int n=0;

    cout<<"Ingrese un numero para iniciar la sucesion de fibonacci: ";
    cin>>n;

    cout<<fibonacci(n);


    return 0;
}

int fibonacci(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fibonacci(n-2) + fibonacci(n-1);
}