#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std; 

int n, m; 
char arr[1001][1001]; 
queue<pair<int, int>> que1; 
bool visited[1001][1001]; 
int dx[4] = {-1, 0, 0, 1}; 
int dy[4] = {0, -1, 1, 0}; 

void dfs(int i, int j){
    cout << i << " : " << j << endl; 
    visited[i][j] = true; 
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k]; 
        int j1 = j + dy[k]; 
        if((i1 >= 1 && i1 <= n) && (j1 >= 1 && j1 <= m) && !visited[i1][j1] && arr[i1][j1] == 'x'){
            dfs(i1, j1); 
        }
    }
}

void bfs(int i, int j){
    que1.push({i, j}); 
    visited[i][j] = true; 
    while(!que1.empty()){
        cout << que1.front().first << " : " << que1.front().second << endl;
        int u = que1.front().first; 
        int v = que1.front().second;  
        que1.pop(); 
        for(int k = 0; k < 4; k ++){
            int i1 = u + dx[k]; 
            int j1 = v + dy[k]; 
            if(!visited[i1][j1] && arr[i1][j1] == 'x' && (i1 >= 1 && i1 <= n) && (i1 >= 1 && j1 <= n)){
                que1.push({i1, j1}); 
                visited[i1][j1] = true; 
            }
        }

    }
}

void input(){
    cin >> n >> m; 
    for(int i = 1; i <= n; i ++){
        for(int j = 1;j <= m;j ++){
            cin >> arr[i][j]; 
        }
    }
    int cnt = 0; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++){
            if(arr[i][j] == 'x' && !visited[i][j]){
                cout << "So thanh phan lien thong: " << cnt + 1 << endl; 
                bfs(i, j); 
                cnt ++; 
            }
        }
    }
    cout << cnt << endl; 
}
int main(){
    input(); 
    return 0; 
}