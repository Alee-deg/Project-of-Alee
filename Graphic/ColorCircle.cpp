#include<iostream>
#include<string.h>
#include<vector>

using namespace std; 

int n, m; 
vector<int> arr[1001]; 
int color[1001]; 

void input(){
    cin >> n >> m; 
    for(int i = 0;i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        arr[x].push_back(y); 
    }
    memset(color, 0, sizeof(color)); 
}

bool DFS(int u){
    color[u] = 1;
    for(int x : arr[u]){
        if(color[x] == 0){
            if(DFS(x)) return true;  
        }
        else if(color[x] == 1){
            return true; 
        }
    } 
    color[u] = 2; 
    return false; 
}

int main(){
    input(); 
    for(int i = 1;i <= n;i ++){
        if(color[i] == 0){
            if(DFS(i)){
                cout << "Yes\n"; 
                return 0; 
            }
        }
    }
    cout << "No" << endl; 
    return 0; 
}