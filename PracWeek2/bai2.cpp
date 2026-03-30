#include<iostream>
using namespace std; 

class rectangle{
    private:
    float width; 
    float length; 
    public:
    rectangle(){
        cout << "Enter width\n"; 
        float wid; cin >> wid; 
        cout << "Enter length\n"; 
        float len; cin >> len; 
        width = wid; 
        length = len; 
    }
    float calArea(); 
    float calPerimeter();
}; 
float rectangle :: calArea(){
    return width*length; 
}
float rectangle :: calPerimeter(){
    return 2*(width + length); 
}

int main(){
    rectangle a; 
    cout << a.calArea() << "\n"; 
    cout << a.calPerimeter() << "\n"; 
    return 0; 
}