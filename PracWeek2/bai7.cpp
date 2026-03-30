#include<iostream>
class exchange{
    int mon; 
    public:
    exchange(){
        int money; std::cin >> money; 
        this -> mon = money; 
    }
    int *cal(int *Mo){
        int *cnt = new int[5]; 
        int Mon = this -> mon; 
        for(int i = 0; i < 4; i ++){
            int ex = Mon / Mo[i]; 
            Mon %= Mo[i]; 
            cnt[i] = ex; 
        }
        cnt[4] = Mon; 
        return cnt; 
    }
    void display(int *Mo){
        std::cout << Mo[0] << "*500k + " << Mo[1] << "*200k + " << Mo[2] << "*100k + " << Mo[3] << "*50k + " << Mo[4] << "k" << std::endl;  
    }
};

int main(){
    int Mo[4] = {500, 200, 100, 50}; 
    exchange mon; 
    int* cl = mon.cal(Mo);
    mon.display(cl); 
    return 0; 
}