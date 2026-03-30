#include<iostream>
#include<string.h>

using namespace std; 

#define MAX 100

int arr[MAX][MAX]; 
int n, m; 
bool visited[1001]; 
int Path[1001];

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        arr[x][y] = 1; 
        arr[y][x] = 1; 
    }
}

void print(int Path[], int nP){
    for(int i = 0; i <= nP; i++){
        cout << Path[i] << " "; 
    }
    cout << "\n"; 
}

void Hamilton(int u, int nP){
    Path[nP] = u; 
    visited[u] = true; 
    if(nP == n - 1){
        if(arr[u][1] > 0){
            Path[nP + 1] = 1; 
            print(Path, nP + 1); 
        }
    }
    else{
        for(int i = 1; i <= n; i ++){
            if(arr[u][i] > 0 && !visited[i]){
                Hamilton(i, nP + 1); 
            }
        }
    } 
    visited[u] = false; 
}

int main(){
    input(); 
    Hamilton(1, 0); 
    return 0; 
}


