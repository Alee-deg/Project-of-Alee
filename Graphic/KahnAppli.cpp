#include<iostream>
#include<string.h>
#include<vector>
#include<queue>

using namespace std; 

vector<int> arr[1001]; 
int n, m; 
int degree[1001]; 
queue<int> que; 

void input(){
    cin >> n >> m; 
    for(int i = 0; i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        arr[x].push_back(y);
        degree[y]++; 
    }
}

bool Kahn(){
    for(int i = 1; i <= n;i ++){
        if(degree[i] == 0){
            que.push(i); 
        }
    }
    int cnt = 0; 
    while(!que.empty()){
        int v = que.front(); que.pop(); 
        cnt ++; 
        for(int i : arr[v]){
            degree[i] --; 
            if(degree[i] == 0){
                que.push(i); 
            }
        }
    }
}

