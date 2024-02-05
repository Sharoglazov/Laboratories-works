#include <iostream>
#include <ctime>
using namespace std;
const int n = 10;
int a[n];
int temp, k;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	cout << "Введите k: ";
	cin >> k;

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 50;
		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < k; i++) {
		temp = a[0];
		for (int j = 0; j < n-1; j++) {
			a[j] = a[j+1];
		}
		a[n-1] = temp;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}