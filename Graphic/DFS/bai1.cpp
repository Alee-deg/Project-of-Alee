#include<iostream>
#include<vector>
#include<string.h>
using namespace std; 

int n, m; 
vector <int> arr[1001]; 
bool visited[1001]; 

void input(){
    cin >> n >> m; 
    int x, y;
    for(int i = 0; i < m;i ++){
        cin >> x >> y; 
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    }
    memset(visited, false, sizeof(visited)); 
}

void dfs(int u){
    cout << u << " "; 
    visited[u] = true; 
    for(int v : arr[u]){
        if(!visited[v]){
            dfs(v); 
        }
    }
}
int main(){
    input();
    dfs(3); 
    return 0; 
}