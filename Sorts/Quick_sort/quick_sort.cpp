#include <iostream>
#include <vector>

using namespace std;

// Функция для быстрой сортировки
void quicksort(vector<int>& items, int left, int right) {
    int i = left, j = right, pivot = items[(left + right) / 2], tmp;
    do {
        while ((items[i] < pivot) && (i < right)) i++;
        while ((pivot < items[j]) && (j > left)) j--;
        if (i <= j) {
            tmp = items[i];
            items[i] = items[j];
            items[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) quicksort(items, left, j);
    if (i < right) quicksort(items, i, right);
}

int main() {

    int n = 25; // Размер массива
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        int new_element;
        cout<<"Введите элемент массива: ";
        cin>>new_element;
        arr[i] = new_element;
    }

    // Выводим исходный массив
    cout << "Исходный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортируем массив методом быстрой сортировки
    quicksort(arr, 0, n - 1);

    // Выводим отсортированный массив
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}