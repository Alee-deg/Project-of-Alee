#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std; 

int n, m; 
vector<int> arr[1001]; 
int degree[100]; 
queue<int> kah; 
vector<int> topo; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        arr[x].push_back(y);
        degree[y]++; 
    }
}

void kahn(){
    for(int i = 1; i <= n;i ++){
        if(!degree[i]){
            kah.push(i); 
        }
    }
    while(!kah.empty()){
        int u = kah.front(); kah.pop(); 
        topo.push_back(u); 
        for(int x : arr[u]){
            degree[x]--; 
            if(!degree[x]){
                kah.push(x); 
            }
        }
    }
    for(int x : topo){
        cout << x << " "; 
    }
}

int main(){
    input(); 
    kahn(); 
    return 0; 
}