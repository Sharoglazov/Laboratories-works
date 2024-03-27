#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int size;
    cout<<"Введите размер массива: ";
    cin>>size;
    cout<<"Последовательно введите элементы массива: ";
    vector <char> a(size);

    for (int i = 0; i < size; i++) {
        char new_element;
        cin>>new_element;
        a[i] = new_element;
    }

    for (int i = 0; i < size; i++) {
        cout<<a[i]<<" ";
    }
    cout << "\nВведите ключ для поиска" << endl;
    char key;
    cin >> key;
    bool flag = false;
    int number = 0;
    for (int i = 0; i < size && flag == false; i++) {
        if (a[i] == key) {
            flag = true;
            number = i+1;
    }
}
    if (flag) {
        cout << "Ключ находится по номеру " << number;
    }
    else {
        cout << "Ключ не найден";
    }
    return 0;
}