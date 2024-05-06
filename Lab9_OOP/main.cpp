#include<string>
#include <iostream>
#include <vector>
using namespace std;

class Error{
protected:
    string msg;
public:
    virtual void what(){};
};

class IndexError:public Error{
protected:
    string msg;
public:
    IndexError(){msg="Index Error\n";}
    virtual void what(){cout<<msg;}
};

class Index_min_error:public IndexError{
protected:
    string msg_;
public:
    Index_min_error(){IndexError();msg_="Index<MinIndex\n";}
    virtual void what(){cout<<msg<<msg_;}
};
class Index_max_error:public IndexError{
protected:
    string msg_;
public:
    Index_max_error(){IndexError();msg_="Index>MaxIndex\n";}
    virtual void what(){cout<<msg<<msg_;}
};
class size_error:public Error{
protected:
    string msg;
public:
    size_error(){msg="Index Error\n";}
    virtual void what(){cout<<msg;}
};
class error_empty :public size_error
{
protected:
    string msg_;
public:
    error_empty(){size_error();msg_ = "empty list";}
    virtual void what(){cout<<msg<<msg_;}
};

class error_diff_size :public size_error
{
protected:
    string msg_;
public:
    error_diff_size(){size_error();msg_= "Different size of list";}
    virtual void what(){cout<<msg<<msg_;}
};


struct Node {
public:
    int data;
    Node* next;
    Node* prev;

};


class List {
private:
    int size;
    Node* head;
    Node* tail;
    friend ostream& operator<<(ostream& out, const List& list);
    friend istream& operator >> (istream& in, const List& list);
public:
    List() : size(0), head(nullptr),tail(nullptr) {}
    void push_back(int data){
        Node* new_node = new Node;
        new_node->data=data;
        new_node->next=nullptr;
        if(this->head==nullptr)
        {
            this->head=new_node;
            this->tail=new_node;

        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail=new_node;
        }
        this->size++;
    }
    void push_front(int data){
        Node* new_node = new Node;
        new_node->data=data;
        if(this->head==nullptr)
        {
            this->head=new_node;
            this->tail=new_node;
            this->size++;

        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head=new_node;
            this->size++;

        }

    }
    int front(){
        return this->head->data;
    }
    int back(){
        return this->tail->data;
    }
    int pop_back(){
        int temp;
        if(this->tail!=nullptr){
            Node * current_node= this->tail;
            tail=current_node->prev;
            temp=current_node->data;
            tail->next=nullptr;
            this->size--;
        }
        return temp;
    }
    int pop_front(){
        int temp;
        if(this->head!=nullptr){
            Node * current_node= this->head;
            head=current_node->next;
            temp=current_node->data;
            head->prev=nullptr;
            this->size--;
        }
        return temp;
    }
    bool is_empty(){
        return this->size==0;
    }
    List& operator = (const List& list){
        cout<<"Operator ="<<endl;
        if(this == &list){
            return *this;
        }
        while (head!=nullptr){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        size =0;
        Node* current_node=list.head;
        while(current_node!=nullptr){
            push_back(current_node->data);
            current_node=current_node->next;
        }
        return *this;
    }
    int& operator [](int index){
        if (index < 0) throw Index_min_error();
        if (index >= size) throw Index_max_error();
        if(index <this->size&&index>=0){
            Node* current_node = this->head;
            for(int i=0;i!=index;i++){
                current_node=current_node->next;
            }
            return current_node->data;
        }
        else{
            cerr<<"index out of range";
            exit(0);
        }
    }
    int operator-(int h) {
    if (h < 0) throw Index_min_error();
    if (h >= size) throw Index_max_error();

    Node* c = head;
    while (c->next != nullptr) {
        c = c->next;
    }

    for (int i = 0; i < h; ++i) {
        c = c->prev;
    }

    return c->data;
}
    int operator () (){
        if(size==0)throw error_empty();
        return this->size;
    }
    List operator * (List& list){
        if (this->size != list.size)
        {
            throw error_diff_size();
        }
        int temp_size;
        if(this->size>list.size){
            temp_size=list.size;
        }
        else
        {
            temp_size=this->size;
        }
        List temp(temp_size,0);
        for(int i=0;i<temp_size;i++){
            temp[i]=(*this)[i]*list[i];
        }
        return temp;
    }

    List(int size, int data){
        this->size=size;
        if(size>0){
            Node* node = new Node;
            node->data=data;
            this->head=node;
            this->tail=node;
            for(int i=1;i<size; i++){
                Node* newNode = new Node;
                newNode->data=data;
                tail->next = newNode;
                newNode->prev = tail;
                tail=newNode;
            }
            tail->next=nullptr;
        }
        else
        {
            this->head=nullptr;
            this->tail=nullptr;
        }

    }
    List(const List& list)
    {
        this->head=nullptr;
        this->tail=nullptr;
        this->size=0;
        Node* current_node=list.head;
        while(current_node!=nullptr){
            push_back(current_node->data);
            current_node=current_node->next;
        }

    };
    List(int size){
        this->size=size;
        if(size>0){
            Node* node = new Node;
            this->head=node;
            this->tail=node;
            for(int i=1;i<size; i++){
                Node* newNode = new Node;
                tail->next = newNode;
                newNode->prev = tail;
                tail=newNode;
            }
            tail->next=nullptr;
        }
        else
        {
            this->head=nullptr;
            this->tail=nullptr;
        }

    };
    ~List()
    {
        Node* current_node=head;
        while(current_node!=nullptr){
            Node* next=current_node->next;
            delete current_node;
            current_node=next;
            }
        head=nullptr;
    };


};
    ostream& operator<<(ostream& out, const List& list){
        out <<endl<< "Elements of list"<<endl;
        Node* current_node = list.head;
        while (current_node!=nullptr)
        {
            out<<current_node->data<< " ";
            current_node=current_node->next;
        }
        out<<endl<<"conclusion end"<<endl;
        return out;
    }
    istream& operator >> (istream& in, const List& list){

        cout<<endl<<"Enter element of list"<<endl;
        Node* current_node=list.head;
        while (current_node!=nullptr){
            in>>current_node->data;
            current_node=current_node->next;
        }
        cout<<endl<<"Enter element stop"<<endl;
        return in;
    }


int main(){

    List sp1, sp2;
    int count, x, index,h;
    cout << "Enter element count: ";
    cin >> count;
    try
    {
        if (count < 1) throw error_empty();
        cout << "Enter element of list: ";
        for (int i = 0; i < count; ++i)
        {
            cin >> x;
            sp1.push_back(x);
        }
        cout << "Enter index of list number 1 for calling: ";
        cin >> index;
        cout << "Enter element with this index: " << sp1[index] << endl;
        cout << "Enter index one of the left element of list sp1: ";
        cin >> h;
        cout << "element with this index: " << sp1-h << endl;
        cout << "Size of lsit : " << sp1() << endl;
        cout << "Enter count of element of list number 2: ";
        cin >> count;
        if (count < 1) throw error_empty();
        cout << "Enter element of list: ";
        for (int i = 0; i < count; ++i)
        {
            cin >> x;
            sp2.push_back(x);
        }
        sp1* sp2;
        cout << "List obtained by multiplying two lists: ";
        cout<<sp1<<endl;

    }
    catch (Error& a)
    {
        a.what();
    }
    return 0;
}