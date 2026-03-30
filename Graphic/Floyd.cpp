#include<iostream>
#include<algorithm>
#include<vector>

using namespace std; 

int n, m; 
int arr[1001][1001] = {0}; 
int Par[1001][1001]; 
vector<int> path; 

void input(){
    cin >> n >> m; 
    for(int i = 0;i < m; i ++){
        int x, y, w; 
        cin >> x >> y >> w; 
        arr[x][y] = w; 
    }
}
const int INF = 1e9; 
void Floyd(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j ++){
            if(arr[i][j] == 0 && i!=j) arr[i][j] = INF; 
            Par[i][j] = i; 
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n;j ++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j]; 
                    Par[i][j] = Par[k][j]; 
                }
            }
        }
    }
}

int main(){
    input(); 
    Floyd(); 
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n;j ++){
            if(arr[i][j] == INF){
                cout << "INF "; 
                continue;
            }
            cout << arr[i][j] << " "; 
        }
        cout << "\n"; 
    }
    cout << "\n"; 
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n;j ++){
            cout << Par[i][j] << " "; 
        }
        cout << "\n"; 
    }
    int u = 1, v = 2; 
    while(1){
        path.push_back(v); 
        v = Par[u][v]; 
        if(u == v) break; 
    }
    path.push_back(u); 
    reverse(path.begin(), path.end()); 
    for(auto x : path){
        cout << x << " "; 
    }
    return 0; 
}; 