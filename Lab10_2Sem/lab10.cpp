#include<iostream>
#include<string.h>
#include<string>
using namespace std;

string* deletefroma(string *a, int &N) { // Удаляет элемент, начинающийся и заканчивающийся на 'a'
    int count = 0;
    for (int i = 0; i < N; i++){
        int end_index = a[i].length() - 1;
        if ((a[i][0] == 'A' || a[i][0] == 'a') && (a[i][end_index] == 'A' || a[i][end_index] == 'a')) {
            string tmp = a[count]; 
            a[count] = a[i];
            a[i] = tmp;
            count++;          
        }
    }
    N = N - count;
    string *result = new string[N];
    for (int i = 0; i < N; i++)
        result[i] = a[i + count];
    
    return result;
    
}


int main(){
    setlocale(LC_ALL, "RU");
    system("chcp 1251>Null");
    int N = 0;
    cout<<"Enter the number of elements: ";
    while (N <= 0) cin>>N;
    cout<<endl;
    string *a = new string[N]; 
    for(int i = 0; i < N; i++){
        string fl = "";
        cout<<"Enter the element "<<i+1<<": ";
        while (fl == "") {
            getline(cin, fl);
        }
        a[i] = fl;
    }
    cout<<endl;
    for(int i = 0; i < N; i++){
        cout<<a[i]<<endl;
    }
    cout<<"____________________"<<endl;
    string *arr = deletefroma(a, N);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << endl;
    }
    delete[] arr;
    delete[] a;
    return 0;
}
