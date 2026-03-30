#include<iostream>
#include<vector>

using namespace std; 

vector<int> edg[1001]; 
int arr[1001][1001]; 

int main(){
    int n; cin >> n; 
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> arr[i][j]; 
        }
    }
    for(int i = 1;i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(arr[i][j] & i < j){
                edg[i].push_back(j); 
                edg[j].push_back(i); 
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        cout << i << ": "; 
        for(int x : edg[i]){
            cout << x << " "; 
        }
        cout << "\n"; 
    }
    return 0; 
}