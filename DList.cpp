#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;
class List{

    private:

    struct Node{
        int value;
        Node* next;
        Node* prev;
        Node(int val, Node* next = NULL, Node* prev = NULL){
            value = val, this->next = next, this->prev = prev;
        }

    };
    Node* head;
    Node* tail;
    void Delete(Node*& node);
    public:
    void task2();
    int len = 0;
    void print();
    List();
    ~List();
    bool Task();
    void Add(int num, int index);

    
};
void List::task2(){
    int mx = max(head->value, tail->value);
    int mn = min(head->value, tail->value);
    Node* front = this->head->next;
    Node* back = this->tail->prev;
    while (front->prev != back->next && (front != back->next && front->prev != back))
    {
        mx = max(front->value, mx);
        mn = min(front->value, mn);
        mx = max(back->value, mx);
        mn = min(back->value, mn);
        front = front->next;
        back = back->prev;
    }
   
    Node* temp = this->tail;
    this->tail = new Node(mx, NULL, temp);
    temp->next = this->tail;
    temp = this->head;
    this->head = new Node(mn, temp);
    temp->prev = this->head;
}
void List::print(){
    cout << "[ ";
    Node* current = head;
    while(current != NULL){
        cout << current->value << " ";
        current = current->next;
    }
    cout << "]\n";

}
List::List(){
    head = NULL;
    tail = NULL;

}
List::~List(){
    while(head != NULL && tail != NULL){
        Delete(head);
        Delete(tail);
    }
    
}
void List::Delete(Node*& node){
    Node* temp = node;
    node = temp->next;       
    delete temp;
}
void List::Add(int val, int index){
    if(index == 0){
        this->head = new Node(val, head, NULL);
        if (len == 0){
            this->tail = this->head;
        }
        this->len++;
        return;
    }
    if(index == len){
        Node* temp = this->tail;
        
        this->tail = new Node(val, NULL, temp);
        temp->next = this->tail;
        this->len++;
        return;
    }
    Node* current = head;
    int i = 0;
    
    while(i != index-1 && current != NULL){
        i++;
        current = current->next;
    }
    Node* temp = new Node(val, current->next, current);
    current->next = temp;
    temp->next->prev = temp;

    this->len++;

};

bool List::Task(){
   
    Node* front = this->head;
    Node* back = this->tail;
    while (front->next != back->prev)
    {
        if (front->value != back->value){
            return false;
        }
        else {
            front = front->next;
            back = back->prev;
        }
        
    }
    return true;



};

int main(){
    List list;
    list.Add(2, 0);
    list.Add(3, 1);
    list.Add(5, 1);
    list.Add(10, 1);
    list.Add(20, 1);
    list.Add(1, 2);
    list.task2();
    list.print();
    
    list.~List();
    return 0;

}
