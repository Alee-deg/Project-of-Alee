#include<iostream>
#include<vector>
#include<sstream>

using namespace std; 

vector<int> arr[1001]; 

int n; 

int main(){
    cin >> n; 
    cin.ignore(); 
    for(int i = 1; i <= n; i ++){
        string x, num; 
        getline(cin, x); 
        stringstream ss(x); 
        while(ss >> num){
            arr[i].push_back(stoi(num));
        } 
    }
    for(int i = 1; i <= n; i ++){
        for(int x : arr[i]){
            if(i < x) cout << i << " " << x << endl; 
        }
    }
    return 0; 
}