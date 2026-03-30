#include<iostream>
#include<stack>
using namespace std; 
int main(){
    stack<string> cars; 
    cars.push("Volvo"); 
    cars.push("BMW"); 
    cars.push("Ford"); 
    cars.push("Mazda"); 
    cout << cars.top() << "\n"; 
    cars.top() = "Tesla"; 
    cout << cars.top() << "\n"; 
    cars.pop(); 
    cout << cars.top() << "\n"; 
    cout << cars.size() << "\n"; 
    cout << cars.empty() << "\n"; 
    return 0; 
}