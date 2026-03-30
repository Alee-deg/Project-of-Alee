#include<iostream>

int getElement(int arr[], int index){
    return arr[index]; 
}
int main(){
    int a[3] = {1, 2, 3}; 
    std::cout << getElement(a, 2) << "\n"; 
    for(int x : a){
        std::cout << x << " "; 
    }
    int a1 = 1; 
    int &b = a1; 
    int c = 3; 
    if(b == c){
        return 1; 
    }
    return 0; 
}