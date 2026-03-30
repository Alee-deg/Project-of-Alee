#include<iostream>
#include<string>

class vowels{
    char vow; 
    public:
    void input(){
        char v; std::cin >> v; 
        this -> vow = v; 
    }
    int inspect(){
        if(vow == 'a' || vow == 'e' || vow == 'i' || vow == 'o' || vow == 'u'){
            return 1; 
        }
        return 0; 
    }
    void display(){
        std::cout << vow << std::endl; 
    }
}; 

int main(){
    vowels v; 
    v.input(); 
    while(!v.inspect()){
        std::cout << "Enter again" << std::endl; 
        v.input(); 
    }
    v.display(); 
    return 0; 
}