#include <iostream>
#include <cstdlib>
#include <list.cpp>

using namespace std;


class Set{
    List set;

    public:
    Set();
    ~Set();
    friend istream &operator>>(istream& in, Set& s){
        int x;
        in >> x;
        for (int i = 0; i < x; i++)
        {
            int elem;
            in >> elem;
            s.set.push_back(elem);
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, Set s){
        cout << "{ ";
        for (int i = 0; i < s.set.size() - 1; i++)
        {
            cout << s.set.
        }
        
    }
}

int main(){

}