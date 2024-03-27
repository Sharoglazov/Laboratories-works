#include <iostream>
#include <string>
using namespace std;

void createTable(string& pattern, int d[]) {
    int Len = pattern.length();

    for (int i = 0; i < 256; i++) {
        d[i] = Len;
    }

    for (int i = 0; i < Len-1; i++) {
        d[(unsigned char)pattern[i]] = Len - i - 1;
    }
}

void boyerMoore(string& text, string& pattern) {
    int patLen = pattern.length();
    int txtLen = text.length();
    int d[256];
    createTable(pattern, d);
    bool f = 0;
    for (int i = patLen - 1; i < txtLen; i+= d[(unsigned char)text[i]]) {
        int k = 0;
        while(k < patLen && pattern[patLen-1-k] == text[i-k]) {
            k++;
        }
        if (k == patLen) {
            cout<<"Образ найден по индексу " << i - patLen + 1<<endl;
            f = 1;
        }
    }

    if(!f) {
        cout<<"Образ не найден в строке" << endl;
    }
}

int main() {
    system("chcp 1251<null");
    string a, b;
    cout<<"Введите строку: ";
    getline(cin, a);
    cout<<"Введите образ для поиска: ";
    getline(cin, b);
    boyerMoore(a, b);
}