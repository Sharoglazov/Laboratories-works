#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
using namespace std;

struct films {
    string name;
    string director;
    string country;
    int profit;
    void enter_info(string n, string d, string c, int p) {
        name = n;
        director = d;
        country = c;
        profit = p;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("CLS");
    system("chcp 1251");
    int N;
    cout<<"Enter N: ";
    cin >> N;
    cout<<endl;
    films mass[5];

    for (int i = 0; i < N; i++) {
        string n, d, c;
        int p;
        cout<<"Enter name, director, country and profit: "<<endl;
        cin>>n>>d>>c>>p;
        cout<<endl;
        mass[i].enter_info(n, d, c, p);
    }

    for (int i = 0; i < N; i++) {
        cout<<mass[i].name<<" "<<mass[i].director<<" "<<mass[i].country<<" "<<mass[i].profit<<endl;
    }
    return 0;
}

