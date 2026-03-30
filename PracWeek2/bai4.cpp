#include<iostream>
#include<string>
using namespace std; 

class average{
    float score; 
    public:
    average(float score){
        this -> score = score; 
    }
    string Achive(){
        if(0 <= score && score < 5){
            return "Yeu"; 
        }
        else if(5 <= score && score < 7){
            return "Tb"; 
        }
        else if(7 <= score && score < 8){
            return "Kha"; 
        }
        else if(8 <= score && score < 9){
            return "Gioi"; 
        }
        else if(9 <= score && score <= 10){
            return "Xs"; 
        }
        else{
            return "Du lieu dau vao khong hop le!"; 
        }
    }
}; 

int main(){
    average hs1(9.8); 
    cout << hs1.Achive() << endl; 
    return 0; 
}