#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node* next;
};
struct Stack {
    Node* head = nullptr;
    int size = 0;
};

void push(Stack& q, char a)
{
    Node* new_node = new Node;
    new_node->data = a;
    new_node->next = q.head;
    q.head = new_node;
    q.size++;
}

void pop(Stack& q) {
    Node* delete_node = q.head;
    q.head = delete_node->next;
    delete delete_node;
    q.size--;
}

char top(Stack& q) {
    return q.head->data;
}
void print(Stack& q1, Stack& q2)
{
    while(q1.size != 0)
    {
        push(q2, top(q1));
        cout<<top(q1)<<" ";
        pop(q1);
    }
    cout<<endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    Stack q1, q2;
    cout << "Введите количество элементов в стеке: ";
    cin >> n;

    for (int i = 0; n > i; i++) {
        cout << "Вводите элементы стека: ";
        char a;
        cin >> a;
        push(q1, a);
    }
    cout << "Стек: ";
    print(q1,q2);
    cout << "Введите ключ для удаления: ";
    char key;
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (top(q2) == key) {
            pop(q2);
    }
        else {
            push(q1, top(q2));
            pop(q2);
    }
    }
    cout << "Стек после удаления: ";
    print(q1, q2);
    cout << "Введите количество новых элементов: ";
    int k, s;
    cin >> k;
    n = q2.size;
    for (int i = 0; i < n; i++) {
        push(q1, top(q2));
        pop(q2);
   
    }
    cout << "Вводите новые элементы для добавление в начало стэка: ";
    for (int i = 0; i < k; i++) {
        char a;
        cin >> a;
        push(q1, a);
    }
    while (q2.head != nullptr) {
        push(q1, top(q2));
        pop(q2);
    }
    cout << "Стек после добавления: ";
    print(q1, q2);

    }