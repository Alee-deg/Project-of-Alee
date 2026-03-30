#include<iostream>
#include<deque>
using namespace std; 
int main(){
    deque<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    for(string car : cars){
        cout << car << " "; 
    } 
    cout << "\n"; 
    cout << cars[0] << "\n";
    cout << cars[1] << "\n";  
    cout << cars.at(3) << "\n"; 
    cout << cars.at(1) << "\n"; 
    cars.push_back("Tesla"); 
    cars.push_front("VW"); 
    cars.pop_back(); 
    cars.pop_front(); 
    for(string car : cars){
        cout << car << " "; 
    }
    cout << "\n"; 
    return 0; 
}
