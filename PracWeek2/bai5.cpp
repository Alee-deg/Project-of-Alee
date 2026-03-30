#include<iostream>
#include<string.h>

using namespace std; 

class inspect{
    string username; 
    string password; 
    int count = 0; 
    public:
    inspect(){
        username = "Haule"; 
        password = "Haule@123"; 
    }
    string input(); 
}; 
string inspect::input(){
    string name, password; 
    getline(cin, name); 
    getline(cin, password);
    while(count < 2){
        if(this -> username == name && this -> password == password){
            return "username"; 
        }
        else{
            getline(cin, name); 
            getline(cin, password);
        }
        count ++; 
    }
    if(this -> username == name && this -> password == password){
        return "username"; 
    }
    return "Error"; 
}

int main(){
    inspect a; 
    cout << a.input() << endl; 
    return 0; 
}