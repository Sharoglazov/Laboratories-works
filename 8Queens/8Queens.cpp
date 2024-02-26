#include <iostream>
using namespace std;
const int n = 8;
int a[n][n];

void place(); // Создание нулевого массива 

void Output(); // Вывод измененного массива

void Queen(int i, int j); // Постановка ферзя

void del(int i, int j); // Удаление ферзя

bool MainMotion(int i); //Основная функция

int main()
{
    setlocale(LC_ALL, "Ru");
    place();
    MainMotion(0);
    cout << endl << " Решение: " << endl;
    Output();
    cout<<endl;
    return 0;
}

void place() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
}

void Output() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
            {
                cout << " Q "; // Ферзь
            }
            else if (a[i][j] > 0) {
                cout << " X "; // Клетка под боем
            }
            else {
                cout << " _ "; // Клетка    
            }
        }
        cout << endl;
    }
}

void Queen(int i, int j) {
    for (int x = 0; x < n; ++x)
    {
        a[x][j] += 1;
        a[i][x] += 1;
        int d;
        d = j - i + x;
        if (d >= 0 && d < n)
        {
            a[x][d] += 1;
        }
        d = j + i - x;
        if (d >= 0 && d < n) {
            a[x][d] += 1;
        }
    }
    a[i][j] = -1;
    cout << endl;
    Output();
}

void del(int i, int j) {
    for (int x = 0; x < n; ++x) {
        a[x][j] -= 1;
        a[i][x] -= 1;
        int d;
        d = j - i + x;
        if (d >= 0 && d < n) {
            a[x][d] -= 1;
        }
        d = j + i - x;
        if (d >= 0 && d < n) {
            a[x][d] -= 1;
        }
    }
    cout << endl << "Отмена предыдущего хода" << endl;
    Output();
    a[i][j] = 0;
}

bool MainMotion(int i) {
    bool f = false;
    for (int j = 0; j < n; ++j)
    {
        if (a[i][j] == 0)
        {
            Queen(i, j); // Постановка ферзя
            if (i == 7)
            {
                f = true;
            }
            else if (!(f = MainMotion(i + 1)))
            {
                del(i, j); // Удаление ферзя
            }
        }
        if (f) break;
    }
    return f;
}