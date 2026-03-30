#include<iostream>
#include<string>

using namespace std; 

struct student{
    string name; 
    float coreMath; 
    float coreLit; 
    float avg; 
}; 

void avg(student &a){
    a.avg = (a.coreLit + a.coreMath) / 2;  
}

void insertionSort(student arr[], int n){
    int j; 
    student key;
    for(int i = 0; i < n;i ++){
        key = arr[i]; 
        j = i - 1; 
        while(j >= 0 && key.avg < arr[j].avg){
            arr[j + 1] = arr[j]; 
            j --; 
        }
        arr[++j] = key; 
    }
}

int main(){
    student s[100];
    cout << "Enter number of student\n"; 
    int n; cin >> n; 
    for(int i = 0; i < n; i ++){
        cout << "Enter name of Student\n"; 
        cin.ignore(); 
        getline(cin, s[i].name); 
        cout << "Enter score Math\n"; 
        cin >> s[i].coreMath; 
        cout << "Enter score Lit\n"; 
        cin >> s[i].coreLit; 
        avg(s[i]);  
    }
    for(int i = 0; i < n; i ++){
        cout << s[i].avg << " "; 
    }
    cout << "\n";
    insertionSort(s, n); 
    for(int i = 0; i < n; i++){
        cout << s[i].avg << " "; 
    }  
    cout << "\n"; 
    cout << "min: " << s[0].avg << endl; 
    cout << "max: " << s[n - 1].avg << endl; 
    return 0; 
}