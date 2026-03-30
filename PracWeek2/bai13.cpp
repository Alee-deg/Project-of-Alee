#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std; 

class Game{
    public:
    int player; 
    int computer; 
    void play(){
        cout << "1. Keo\n2. Bua\n3. Bao\n"; 
        cout << "Nhap lua chon cua ban: "; 
        cin >> player; 

        computer = rand() % 3 + 1; 

        cout << "May chon: " << computer << endl; 
        
        if(player == computer){
            cout << "Hoa\n"; 
        }
        else if((player == 1 && computer == 3) ||
                (player == 2 && computer == 1) ||
                (player == 3 && computer == 2))
            cout << "Ban thang\n";
        else
            cout << "May thang\n";
    }
}; 

int main(){
    srand(time(0)); 

    Game g; 
    g.play(); 

    return 0; 
}