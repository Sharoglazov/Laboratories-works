#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
 
int main() {
    string s;
    cout<<"Введите строку: ";
    getline(cin, s);
    const int n = s.length();
    string a[n];
    int k = 0;
    stringstream  ss(s);
    while(ss >> s) {
        if(s[0] >= '0' && s[0] <= '9') {
            a[k] = s;
            k++;
        }
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k-i-1; j++) {
            if (a[j] < a[j+1]) {
                string temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}