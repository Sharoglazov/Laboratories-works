#include "ATM.h"
#include <iostream>
#include <string>
using namespace std;
//функция для возврата объекта как результата
ATM make_ATM() {
    int s;
    double i;
    double d;
    cout<<"input id: ";
    cin>>s;
    cout<<"input rest: ";
    cin>>i;
    cout<<"input max_sum: ";
    cin>>d;
    ATM t(s, i, d);
    return t;
}
//функция для передачи объекта как параметра
void print_ATM(ATM t) {
    t.show();
}
int main() {
    //конструктор без параметров
    ATM t1;
    t1.show();
    //конструктор с параметрами
    ATM t2(001001, 100.5, 15000.0);
    t2.show();
    //конструктор копирования
    ATM t3=t2;
    t3.set_id(002002);
    t3.set_rest(2.2);
    t3.set_max_sum(5000.0);
    //конструктор копирования
    print_ATM(t3);
    //конструктор копирования
    t1 = make_ATM();
    t1.show();
    return 0;
}