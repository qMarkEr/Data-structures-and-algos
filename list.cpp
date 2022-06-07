#include <iostream>
#include <cstdlib>

using namespace std;
class List{

    private:

    struct Node{
        int value;
        Node* next;
        Node(int val, Node* next = NULL){
            value = val, this->next = next;
        }
    };
    int len = 0;
    Node* head;
    void Delete(Node*& node);
    public:
    int Size();
    void print();
    List();
    ~List();
    void Task();
    void Add(int num, int index);

    
};
int List::Size(){
    return len;
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

}
List::~List(){
    while(head != NULL){
        Delete(head);
    }
    
}
void List::Delete(Node*& node){
    Node* temp = node;
    node = temp->next;
    len--;
    delete temp;
}
void List::Add(int val, int index){
    if(index == 0){
        this->head = new Node(val, head);
        len++;
        return;
    }
    Node* current = head;
    int i = 0;
    
    while(i != index-1 && current != NULL){
        i++;
        current = current->next;
    }
    current->next = new Node(val, current->next);
    len++;

};

void List::Task(){
    int i = 0;
    int min = 1000000;
    int max = 0;
    Node* current = head;
    while (current->next != NULL){
        if (current->value > max){
            max = current->value;
            i++;
        }
        if (current->value < min){
            min = current->value;
        }
        current = current->next;
        
    }
    this->Add((max+min)/2, i);



};

int main(){
    List list;
    list.Add(1, 0);
    list.Add(2, 1);
    list.Add(14, 2);
    list.Add(54, 3);
    list.Add(11, 4);
    list.Add(8, 5);
    cout << list.Size();
    list.Task();
    list.print();
    list.~List();
    return 0;

}
