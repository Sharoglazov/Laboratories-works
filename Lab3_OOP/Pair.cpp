#include <iostream>
#include "Pair.h"
using namespace std;

class Pair {
public:
    int first;
    double second;

    // Конструктор
    Pair(int first, double second) : first(first), second(second) {}

    // Операторы сравнения
    bool operator == (const Pair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator != (const Pair& other) const {
        return !(*this == other);
    }

    // Вычитание константы
    Pair operator-(int value) const {
        return Pair(first - value, second);
    }

    Pair operator-(double value) const {
        return Pair(first, second - value);
    }

    // Вывод на экран
    friend ostream& operator<<(ostream& os, const Pair& pair) {
        os << pair.first << ":" << pair.second;
        return os;
    }
};

int main() {
    Pair p1(5, 3.14);
    Pair p2(2, 2.71);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    if (p1 == p2) {
        cout << "p1 и p2 равны" << endl;
    } else {
        cout << "p1 и p2 не равны" << endl;
    }

    Pair p3 = p1 - 2;  // Вычитание целого числа
    Pair p4 = p2 - 0.5; // Вычитание вещественного числа

    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;

    return 0;
}

