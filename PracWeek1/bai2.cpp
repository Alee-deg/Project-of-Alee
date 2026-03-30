#include<iostream>
using namespace std; 

int GCD(int a, int b){
    if(a % b == 0){
        return b; 
    }
    return GCD(b, a % b); 
}

int main(){
    cout << "Enter FractionA\n"; 
    int numeratorA; cin >> numeratorA; 
    int denominatorA; cin >> denominatorA; 
    cout << "Enter FractionB\n"; 
    int numeratorB; cin >> numeratorB; 
    int denominatorB; cin >> denominatorB; 
    int lcm = (denominatorA*denominatorB) / GCD(denominatorA, denominatorB); 
    int temp1 = lcm / denominatorA; 
    int temp2 = lcm / denominatorB; 
    if(numeratorA*temp1 > numeratorB*temp2){
        cout << numeratorA << "/" << denominatorA << " " << "is greater than "<< numeratorB << "/" << denominatorB << endl; 
    }
    else{
        cout << numeratorA << "/" << denominatorA << " " << "is lower than or equal "<< numeratorB << "/" << denominatorB << endl; 
    }
    return 0; 
}
