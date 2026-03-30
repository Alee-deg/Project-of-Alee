#include<iostream>
#include<string>
#include<vector>
using namespace std;  
int main(){
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
    cout << cars[0] << "\n"; 
    cout << cars[3] << "\n"; 
    cout << cars.back() << "\n";
    cout << cars.front() << "\n";  
    cout << cars.at(1) << "\n"; 
    cars[0] = "Opel"; 
    cars.push_back("Tesla"); 
    cars.pop_back(); 
    for(auto it = cars.begin(); it != cars.end(); ++it){
        cout << *it << " "; 
    }
    cout << "\n"; 
    cout << cars.size() << "\n"; 
    cout << cars.empty() << "\n"; 
    for(int i = 0;i < cars.size();i ++){
        cout << cars[i] << " "; 
    }
    cout << "\n"; 
    for(string car : cars){
        cout << car << " "; 
    }
    cout << "\n"; 
    return 0; 
}