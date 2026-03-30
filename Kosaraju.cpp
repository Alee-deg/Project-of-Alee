#include<iostream>
#include<vector>
#include<stack>
#include<string.h>

using namespace std; 

int n, m; 
vector<int> adj[1001], r_adj[1001]; 
bool visited[1001];
stack<int> st; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        adj[x].push_back(y); 
        r_adj[y].push_back(x); 
    }
}

void dfs1(int u){
    visited[u] = true; 
    for(int x : adj[u]){
        if(!visited[x]){
            dfs1(x); 
        }
    }
    st.push(u); 
}

void dfs2(int u){
    visited[u] = true; 
    cout << u << " "; 
    for(int i : r_adj[u]){ 
        if(!visited[i]) dfs2(i);
    }
}

void SCC(){
    memset(visited, false, sizeof(visited)); 
    while(!st.empty()){
        int v = st.top(); st.pop(); 
        if(!visited[v]){
            dfs2(v); 
            cout << endl; 
        }
    }
}

int main(){
    memset(visited, false, sizeof(visited)); 
    input(); 
    for(int i = 0;i < n; i ++){
        if(!visited[i]){
            dfs1(i); 
        }
    } 
    SCC(); 
    return 0; 
}