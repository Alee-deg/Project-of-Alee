#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std; 

int n, m, t, s; 
bool visited[1001]; 
vector<int> arr[1001]; 
queue<int> ar; 
int parent[1001]; 

void DFS(int u){
    visited[u] = true;
    for(int v : arr[u]){
        if(!visited[v]){
            parent[v] = u;
            DFS(v); 
        }
    } 
}

void BFS(int u){
    ar.push(u); 
    visited[u] = true; 
    while(!ar.empty()){
        int value = ar.front(); 
        ar.pop(); 
        for(int x : arr[value]){
            if(!visited[x]){
                ar.push(x); 
                visited[x] = true; 
                parent[x] = value; 
            }
        }
    }
}

void Path(int s, int t){
    memset(visited, false, sizeof(visited)); 
    memset(parent, 0, sizeof(parent)); 
    BFS(s); 
    if(!visited[t]){
        cout << "Khong co duong di! \n"; 
    }
    else{
        vector<int> path; 
        while(t != s){
            path.push_back(t); 
            t = parent[t]; 
        }
        path.push_back(t); 
        reverse(path.begin(), path.end()); 
        for(int x : path){
            cout << x << " "; 
        }
        cout << "\n"; 
    }

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int x, y;
        cin >> x >> y;  
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    }     
    cin >> s >> t;
    Path(s, t); 
    return 0; 
}