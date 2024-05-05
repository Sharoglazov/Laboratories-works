#include <iostream>
using namespace std;

struct fraction {
    int first;
    double second;
    int k;
    double Sum;
    void Init(double, double, int);
    void Read();
    void Show();
    double multiply();
}; 

void fraction::Init(double F, double S, int num) {
    first = F;
    second = S;
    double Sum = first + second;
    k = num;
}

void fraction::Read() {
    cout<<"\nfirst: "; 
    cin>>first;
    cout<<"\nsecond: "; 
    cin>>second;
    cout<<"\nk: ";
    cin>>k;
}

void fraction::Show() {
    cout<<"\nfirst = "<<first;
    cout<<"\nsecond = "<<second;
    cout<<"\nSum = "<<Sum;
    cout<<"\nk = "<<k<<endl;
}

double fraction::multiply() {
    return Sum;
}


fraction make_fraction(double F, double S, int num) {
    fraction t;
    t.Init(F, S, num);
    return t;
}

int main() {
    fraction A;
    make_fraction(10, 0.5, 2);
    cout<<endl;
    double result = A.multiply();
    cout<<result;
    
    return 0;
}