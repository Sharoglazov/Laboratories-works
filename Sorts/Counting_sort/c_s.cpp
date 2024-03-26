#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки подсчетом
void countSort(vector<int>& arr, int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    vector<int> output(n);

    // Создаем массив `count` размера `maxVal + 1`, инициализируем его нулями
    vector<int> count(maxVal + 1, 0);

    // Используя значение каждого элемента входного массива в качестве индекса,
    // сохраняем счетчик каждого целого числа в `count[]`
    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    // Копируем в выходной массив, сохраняя порядок входов с одинаковыми ключами
    int outputIndex = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i] > 0) {
            output[outputIndex] = i;
            --count[i];
            ++outputIndex;
        }
    }

    // Выводим отсортированный массив
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << output[i] << " ";
    }
}

int main() {

    int n = 25; // Размер массива
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        int new_number;
        cout<<"Введите элемент массива: ";
        cin>>new_number;
        arr[i] = new_number;
    }

    // Выводим исходный массив
    cout << "Исходный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортируем массив методом подсчета
    countSort(arr, n);

    return 0;
}