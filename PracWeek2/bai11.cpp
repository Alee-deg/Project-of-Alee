#include<iostream>
#include<string>

class student{
    static float standardScore; 
    float scoreA; 
    float scoreB; 
    float scoreC; 
    char area; 
    char character; 
    public:
    student(float scoreA, float scoreB, float scoreC, char ar, char chracter){
        this -> scoreA = scoreA; 
        this -> scoreB = scoreB; 
        this -> scoreC = scoreC; 
        this -> area = ar; 
        this -> character = chracter; 
    }
    float are(char a){
        switch(a){
            case 'A':
                return 1.5; 
            case 'B':
                return 1; 
            case 'C':
                return 0.5; 
        }
        return -1; 
    }
    float chara(char a){
        switch(a){
            case '1':
                return 1.5; 
            case '2':
                return 1; 
            case '3':
                return 0.5;    
        }
        return -1; 
    }
    void result(){
        if(scoreA == 0 || scoreB == 0 || scoreC == 0){
            std::cout << "False" << std::endl; 
            return; 
        }
        if((scoreA + scoreB + scoreC + are(area) + chara(character)) < standardScore){
            std::cout << "False" << std::endl; 
        }
        else{
            std::cout << "You are grateduated" << std::endl; 
        }
    }
}; 

float student::standardScore = 17; 
int main(){
    student a(10, 2, 3, 'A', '1'); 
    a.result(); 
    return 0; 
}