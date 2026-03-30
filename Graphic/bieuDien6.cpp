#include<iostream>
#include<sstream>
#include<vector>
using namespace std; 

int arr[1001][1001]; 

int main(){
    int n; cin >> n; 
    cin.ignore(); 
    for(int i = 1; i <= n; i ++){
        string s, num;
        getline(cin, s); 
        stringstream ss(s);
        while(ss >> num){
            arr[i][stoi(num)] = 1; 
        } 
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j ++){
            cout << arr[i][j] << " "; 
        }
        cout << "\n"; 
    }
    return 0; 
}