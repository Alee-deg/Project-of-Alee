#include<iostream>

class solve{
    float a; 
    float b; 
    public:
    solve(float a, float b){
        this -> a = a; 
        this -> b = b; 
    }
    void cal(); 
}; 

void solve::cal(){
    if(a == 0 && b == 0){
        std::cout << "The equation has infinitely many solutions\n"; 
    }
    else if(a == 0 && b != 0){
        std::cout << "The equation not has solution\n"; 
    }
    else{
        std::cout << "The equation has a unique solution: " << -b / a << std::endl; 
    }
}

int main(){
    solve q(0, 0); 
    q.cal(); 
    return 0; 
}