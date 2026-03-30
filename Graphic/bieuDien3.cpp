#include<iostream>
#include<vector>

using namespace std; 

vector<pair<int, int>> edg;
int arr[1001][1001];  

int main(){
    int n; 
    cin >> n;  
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> arr[i][j]; 
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1;j <= n; j ++){
            if(arr[i][j] && i < j){
                edg.push_back({i, j}); 
            }
        }
    }
    for(auto x : edg){
        cout << x.first << " " << x.second << "\n"; 
    }
    return 0; 
}