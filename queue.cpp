#include<iostream>
#include<queue>
using namespace std; 
int main(){
    queue<string> cars; 
    cars.push("Volvo"); 
    cars.push("BMW"); 
    cars.push("Ford"); 
    cars.push("Mazda"); 
    cout << cars.front() << "\n"; 
    cars.pop(); 
    cout << cars.front() << "\n"; 
    cout << cars.back() << "\n"; 
    cout << cars.size() << "\n"; 
    return 0; 
}