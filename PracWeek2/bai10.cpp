#include<iostream>

class worker{
    std::pair<int,int> hStart; 
    std::pair<int, int> hLeft; 
    public:
    worker(int hS, int mS, int hL, int mL){
        if((hS >= 6 && hS <= 18) && (hL >= 6 && hL <= 18) && (hS < hL) && (0<=mS && mS <= 60) && (0<=mL
        && mL <= 60)){
            if(hS == hL){
                if(mS <= mL){
                    hStart.first = hS; 
                    hStart.second = mS; 
                    hLeft.first = hL; 
                    hLeft.second = mL; 
                }
            }
            else{
                hStart.first = hS; 
                hStart.second = mS; 
                hLeft.first = hL; 
                hLeft.second = mL; 
            }
        }
        else{
            std::cout << "Error"; 
        }
    }
    int cal(){
        if(hStart.first < 12 && hLeft.first < 12){
            return (hLeft.first*60 + hLeft.second - (hStart.first*60 + hStart.second))*100; 
        }
        if((hStart.first < 12 && hLeft.first == 12 && hLeft.second > 0)){
            return (hLeft.first*60 - (hStart.first*60 + hStart.second))*100 + hLeft.second*125; 
        }
        if((hStart.first == 12 && hLeft.first == 12 && hStart.second > 0)){
            return (hLeft.second - hStart.second)*125; 
        }
        if((hStart.first >= 12 && hLeft.first >= 12)){
            return (hLeft.first*60 + hLeft.second- (hStart.first*60 + hStart.second))*125; 
        }
        if((hStart.first < 12 && hLeft.first > 12)){
            return (12*60 - (hStart.first*60 + hStart.second))*100 + ((hLeft.first*60 + hLeft.second) - 12*60)*125; 
        }
        return -1; 
    }
}; 

int main(){
    worker a(6, 30, 13, 20); 
    std::cout << a.cal() << std::endl;
    return 0;  
}