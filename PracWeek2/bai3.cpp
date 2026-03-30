#include<iostream>
using namespace std; 

class arr{
    private:
    int a; 
    int b; 
    int c; 
    public:
    arr(int A, int B, int C){
        a = A; 
        b = B; 
        c = C; 
    }
    void display(); 
    int min(); 
};

void arr::display(){
    cout<<a<< " " <<b<< " "<<c<<endl;
}

int arr::min(){
    if(a <= b && a <= c){
        return a; 
    }
    if(b <= a && b <= c){
        return b; 
    }
    if(c <= a && c <= b){
        return c; 
    }
    return 0; 
}

int main(){
    arr a(2, 5, 1);
    a.display();
    cout << a.min() << endl;  
    return 0; 
}