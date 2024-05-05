#include <iostream>
#include <string>
using namespace std;
class ATM {
    //атрибуты
    int id;
    double rest;
    double max_sum;
public:
    ATM();//конструктор без параметров
    ATM(int, double, double);//конструктор с параметрами
    ATM(const ATM&);//конструктор копирования
    ~ATM();//деструктор
    int get_id();//селектор
    void set_id(int);//модификатор
    double get_rest();//селектор
    void set_rest(double); //модификатор
    double get_max_sum();//селектор
    void set_max_sum(double); //модификатор
    void show();//просмотр атрибутов
};