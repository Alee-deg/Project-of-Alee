#include<iostream>
#include<string>

class exchange{
    int month; 
    int year; 
    public:
    exchange(int a=1, int b=0){
        if(a >= 1 && a <= 12 && b >= 0){
            month = a; 
            year = b; 
        }
        else{
            std::cout << "Error" << std::endl;
        } 
    }
    int cal(){
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            switch (month)
            {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31; 
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return 28; 
            }
        }
        else{
            switch(month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31; 
            case 4: case 6: case 9: case 11:
                return 30; 
            case 2:
                return 29; 
            }
        }
        return -1; 
    }
    void display(){
        std::cout << month << " " << year << std::endl; 
    }
}; 
int main(){
    exchange a(2, 2029);
    a.display();
    std::cout << a.cal() << std::endl;  
    return 0; 
}