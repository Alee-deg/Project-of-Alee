#include<iostream>
using namespace std; 
int main(){
    long long cnt = 0; 
    for(int i = 0; i < 1000000000;i ++){
        cnt += i; 
    }
    cout << cnt << endl; 
    return 0; 
}