#include <iostream>
#include <ctime>
#include <string.h>
#include <math.h>
using namespace std;
const int N = 16;
const int n = 4;
string a[n];
int k = 0, q = 0;
string s;

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Введите s: " << endl;
	cin >> s;
	cout << "Исходный: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i] += s[k];
			k++;
		}

		cout << a[i] << endl;
	}

	string temp;
	cout << "Отсортированный: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}

	for (int i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) {
			q++;
		}
	}
	if (q == n - 1) {
		cout << "Да, можно" << endl;
	}
	else {
		cout << "Нет, нельзя" << endl;
	}
}