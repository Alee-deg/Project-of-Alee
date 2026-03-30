#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std; 

int n, m; 
vector<int> arr[1001]; 
queue<int> que1; 
bool visited[1001]; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m;i ++){
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

int ConnectedComponent(){
    int count = 0; 
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            count ++; 
            cout << "Cac dinh thuoc thanh phan lien thong thu: " << count << "\n"; 
            DFS(i); 
            cout << "\n"; 
        }
    }
    return count; 
}

int main(){
    input(); 
    int count = ConnectedComponent(); 
    cout <<"So thanh phan lien thong " << count << endl; 
    return 0; 
}