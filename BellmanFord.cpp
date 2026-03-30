#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std; 

int n, m; 
vector<pair<int, int>> arr[1001]; 
bool inQueue[1001]; 
queue<int> Q; 
int d[1001]; 
int par[1001]; 
vector<int> path; 
int cnt[1001]; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i++){
        int x, y, w; 
        cin >> x >> y >> w; 
        arr[x].push_back({w, y}); 
        // arr[y].push_back({x, w}); 
    }
    memset(inQueue, false, sizeof(inQueue)); 
}

const int INF = 1e9; 

void BellMan_Ford(int u, int t){
    for(int i = 1; i <= n;i ++){
        d[i] = INF; 
    }
    d[u] = 0; 
    Q.push(u); 
    cnt[u]++; 
    inQueue[u] = true; 
    while(!Q.empty()){
        int s = Q.front(); 
        Q.pop(); 
        inQueue[s] = false;  
        for(auto i : arr[s]){
            if(d[i.second] > d[s] + i.first){
                d[i.second] = d[s] + i.first; 
                par[i.second] = s; 
                if(!inQueue[i.second]){
                    cnt[i.second] ++; 
                    Q.push(i.second); 
                    inQueue[i.second] = true; 
                }
            }
        }
        if(cnt[s] >= n){
            cout << "Has a negative cycle\n"; 
            exit(1); 
        }
    }
    while(1){
        path.push_back(t); 
        if(t == u){
            break; 
        }
        t = par[t]; 
    }
    reverse(path.begin(), path.end()); 
    for(auto i : path){
        cout << i << " "; 
    }
}

int main(){
    input(); 
    BellMan_Ford(1, 4); 
    return 0; 
}

