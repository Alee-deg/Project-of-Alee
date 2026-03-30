#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std; 

int n, m, s, t; 
char arr[1001][1001]; 
queue<pair<int, int>> que; 
int dx[4] = {-1, 0, 0, 1}; 
int dy[4] = {0, -1, 1, 0}; 
int cnt[1001][1001]; 

bool dfs(int u, int v){
    cout << u << " : " << v << endl; 
    if(arr[u][v] == 'B'){
        return true; 
    }
    arr[u][v] = 'x'; 
    for(int k = 0; k < 4; k++){
        int i1 = u + dx[k]; 
        int j1 = v + dy[k]; 
        if((i1 >= 1 && i1 <= n) && (j1 >= 1 && j1 <= m) && arr[i1][j1] != 'x'){
            if(dfs(i1, j1)) return true; 
        }
    }
    return false; 
}

bool bfs(int u, int v){
    que.push({u, v}); 
    arr[u][v] = 'x'; 
    cout << u << " : " << v << endl; 
    cnt[u][v] = 0; 
    while(!que.empty()){
        cout << que.front().first << " : " << que.front().second << endl; 
        int x = que.front().first; 
        int y = que.front().second; 
        que.pop(); 
        for(int i = 0; i < 4; i ++){
            int i1 = x + dx[i]; 
            int j1 = y + dy[i]; 
            if((i1 >= 1 && i1 <= n) && (j1 >= 1 && j1 <= m) && arr[i1][j1] != 'x'){
                cout << i1 << " : " << j1 << endl; 
                cnt[i1][j1] = 1 + cnt[x][y]; 
                if(arr[i1][j1] == 'B') return true; 
                que.push({i1, j1}); 
                arr[i1][j1] = 'x'; 
            }
        }
    }
    return false; 
}
int main(){
    cin >> n >> m >> s >> t; 
    for(int i = 1; i <= n; i ++){
        for(int j = 1;j <= m; j++){
            cin >> arr[i][j]; 
        }
    }
    if(bfs(1, 1)){
        cout << "YES\n";
        cout << cnt[s][t] << endl;
    }
    else{
        cout << "NO\n"; 
    }
    return 0; 
}