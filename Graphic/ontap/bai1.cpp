#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int n, m; 
vector<int> arr[1001]; 
bool visited[1001]; 
queue<int> que; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    }
    memset(visited, false, sizeof(visited)); 
}

void DFS(int u){
    cout << u << " "; 
    visited[u] = true; 
    for(int x : arr[u]){
        if(!visited[x]){
            DFS(x); 
        }
    }
}

void BFS(int u){
    que.push(u); 
    visited[u] = true; 
    while(!que.empty()){
        int value = que.front(); 
        que.pop(); 
        cout << value << endl; 
        for(int x : arr[value]){
            if(!visited[x]){
                que.push(x); 
                visited[x] = true; 
            }
        }
    }
}

