#include<iostream>
using namespace std; 
int GCD(int a, int b){
    if(a % b == 0){
        return b; 
    }
    return GCD(b, a % b); 
}
int main(){
    cout << "Enter numerator\n"; 
    int numerator; cin >> numerator; 
    cout << "Enter Denominator\n"; 
    int Denominator; cin >> Denominator; 
    int gcd = GCD(numerator, Denominator); 
    numerator /= gcd; 
    Denominator /= gcd; 
    cout << numerator << "/" << Denominator << "\n"; 
    return 0; 
}