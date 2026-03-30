#include<iostream>
using namespace std;
class circle{
    private:
    float R; 
    public:
    circle(int r){
        R = r; 
    }
    float calArea(){
        return R*3.14;  
    }
    float calPerimeter(){
        return 2*3.14*R; 
    }
}; 

int main(){
    circle h1(5); 
    cout << h1.calArea() << "\n"; 
    circle h2(2); 
    cout << h2.calPerimeter() << "\n"; 
    return 0; 
}