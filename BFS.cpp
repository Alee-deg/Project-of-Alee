#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std; 

int n, m;
vector<int> arr[1001];
bool visited[1001]; 
queue<int> que1; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i ++){
        int x, y; cin >> x >> y; 
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    }
    memset(visited, false, sizeof(visited)); 
}

void DFS(int u){
    que1.push(u); 
    visited[u] = true; 
    while(!que1.empty()){
        int val = que1.front(); 
        que1.pop(); 
        cout << val << " "; 
        for(int x : arr[val]){
            if(!visited[x]){
                que1.push(x); 
                visited[x] = true; 
            }
        }
    }
}

int main(){
    input();
    DFS(1); 
    return 0; 
}
