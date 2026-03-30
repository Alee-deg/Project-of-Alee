#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

class squareMatrix{
    int n; 
    int **arr; 
    public:
    ~squareMatrix(){
        cout << "Decostructure" << "\n"; 
        for(int i = 0;i < n;i ++){
            delete[] arr[i]; 
        }
        delete[] arr; 
    }
    
    squareMatrix(int n):n(n){
        arr = new int*[n]; 
        for(int i = 0; i < n;i ++){
            arr[i] = new int[n]; 
            for(int j = 0; j < n; j++){
                arr[i][j] = 0; 
            }
        }
    }
    squareMatrix():squareMatrix(0){}
    squareMatrix(squareMatrix &other){
        cout << "Copy Constructure\n"; 
        arr = new int*[n]; 
        n = other.n; 
        for(int i = 0;i < n; i++){
            arr[i] = new int[n]; 
            for(int j = 0;j < n;j ++){
                arr[i][j] = other.arr[i][j]; 
            }
        }
        n = other.n; 
    }

    squareMatrix& operator=(squareMatrix &other);
    
    void getLength(){
        printf("MATRIX[%d][%d]\n", n, n);  
    }
    int *getRow(int index){
        return arr[index]; 
    }
    vector<int> getCol(int indx){
        vector<int> res; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n;j ++){
                if(j == indx){
                    res.push_back(arr[i][j]); 
                }
            }
        }
        return res; 
    }
    int getElement(int x, int y){
        return arr[x][y]; 
    }

    void setLength(int len){
        n = len; 
    }
    void setChangeAElement(int x, int y, int num){
        arr[x][y] = num; 
    }
    void setAllNewElement(int **num){
        for(int i = 0;i < n;i ++){
            for(int j = 0; j < n; j ++){
                arr[i][j] = num[i][j]; 
            }
        }
    }
    void setANewRow(int idx, int *num){
        for(int i = 0; i < n; i ++){
            arr[idx][i] = num[i]; 
        }
    }
    void setANewCol(int idx, int *num){
        vector<int> temp; 
        for(int i = 0; i < n; i ++){
            temp.push_back(num[i]); 
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0;j < n;j ++){
                if(j == idx){
                    arr[i][j] = temp.back();
                    temp.pop_back();  
                }
            }
        }
    }

    friend istream &operator>>(istream &in, squareMatrix &a); 
    friend ostream &operator<<(ostream &out, squareMatrix &a); 

    void valueIntoRange(int x, int y){
        cout << "[ "; 
        for(int i = 0; i < n; i ++){
            for(int j = 0;j < n;j ++){
                if(arr[i][j] > x && arr[i][j] < y){
                    cout << arr[i][j] << " "; 
                }
            }
        }
        cout << "]"; 
    }
    void valueOddOntoMainDia(){
        cout << "["; 
        for(int i = 0; i < n; i ++){
            for(int j = 0;j < n;j ++){
                if(i == j && (arr[i][j] % 2 != 0)){
                    cout << arr[i][j] << " "; 
                }
            }
        }
        cout << "]"; 
    }
    bool insNegativeValueOntoUpperTriagle(){
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                if(arr[i][j] < 0 && j < i){
                    return true; 
                }
            }
        }
        return false; 
    }
    vector<int> valueOntoAntiDiagonal(){
        vector<int> res; 
        for(int i = 0; i < n; i ++){
            res.push_back(arr[n - i][n - 1 - i]); 
        }
        sort(res.begin(), res.end(), [](int x, int y){
            return x > y;}); 
        return res; 
    }
    int ins(){
        for(int i = 0; i < n; i ++){
            for(int j = 0;j < n;j ++){
                if((i + j > n - 1) && (arr[i][j] % 2 == 0)){
                    return arr[i][j]; 
                }
            }
        }
        return __INT_MAX__; 
    }
}; 
istream &operator>>(istream &in, squareMatrix &a){
    for(int i = 0; i < a.n; i ++){
        delete[] a.arr[i]; 
    }
    delete[] a.arr; 
    cout << "Enter dim of Array" << "\n"; 
    in >> a.n; 
    a.arr = new int*[a.n];
    for(int i = 0; i < a.n;i ++){
        a.arr[i] = new int[a.n];
        for(int j = 0; j < a.n; j ++){
            in >> a.arr[i][j]; 
        } 
    } 
    return in; 
}
ostream &operator<<(ostream &out, squareMatrix &a){
    printf("Matrix[%d][%d]\n", a.n, a.n); 
    for(int i = 0; i < a.n;i ++){
        for(int j = 0;j < a.n;j ++){
            out << a.arr[i][j] << " "; 
        }
        cout << "\n"; 
    }
    return out; 
}
squareMatrix& squareMatrix::operator=(squareMatrix &other){
    cout << "Operator= \n"; 
    if(this != &other){
        for(int i = 0; i < n; i++){
            delete[] arr[i];
        }
        delete[] arr;
        
        n = other.n;
        arr = new int*[n];
        for(int i = 0; i < n; i++){
            arr[i] = new int[n];
            for(int j = 0; j < n; j++){
                arr[i][j] = other.arr[i][j];
            }
        }
    }
    return *this; 
}
int main(){
    squareMatrix A; 
    cin >> A; 
    cout << A; 
    squareMatrix B;
    squareMatrix C; 
    C =  B = A; 
    cout << B; 
    cout << C; 
    cout << C.getElement(2, 2) << endl; 
    return 0; 
}