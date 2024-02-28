#include <iostream>

using namespace std;


unsigned long long int fib(int n)
{
    if(n == 0) {
        return 0;
    }
    if(n == 1 || n == 2) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main()
{
    setlocale(LC_ALL, "RU");
    int n;
    cout<<"Введите n: ";
    cin>>n;
    for (int i = 0; i < n; i++) {
        cout << fib(i) <<" ";
    }
    return 0;
}