#include<iostream>
#include<vector>
#include<algorithm>

class exchange{
    int number; 
    public:
    exchange(){
        int num; std::cin >> num; 
        this -> number = num; 
    }
    std::vector<int> cal(){
        std:: vector<int> binary; 
        int num = number; 
        while(num){
            int ex = num % 2; 
            binary.push_back(ex); 
            num /= 2; 
        }
        reverse(binary.begin(), binary.end()); 
        return binary; 
    }
    void display(std::vector<int> v){
        for(int x : v){
            std::cout << x; 
        }
        std::cout<< "\n"; 
    }
}; 

int main(){
    exchange v; 
    std::vector<int> bin = v.cal(); 
    v.display(bin); 
    return 0; 
}