#include<iostream>
using namespace std; 
struct frac{
    int numerator; 
    int denominator;
}; 

int GCD(int a, int b){
    if(a % b == 0){
        return b; 
    }
    return GCD(b, a % b);
}

int LCM(int a, int b){
    return (a*b)/GCD(a, b); 
}

int compare(frac a, frac b){
    int lcm = LCM(a.denominator, b.denominator); 
    int temp1 = lcm / a.denominator; 
    int temp2 = lcm / b.denominator;
    if(a.numerator*temp1 >= b.numerator*temp2){
        return 1; 
    }
    return 0;  
}

void insertionSort(frac Frac[], int n){
    int j; 
    frac key; 
    for(int i = 1; i < n;i ++){
        key = Frac[i]; 
        j = i - 1; 
        while(j >= 0 && compare(Frac[j], key)){
            Frac[j + 1] = Frac[j]; 
            j --; 
        }
        Frac[++j] = key; 
    }
}
int main(){
    frac Frac[100];
    int n; cin >> n; 
    for(int i = 0; i < n; i ++){
        cin >> Frac[i].numerator; 
        cin >> Frac[i].denominator; 
    } 
    frac temp = Frac[0]; 
    for(int i = 1; i < n; i ++){
        if(compare(Frac[i], temp)){
            temp = Frac[i]; 
        }
    }
    cout << "Frac is greatest: " << temp.numerator << "/" << temp.denominator << endl; 
    insertionSort(Frac, n); 
    for(int i = 0;i < n;i ++){
        cout << Frac[i].numerator << "/" << Frac[i].denominator << "\n"; 
    }
    return 0; 
}
