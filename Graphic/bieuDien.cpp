#include<iostream>
using namespace std; 
int arr[1001][1001]; 
int main(){
    int m, n; cin >> n >> m; 
    for(int i = 0; i < m; i ++){
        int x, y; cin >> x >> y; 
        arr[x][y] = arr[y][x] = 1; 
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n;j ++){
            cout << arr[i][j] << " "; 
        }
        cout << endl; 
    }
    return 0; 
}