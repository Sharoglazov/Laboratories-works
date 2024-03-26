#include <iostream>
#include <vector>
using namespace std;


// сортировка методом Шелла
void shellSort(vector<int>& arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {  //gap - значение интервала, равное половине длины массива
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
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

    cout << "Исходный массив:\n";

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    shellSort(arr, n);
    cout << "Отсортированный массив:\n";

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}