#include<iostream>
#include<list>
using namespace std; 
int main(){
    list<string> cars = {"Volvo", "BMW", "Ford", "Mazda"}; 
    for(string car : cars){
        cout << car << "\n"; 
    }
    cout << cars.front() << "\n"; 
    cout << cars.back() << "\n"; 
    cars.front() = "Opel"; 
    cars.back() = "Toyota"; 
    cars.push_front("Tesla");
    cars.push_back("VW"); 
    cars.pop_front(); 
    cars.pop_back(); 
    for(string car : cars){
        cout << car << " "; 
    }
    cout << "\n";
    cout << cars.size() << "\n"; 
    cout << cars.empty() << "\n"; 
    return 0; 
}