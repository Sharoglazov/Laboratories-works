#include <iostream>
using namespace std;

struct operation {
    double first, second;
    int k;
    
    void Init(double f, double s) {
        first = f;
        second = s;
    }

    double sum(double first, double second) {
        return first + second;
    }

    double multiply(int k) {
        return sum(first, second) * k;
    }
};

int main() {
    operation A;
    A.Init(2, 0.5);
    cout<<A.multiply(2);

    return 0;
}