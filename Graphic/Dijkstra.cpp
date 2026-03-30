#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<cmath>
#include<algorithm>

using ll = long long; 

using namespace std; 

const int maxn = 100001;
int n, m; 
vector<pair<int, int>> adj[maxn];
bool visited[1001]; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m;i ++){
        int x, y, w; 
        cin >> x >> y >> w; 
        adj[x].push_back({y, w}); 
    }
    memset(visited, false, sizeof(visited)); 
}

const int INF = 1e9; 
int pre[1001]; 

void dijstra(int s, int t){
    //Mang luu khoang cach duong di
    vector<ll> d(n + 1, INF); 
    d[s] = 0; 
    pre[s] = s; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; 
    //{Khoang cach, dinh}
    Q.push({0, s}); 
    while(!Q.empty()){
        //Chon ra khoang cach tu s nho nhat
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second; 
        int kc = top.first; 
        // if(visited[u]) continue;
        // visited[u] = true; 
        //relaxation: Cap nhat khoang cach tu s cho toi moi dinh ke cua u
        if(kc > d[u]) continue; 
        for(auto it : adj[u]){
            int v = it.first; 
            int w = it.second; 
            if(d[v] > d[u] + w){
                d[v] = d[u] + w; 
                Q.push({d[v], v}); 
                pre[v] = u; 
            }
        }
    }
    cout << d[t] << endl; 
    vector<int> path; 
    while(1){
        path.push_back(t); 
        if(t == s){
            break; 
        }
        t = pre[t]; 
    }
    reverse(begin(path), end(path)); 
    for(int x : path){
        cout << x << " "; 
    }
}

int main(){
    input(); 
    dijstra(1, 4); 
    return 0; 
}


