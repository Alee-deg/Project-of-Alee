#include<iostream>

class Cal{
    public:
    float msum(float a, float b){
        return a + b; 
    }
    float sub(float a, float b){
        return a - b; 
    }
    float product(float a, float b){
        return a * b; 
    }
    float divide(float a, float b){
        if(b == 0){
            std::cout << "Invalid input \n"; 
            return -1; 
        }
        return a / b; 
    }

    void menu(); 
}; 

void Cal::menu(){
        int choice; 
        do{
            std::cout << "\n=====MENU=====\n"; 
            std::cout << "1.+\n2.-\n3.*\n4.:\n"; 
            std::cout << "Enter option: "; 
            std:: cin >> choice; 
            switch(choice){
                case 1:{
                    float a, b; 
                    std::cout << "Nhap a va b\n"; 
                    std::cin >> a >> b; 
                    std::cout << "Sum of two number is: " << msum(a, b) << std::endl; 
                    break; 
                }
                case 2:{
                    float a, b; 
                    std:: cout << "Enter a and b\n"; 
                    std:: cin >> a >> b; 
                    std:: cout << "Substraction of two number is: " << sub(a, b) << std::endl; 
                    break; 
                }
                case 3:{
                    float a, b; 
                    std:: cout << "Enter a and b\n"; 
                    std:: cin >> a >> b; 
                    std:: cout << "Product of two number is: " << product(a, b) << std::endl; 
                    break; 
                }
                case 4:{
                    float a, b; 
                    std:: cout << "Enter a and b\n"; 
                    std:: cin >> a >> b; 
                    std:: cout << "Divide of two number is: " << divide(a, b) << std::endl;
                    break; 
                }
                case 0:
                    std:: cout << "Quite" << std::endl;
                    break; 
                default:
                    std::cout << "Input not valid\n";  
            }
        }while(choice != 0); 
}

int main(){
    Cal c; 
    c.menu(); 
    return 0; 
}