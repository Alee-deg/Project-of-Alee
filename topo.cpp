#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std; 

int n, m; 
vector<int> arr[1001]; 
bool visited[1001]; 
vector<int> topo; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i++){
        int x, y; 
        cin >> x >> y; 
        arr[x].push_back(y); 
    }
    memset(visited, false, sizeof(visited)); 
}

void DFS(int u){
    visited[u] = true; 
    for(int x : arr[u]){
        if(!visited[x]){
            DFS(x); 
        }
    }
    topo.push_back(u); 
}

int main(){
    input(); 
    for(int i = 1; i <= n;i ++){
        if(!visited[i]){
            DFS(i); 
        }
    }
    reverse(topo.begin(), topo.end()); 
    for(int x : topo){
        cout << x << " "; 
    }
    cout << endl; 
    return 0; 
}