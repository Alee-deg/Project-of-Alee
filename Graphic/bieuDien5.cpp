#include<iostream>
#include<vector>

using namespace std; 

vector<int> adj[1001]; 
int arr[1001][1001]; 
int main(){
    int n; cin >> n; 
    for(int i = 1; i <= n; i ++){
        int x = 1; 
        while(x >= 0){
            cin >> x; 
            if (x > 0){
                adj[i].push_back(x);
            } 
        }
    }
    for(int i = 1; i <= n; i++){
        for(int x : adj[i]){
            arr[i][x] = 1;
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cout << arr[i][j] << " "; 
        }
        cout << "\n"; 
    }
    return 0; 
}