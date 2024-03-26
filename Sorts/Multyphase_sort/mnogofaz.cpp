#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;



void multiPhaseMergeSort(int array[], int n) {
    int phase_size = 1;
    while (phase_size < n) {
        for (int i = 0; i < n; i += 2 * phase_size) {
            int start = i;
            int mid = min(i + phase_size, n);
            int end = min(i + 2 * phase_size, n);
            int * temp = new int[end - start];
            
            int left = start, right = mid, index = 0;
            while (left < mid && right < end) {
                if (array[left] <= array[right]) {
                    temp[index++] = array[left++];
                } else {
                    temp[index++] = array[right++];
                }
            }
            while (left < mid) {
                temp[index++] = array[left++];
            }
            while (right < end) {
                temp[index++] = array[right++];
            }
            
            for (int k = 0; k < index; k++) {
                array[start + k] = temp[k];
            }
        }
        phase_size *= 2;
        cout<<"\nПромежуточный этап сортировки: ";
        for (int i = 0; i < n; i++) {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {

    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        int new_element;
        cout<<"Введите элемент массива: ";
        cin>>new_element;
        array[i] = new_element;
    }

    cout << "\nИзначальный массив: ";

    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout<<array[i]<<" ";
    }


    multiPhaseMergeSort(array, ARRAY_SIZE);

    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << array[i] << " ";
    }

    return 0;
}