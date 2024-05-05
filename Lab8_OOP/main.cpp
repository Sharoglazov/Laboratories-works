#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>

using namespace std;

class Print {
protected:
    string title;
    string author;
public:
    Print() : title(""), author("") {}
    Print(string t, string a) : title(t), author(a) {}
    virtual ~Print() {}

    virtual void input() = 0;
    virtual void output() = 0;

    void setTitle(string t) {
        title = t;
    }

    string getTitle() const {
        return title;
    }

    void setAuthor(string a) {
        author = a;
    }
    
    string getAuthor() const {
        return author;
    }
};

class Book : public Print {
private:
    int numPages;
public:
    Book() : Print(), numPages(0) {}
    Book(string t, string a, int np) : Print(t, a), numPages(np) {}

    void input() override {
        cout << "Введите название: ";
        cin >> title;
        cout << "Укажите автора: ";
        cin >> author;
        cout << "Введите количество страниц: ";
        cin >> numPages;
    }

    void output() override {
        cout << "Название: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Количество страниц: " << numPages << endl;
    }
};

class Tree {
private:
    vector<Print*> elements;
public:
    Tree() {}

    void addElement(Print* p) {
        elements.push_back(p);
    }

    void removeElement(int index) {
        if (index >= 0 && index < elements.size()) {
            delete elements[index];
            elements.erase(elements.begin() + index);
        }
    }

    void showInfo() {
        for (Print* p : elements) {
            p->output();
        }
    }

    int getSize() const {
        return elements.size();
    }
    friend int main();
};

int main() {
    Tree group;

    char choice;
    int numElements;
    cout << "Введите количество элементов в группе: ";
    cin >> numElements;

    for (int i = 0; i < numElements; i++) {
        Book* mag = new Book();
        mag->input();
        group.addElement(mag);
    }

    do {
        cout << "МЕНЮ:" << endl;
        cout << "1. Добавить элемент в группе (+)" << endl;
        cout << "2. Удалить элемент из группы (-)" << endl;
        cout << "3. Показать информацию об элементах группы" << endl;
        cout << "4. Показать названия всех элементах группы" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            Book* mag = new Book();
            mag->input();
            group.addElement(mag);
            break;
        }
        case '2': {
            int index;
            cout << "Введите индекс элемента для удаления: ";
            cin >> index;
            group.removeElement(index);
            break;
        }
        case '3':
            group.showInfo();
            break;
        case '4':
            for (Print* p : group.elements) {
                cout << p->getTitle() << endl;
            }
            break;
        case '5':
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова" << endl;
        }

    } while (choice != '5');

    return 0;
}