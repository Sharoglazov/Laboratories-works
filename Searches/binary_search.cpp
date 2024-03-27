#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;     // Индексы крайних элементов массива
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Найден элемент
        } else if (arr[mid] < target) {
            left = mid + 1; // Искать в правой половине
        } else {
            right = mid - 1; // Искать в левой половине
        }
    }

    return -1; // Элемент не найден
}

int main() {
    vector<int> sortedArray = {3, 4, 5, 6, 11, 16, 22, 57, 69, 800};
    cout<<"Отсортированный массив: ";
    for (int i = 0; i < sortedArray.size(); i++) {
        cout<<sortedArray[i]<<" ";
    }
    cout<<"\nВведите ключ: ";
    int target;
    cin>>target;

    int result = binarySearch(sortedArray, target);

    if (result != -1) {
        cout << "Элемент " << target << " найден на позиции " << result+1 << endl;
    } else {
        cout << "Элемент " << target << " не найден" << endl;
    }

    return 0;
}

