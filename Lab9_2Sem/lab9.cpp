
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string first_word = "";

int main() {
    ifstream fin;
    fin.open("f1.txt");
    string s;
    int k = 0;
    getline(fin, s);
    ofstream fout;
    fout.open("f2.txt");

    while (s[k] != ' ') {
            first_word += s[k];
            k++;
        }
    while (getline(fin, s)) {
        int i = 0;
        string word;
        bool flag = true;

        while(s[i]) {
            if (s[i] != ' ') {
                word += s[i];
            }
            else {
                if (word == first_word) {
                    flag = false;
                }
                word = "";
            }
            i++;
        }
        if (flag) {
            fout<<s<<endl;
        }
    }

    //второй пункт задания, определить количество гласных букв в первой строке f2

    ifstream f;
    f.open("f2.txt");
    int count = 0;
    string d;
    getline(f, d);
    for (int i = 0; i < d.length(); i++) {
        if (d[i] != 'a' && d[i] != 'A'
        && d[i] != 'e' && d[i] != 'E'
        && d[i] != 'i' && d[i] != 'I'
        && d[i] != 'o' && d[i] != 'O'
        && d[i] != 'u' && d[i] != 'U'
        && d[i] != 'y' && d[i] != 'Y'
        && isalpha(d[i])) {
            count++;
        }
    }
    cout<<d<<endl;
    cout<<"Number of consonants is: "<<count<<endl;

    return 0;
}