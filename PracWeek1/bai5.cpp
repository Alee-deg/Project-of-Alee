#include<iostream>
#include<string>
using namespace std; 
struct student{
    string name; 
    int coreMath; 
    int coreLit; 
}; 
int main(){
    student a; 
    cout << "Enter name of Student\n"; 
    getline(cin, a.name);  
    cout << "Enter core Math\n"; 
    cin >> a.coreMath;  
    cout << "Enter core Liture\n"; 
    cin >> a.coreLit;  
    cout << a.name << "\n"; 
    cout << "Average: " << (a.coreMath + a.coreLit) / 2 << "\n"; 
    return 0; 
}