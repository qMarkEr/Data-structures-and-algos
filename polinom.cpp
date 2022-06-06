#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
class Polynom{
    int* array;
    int n;
    public:
    void Print();
    Polynom(int* arr, int n);
    Polynom operator*(Polynom x);
    



};

void Polynom::Print(){
    int i = 0;
    cout << array[i] << "x^" << n - i - 1 << " ";
    for (i = 1; i < n-2; i++)
    {
        if (array[i] < 0)
        {
            cout << array[i] << "x^" << n - i -1 << " ";
        } else if (array[i] > 0)
        {
            cout << " + " << array[i] << "x^" << n - i -1 << " ";
        }
        
        
        
    }
    if (array[n-2] < 0)
        {
            cout << array[n-2] << "x ";
        } else if (array[n-2] > 0)
        {
            cout << " + " << array[n-2] << "x ";
        }
    if (array[n-1] < 0)
        {
            cout << array[n-1];
        } else if (array[n-1] > 0)
        {
            cout << " + " << array[n-1];
        }
}
Polynom::Polynom(int arr[], int n){
    array = arr;
    this->n = n;
}
Polynom Polynom::operator*(Polynom x){
    int* array = new int[this->n + x.n - 1];
    for (int i = 0; i < this->n + x.n - 1; i++)
    {
        array[i] = 0;
    }
    
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < x.n; j++)
        {
            array[i + j] += this->array[i] * x.array[j];
        }
        
    }
    return Polynom(array, this->n + x.n - 1);
    
}

int main(){
    int n = 3;
    int array[] = {1, -2, 4};
    int array2[] = {2, -4, 1, 2};
    Polynom p(array, n);
    Polynom p1(array2, 4);
    
    Polynom x = p*p1;
    x.Print();
}