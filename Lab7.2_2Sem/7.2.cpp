#include <iostream>
#include <math.h>
using namespace std;


void belong(int R, ...) {
    int count = 0;
    int *p = &R;

    while(*(p+2) || *(p+1)) {
        int x = *(p+2);
        cout<<"x = "<<x<<endl;
        int y = *(p+4);
        cout<<"y = "<<y<<endl;
        if (x*x + y*y <= R*R) {
            count++;
        }
        p += 4;
    }
    cout << "Количество точек, лежащих в окружности с радиусом "<<R<<": " << count << endl;
}

int main() {
    belong(3, 1, 1, 0);    // 3 параметра 
    belong(3, 1, 1, 2, 2, 3, 3, 5, 5, 0);   // 9 параметров
    belong(4, 1, 1, 4, 4, 2, 2, 3, 3, 10, 10, 0);    // 11 параметров 
    return 0;
}