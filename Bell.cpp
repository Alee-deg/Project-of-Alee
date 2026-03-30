#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std; 

int n, m; 
vector<pair<int, int>> arr[1001]; 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; 
int par[1001]; 
int dis[1001]; 
vector<int> path; 

void input(){
    cin >> n >> m; 
    int x, y, w; 
    for(int i = 0; i < m; i++){
        cin >> x >> y >> w; 
        arr[x].push_back({y, w}); 
        // arr[y].push_back({x, w}); 
    }
}
const int INF = 1e9; 
void Bellman_Ford(int u, int t){
    for(int i = 1; i <= n; i++){
        dis[i] = INF; 
    }
    dis[u] = 0; 
    par[u] = u; 
    Q.push({0, u});
    while(!Q.empty()){
        pair<int, int> s = Q.top();
        Q.pop();  
        int ver = s.second; 
        int distance = s.first;
        if(distance > dis[ver]) continue;
        for(auto i : arr[ver]){
            int veri = i.first; 
            int distancei = i.second;
            if(dis[veri] > dis[ver] + distancei){
                dis[veri] = dis[ver] + distancei; 
                par[veri] = ver;
                Q.push({dis[veri], veri});  
            } 
        } 
    }
    cout << dis[t] << "\n"; 
    while(1){
        path.push_back(t);  
        if(t == u){
            break; 
        }
        t = par[t];
    }
    reverse(path.begin(), path.end()); 
    for(auto x : path){
        cout << x << " "; 
    }
    cout << "\n"; 
}

int main(){
    input(); 
    Bellman_Ford(1, 4); 
    return 0; 
}