#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std; 

int n, m; 
vector<int> arr[1001]; 
queue<int> que;
bool visited[1001];  
int parent[1001]; 
int st, en; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y; 
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    }
    memset(visited, false, sizeof(visited)); 
}

bool BFS(int u){
    que.push(u); 
    visited[u] = true;
    while(!que.empty()){
        int v = que.front(); que.pop(); 
        for(int x : arr[v]){
            if(!visited[x]){
                que.push(x); 
                visited[x] = true; 
                parent[x] = v; 
            }
            else if(x != parent[v]){
                st = v; 
                en = x; 
                return true; 
            }
        }
    }
    return false;   
}

int main(){
    input(); 
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(BFS(i)){
                cout << "Yes" << endl; 

                // vector<int> res; res.push_back(st); 

                // while(en != st){
                //     res.push_back(en); 
                //     en = parent[en]; 
                // }
                // res.push_back(st); 
                // reverse(res.begin(), res.end()); 
                // for(int x : res){
                //     cout << x << " " << endl; 
                // }
                // return 0; 
            }
        }
    }
    cout << "No" << endl; 
    return 0; 
}




