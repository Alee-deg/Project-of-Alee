#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
set<int> arr[1001];
vector<int> eul;
stack<int> st;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        arr[x].insert(y);
        arr[y].insert(x);
    }
}

void euler(int u) {
    st.push(u);
    while (!st.empty()){
        int x = st.top();
        if (!arr[x].empty()){
            int v = *arr[x].begin();
            st.push(v); 
            arr[x].erase(v);
            arr[v].erase(x);
        } else{
            st.pop();
            eul.push_back(x);
        }
    }
    reverse(eul.begin(), eul.end());
    for(int x : eul) cout << x << " "; 
}

int main(){
    input();
    euler(1);
    return 0;
}