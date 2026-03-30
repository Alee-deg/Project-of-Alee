#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std; 
int main(){
    set<string> cars = {"Volvo", "BMW", "Ford", "Mazda"}; 
    cars.insert("Tesla");
    cars.insert("VW"); 
    cars.insert("Toyota"); 
    cars.erase("BMW"); 
    cout << cars.size() << "\n"; 
    for(string car : cars){
        cout << car << " "; 
    }
    cout << "\n"; 
    map<string, int> people = {{"John", 32},{"Adele", 45}, {"Bo", 29}}; 
    cout << "John is: " << people["John"] << "\n"; 
    cout << "Adele is: " << people["Adele"] << "\n"; 
    people["Jenny"] = 22; 
    people["Liam"] = 24; 
    people["Kasper"] = 20; 
    people.insert({"Anja", 30}); 
    people.erase("John"); 
    cout << people.size() << "\n"; 
    for(auto person : people){
        cout << person.first << " is: " << person.second << "\n"; 
    }
    vector<string> carsV = {"Volvo", "BMW", "Ford", "Mazda"}; 
    vector<string>::iterator it; 
    for(it = carsV.begin(); it != carsV.end(); ++it){
        cout << *it << "\n"; 
    }
    for(auto s = carsV.begin(); s != carsV.end(); ++s){
        cout << *s << "\n"; 
    }
    map<string, int> peoples = {{"John", 32}, {"Adele", 45}, {"Bo", 29}}; 
    for (auto it = peoples.begin(); it != peoples.end(); ++it){
        cout << it -> first << " is: " << it -> second << "\n"; 
    }
    vector<int> numbers = {1, 7, 3, 5, 9, 2}; 
    sort(numbers.begin(), numbers.end()); 
    for(int num : numbers){
        cout << num << " "; 
    }
    cout << "\n"; 
    auto its = upper_bound(numbers.begin(), numbers.end(), 3); 
    cout << *its << "\n"; 
    return 0; 
}