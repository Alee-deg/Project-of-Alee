#include<iostream>
#include<string.h>
#include<vector>
#include<sstream>

using namespace std;
vector<int> date; 
void input(){
    string date; 
    getline(cin, date); 
    string num;
    stringstream ss(date); 
    while(ss >> num){
        date.push_back(stoi(num)); 
    }
}

int main(){
    input(); 
    return 0; 
}
