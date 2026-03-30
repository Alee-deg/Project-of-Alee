#include<iostream>
using namespace std; 
class PT1{
    private:
    int a; 
    int b; 
    public:
    PT1(int a, int b){
        this -> a = a; 
        this -> b = b; 
    }
    int solve(){
        return -(this -> b) / (this -> a); 
    }
}; 

int main(){
    PT1 g(1, 2);
    cout << g.solve() << endl;  
    return 0; 
}