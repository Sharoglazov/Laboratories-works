#include <iostream>
#include <vector>
using namespace std;

// Функция для интерполяционного поиска в отсортированном массиве
int interpolationSearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        // Интерполируем позицию элемента
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target) {
            return pos; // Найден элемент
        } else if (arr[pos] < target) {
            left = pos + 1; // Искать в правой половине
        } else {
            right = pos - 1; // Искать в левой половине
        }
    }

    return -1; // Элемент не найден
}

int main() {
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 16, 18, 19, 23, 25, 28, 35};
    for (int i = 0; i < sortedArray.size(); i++) {
        cout<<sortedArray[i]<<" ";
    }


    int target;
    cout<<"\nВведите ключ: ";
    cin>>target;
    cout<<endl;

    int result = interpolationSearch(sortedArray, target);

    if (result != -1) {
        cout << "Элемент " << target << " найден на позиции " << result+1 << endl;
    } else {
        cout << "Элемент " << target << " не найден" << endl;
    }

    return 0;
}
