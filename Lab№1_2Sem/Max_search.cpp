#include <iostream>
#include <ctime>
using namespace std;
const int n = 10;
int s, j;
int a[n];


int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RU");

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 200 - 100;
	}

	int max = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			s = 1;
			j = i;
		}
		else {
			if (a[i] == max) {
				s++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i]<<endl;
	}

	cout << "Максимальный элемент последовательности: " << max << endl;
	cout << "Номер максимального элемента: " << j + 1 << endl;
	cout << "Количество элементов, совпадающих с максимальным: " << s << endl;
	
}
