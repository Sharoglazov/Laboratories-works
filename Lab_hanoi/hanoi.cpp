#include <iostream>
using namespace std;

extern int IterationCounter = 0;

void TowerSolver(int n, int start, int goal, int helping, int rootId) {
    if (n>0) {
        int id = ++IterationCounter;

        cout<<"Создание итерации с ID = " << id <<" и n = " << n << ", ID родительской итерации: "<<rootId<<endl<<endl;
        cout<<"Позиции башен: "<<endl <<"Стартовая: " <<start << ", Дополнительная: "<< helping <<", Целевая: " <<goal<<endl<<endl;
        cout<<"Создаем итерацию по первой ветке"<<endl<<"---------------------------"<<endl;

        TowerSolver(n-1, start, helping, goal, id);

        cout<<"Возвращаемся в ранее созданную итерцию с ID = " <<id<<" и n = "<<n<<endl;
        cout<<"Позиции башен: "<<endl << "Стартовая: " <<start <<", Дополнительная: "<<helping<< ", Целевая: "<<goal<<endl<<endl;
        cout<<"Выводим действие для решения задачи: "<<endl;
        cout<<"(Переместить диск) " << n << " с башни " << start << " на башню " << goal<< ")"<< endl << endl;
        cout<<"Создаем итерацию по второй ветке" << endl << "--------------------------------"<<endl;
        
        TowerSolver(n-1, helping, goal, start, id);

        cout<< "Уничтожаем итерацию с ID " << id <<endl << "----------------------" <<endl;
    }
    else {
        cout<<"Обнаружена итерация с n = 0. Поднимаемся на итерацию выше" <<endl <<"--------------------------" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int numberOfDisks;
    cout<< "Введите количество дисков" <<endl;
    cin >> numberOfDisks;

    if (numberOfDisks < 1) {
        cout<<"Число дисков должно быть больше или равно 1" <<endl;
        return 0;
    }

    cout<<endl;
    TowerSolver(numberOfDisks, 1, 3, 2, 0);
    cout<<endl <<"Всего потребовалось итераций: " <<IterationCounter<<endl;
}