#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class noVector {
    vector<pair<int, int>> lst;
    int n;


public:
    friend noVector operator+(noVector v1, noVector v2);
    friend istream& operator>>(istream& in, noVector& v) {
        in >> v.n;
        for (size_t i = 0; i < v.n; i++)
        {
            int coord;
            in >> coord;
            if (coord != 0)
            {
                v.lst.push_back(make_pair(coord, i));

            }
        }
        
        return in;
    };
    noVector(vector<pair<int, int>> a, int m);
    noVector();
    
    friend ostream& operator << (ostream& out, noVector& vec) 
{ 
    int t = 0; 
    out << "["; 
    for (size_t i = 0; i < vec.n; i++) 
    { 
        if(vec.lst[t].second == i) 
        { 
            out << vec.lst[t].first <<", "; 
            t++; 
        } 
        else 
        { 
            out << 0 << ", "; 
        } 
         
    } 
    out << "]"; 
    return out; 
}
};

noVector operator+(noVector v1, noVector v2) {
        vector<pair<int, int>> n;
        int j = 0;
        int i = 0;
        for (int k = 0; k < v1.n; k++)
        {
           
            
            if (v1.lst[i].second == v2.lst[j].second)
            {
                
                n.push_back(make_pair(v1.lst[i].first + v2.lst[j].first, v1.lst[i].second));
                j++;
                i++;
            }
            else if (v1.lst[i].second < v2.lst[j].second) {
                
                n.push_back(v1.lst[i]);
                i++;
            }
            else if (v1.lst[i].second > v2.lst[j].second){
                n.push_back(v2.lst[j]);
                j++;
            }

        }

        return noVector(n, v1.n);

    }
noVector::noVector(vector<pair<int, int>> a, int m) {
    n = m;
    lst = a;
}
noVector::noVector() {

};
int main() {

    noVector a;

    cout << "a" << endl;
    cin >> a;
    noVector b;
    cout << "b" << endl;
    cin >> b;
    noVector c = a + b;
    cout << c;


}