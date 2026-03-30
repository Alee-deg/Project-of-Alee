#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std; 

int n, m;
vector<int> arr[1001];
bool visited[1001];
int parent[1001]; 

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int x, y; 
        cin >> x >> y; 
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    }
    memset(visited, false, sizeof(visited)); 
}

bool hasCircle1(int u, int par){
    visited[u] = true;
    for(int x : arr[u]){
        if(!visited[x]){
            if(hasCircle1(x, u)) return true;
        }
        else if(x != par){
            return true;
        }
    }
    return false;
}

int startq, endI; 

bool hasCircle2(int u){
    visited[u] = true; 
    for(int x : arr[u]){
        if(!visited[x]){
            parent[x] = u; 
            if(hasCircle2(x)) return true; 
        }
        else if(x != parent[u]){ 
            startq = x; 
            endI = u; 
            return true; 
        } 
    }
    return false; 
}

int main(){
    input(); 
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(hasCircle2(i)){
                cout << "Yes" << endl; 

                vector<int> res; res.push_back(startq); 

                while(endI != startq){
                    res.push_back(endI); 
                    endI = parent[endI]; 
                }
                res.push_back(startq); 
                reverse(res.begin(), res.end()); 
                for(int x : res){
                    cout << x << " "; 
                }
                return 0; 
            }
        }
    }
    cout << "No" << endl; 
    return 0; 
}




