#include <iostream>
#include <cstdlib>

using namespace std;

struct Point{
        int x;
        int y;
        friend istream &operator>>(istream &in, Point& p){
            in >> p.x;
            in >> p.y;
            return in;
        }
        friend ostream &operator<<(ostream &out, Point& p){
            out << "(" << p.x << ", " << p.y << ")";
            return out;
        }
    };
class Rect{
    
    private:
    Point pts[4];
    
    public:
    
    Rect(Point array[]);
    Rect();
    friend istream &operator>>(istream &in, Rect& r){
        for (size_t i = 0; i < 4; i++)
        {
            in >> r.pts[i];
        }
        

        return in;
    }
    friend ostream &operator<<(ostream &out, Rect& r){
        for (size_t i = 0; i < 4; i++)
        {
            out << r.pts[i] << "\t";
        }
        

        return out;
    }
    Rect operator+(Point a){
        Point newpts[4];
        for (size_t i = 0; i < 4; i++)
        {
            newpts[i].x = this->pts[i].x + a.x;
            newpts[i].y = this->pts[i].y + a.y;
        }
        
        return Rect(newpts);
    }
    Rect operator!(){
        Point c;
        c.x = (pts[1].x + pts[0].x)/2;
        c.y = (pts[1].y + pts[3].y)/2;
        Point newpts[4];
        for (size_t i = 0; i < 4; i++)
        {
            int tmpX = pts[i].x;
            int tmpY = pts[i].y;
            newpts[i].x = (tmpY - c.y) + c.x;
            newpts[i].y = -(tmpX - c.x) + c.y;

        }
        
        return Rect(newpts);
    };
};
Rect::Rect(Point *array){
    for (size_t i = 0; i < 4; i++)
    {
        pts[i] = array[i];
    }
    
};
Rect::Rect(){
    for (size_t i = 0; i < 4; i++)
    {
        pts[i].x = 0;
        pts[i].y = 0;
    }
    
};

int main(){
    Rect a;
    cin >> a;
    Rect b;
    b = !a;
    Point g;
    cin >> g;
    Rect c = a + g;
    cout << a << "\n";
    cout << b;
    cout << c;
}