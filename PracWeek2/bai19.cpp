#include<iostream>
using namespace std; 

class cal{
    public:
    int GCD(int a, int b){
        if(a % b == 0){
            return b; 
        }
        return GCD(b, a % b); 
    }
    int LCM(int a, int b){
        return a * b / GCD(a, b); 
    }
    void menu(); 
}; 

void cal::menu(){
    int choice;  
    do{
        std::cout << "\n====MENU\n"; 
        std::cout << "1.GCD\n2.LCM\n3.Quite\n"; 
        std::cout << "Enter Option\n";
        std::cin >> choice; 
        switch(choice){
            case 1:{
                int a, b; 
                std::cout << "Enter a and b\n"; 
                std::cin >> a >> b; 
                std::cout << "GCD of a and b is: " << GCD(a, b) << endl; 
                break; 
            }
            case 2:{
                int a, b; 
                std::cout << "Enter a and b\n"; 
                std::cin >> a >> b; 
                std::cout << "LCM of a and b is: " << LCM(a, b) << endl; 
                break; 
            }
            case 3:{
                std::cout << "Quite\n"; 
                break; 
            }
            default:
                std::cout << "Invalid input\n"; 
        }
    }while(choice != 3); 
}

int main(){
    cal a; 
    a.menu(); 
    return 0; 
}