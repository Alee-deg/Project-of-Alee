#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std; 

int n, m, s, t; 
vector<int> arr[1001];
queue<int> que1;
bool visited[1001]; 
int path[1001]; 

void DFS(int u){
    visited[u] = true; 
    for(int x : arr[u]){
        DFS(x); 
        path[x] = u; 
    }
}

void BFS(int u){
    que1.push(u); 
    visited[u] = true; 
    while(!que1.empty()){
        int val = que1.front(); 
        que1.pop(); 
        for(int v : arr[val]){
            if(!visited[v]){
                que1.push(v); 
                visited[v] = true;
                path[v] = u; 
            }
        }
    }
}

int Path(int s, int t){
    DFS(s); 
    if(!visited[t]){
        return 0; 
    }
    else{
        vector<int> pah; 
        while(t!=s){
            pah.push_back(t); 
            t = path[t]; 
        }
        pah.push_back(s); 
        for(int x : pah){
            cout << x << " "; 
        }
        cout << "\n"; 
    }
}

int cnt(int u){
    int count = 0; 
    for(int i = 1; i <= n;i ++){
        if(!visited[i]){
            count ++; 
            DFS(i); 
        }
    }
}
void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    }
    cin >> s >> t; 
}

int main(){
    input(); 
}