#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
class Tree{
    struct Node{
        int info;
        int depth;
        Node* left;
        Node* right;
        Node(int num, int d){
            info = num;
            left = NULL;
            right = NULL;
            depth = d;
        }
        

        
    };
    Node* root;
    void Destroy(Node* n);
    void Add(int num, Node*& node, int& d);
    int Task(Node* node, int depth);
    void Print(Node* n);
    void Task2(Node* n, int& mn, bool& x);
    int Depth(Node* n);

    public:
    void Task3();
    void Task2();
    void Add(int num);
    void Print();
    Tree();
    int Task(int depth);
    
    ~Tree();


};
void Tree::Task3(){
    int elem = Depth(root);
    this->Add(elem);
}
int Tree::Depth(Node* n){
    if (n == NULL)
    {
        return 0;
    }

    return 1 + max(Depth(n->right), Depth(n->left));
    
}
void Tree::Task2(){
    Node* r = root;
    bool x = false;
    int b = INT_MAX;
    Task2(root, b, x);
    cout << x;
    
}
void Tree::Task2(Node* n, int& mn, bool& x){
    if (x)
    {
        return;
    }
    if (n == NULL){ 
        return;
    }
    if (mn == n->info)
    {
        x = true;
        return;
    }
    mn = min(n->info, mn);
    
    Task2(n->left, mn, x);
    mn = n->info;
    Task2(n->right, mn, x);
}

void Tree::Add(int num){
    int d = 0;
    Add(num, root, d);
}

void Tree::Add(int num, Node*& node, int& d){
    if (node == NULL)
    {
        node = new Node(num, d+1);
        return;
    }

    if (node->info > num)
    {
        Add(num, node->left, node->depth);
    } else {
        Add(num, node->right, node->depth);
    }
}


Tree::Tree(){
    root = NULL;
}
Tree::~Tree(){
    Destroy(root);
    
}
int Tree::Task(int depth){
    return Task(root, depth);


}
int Tree::Task(Node* node, int depth){
    if (node == NULL)
    {
        return 0;
    }
    if (node->depth == depth)
    {
        return 1;
    }
    return Task(node->left, depth) + Task(node->right, depth);
    
    
}
void Tree::Destroy(Node* n){
    if (n != NULL)
    {
        Destroy(n->left);
        Destroy(n->right);

        delete n;
    }
    
}
void Tree::Print(Node* n){
    if (n==NULL){ 
        return;
    }
    Print(n->left);

    cout<< " " << (n->info) << " ";

    Print(n->right);
}
void Tree::Print(){
    Print(root);
}

int main(){
    Tree a;
    int ae[] = {8, 7, 5, 6};
    for (int i = 0; i < 4; i++)
    {
        a.Add(ae[i]);
    }
    a.Task3();
    a.Print();
    a.Task2();
    
}