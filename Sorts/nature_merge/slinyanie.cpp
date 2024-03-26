#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int p, int q, int r) { // функция слияния двух цепочек
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void naturalMergeSort(vector<int>& arr) {
    bool sorted = false;
    while (!sorted) {
        int p = 0;
        int r = arr.size()-1;
        sorted = true;
        while (p < r) {
            int q = p;
            while (q < r && arr[q] <= arr[q+1]) {
                q++;
            }
            if (q < r) {
                merge(arr, p, q, r);
                // Вывод этапа сортировки
                cout<<"\nПромежуточный этап: ";
                for (int i = 0; i < r + 1; i++) {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                sorted = false;
            }
            p = q + 1;
        }
    }
}

int main() {
    cout<<"Введите количество элементов: ";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cout<<"Введите элемент номер "<< i+1 <<": ";
        int new_element;
        cin>>new_element;
        arr[i] = new_element;
    }
    cout << "Изначальный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout<<endl;
    
    naturalMergeSort(arr);

    cout<<endl;
    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    return 0;
}