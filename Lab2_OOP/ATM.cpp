#include "ATM.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор без параметров
ATM::ATM() {
    id = 0;
    rest = 0;
    max_sum = 0;
    cout<<"Constructor without parameters for: "<<this<<endl;
}
//конструктор с параметрами
ATM::ATM(int N, double K, double S) {
    id=N;
    rest=K;
    max_sum=S;
    cout<<"Constructor with parameters for: "<<this<<endl;
}
//конструктор копирования
ATM::ATM(const ATM &t) {
    id=t.id;
    rest=t.rest;
    max_sum=t.max_sum;
    cout<<"Copy constructor for: "<<this<<endl;
}
//деструктор
ATM::~ATM() {
    cout<<"Destructor for: "<<this<<endl;
}
//селекторы
int ATM::get_id() {
    return id;
}
double ATM::get_rest() {
    return rest;
}
double ATM::get_max_sum() {
    return max_sum;
}
//модификаторы
void ATM::set_id(int N) {
    id = N;
}
void ATM::set_rest(double K) {
    rest = K;
}
void ATM::set_max_sum(double S) {
    max_sum = S;
}
//метод для просмотра атрибутов
void ATM::show() {
    cout<<"id: "<<id<<endl;
    cout<<"rest: "<<rest<<endl;
    cout<<"max_sum: "<<max_sum<<endl;
}