#include<iostream>
#include<math.h>

using namespace std; 

class MaTrix; 

class CVector{
    float *Vector;
    int length; 
    public:
    CVector():CVector(1){}
    CVector(int len):length(len), Vector(new float[len]){
        for(int i = 0; i < len; i ++){
            Vector[i] = 0; 
        }
    }
    CVector(float *Vec, int len): length(len) {
        Vector = new float[len];
        for(int i = 0; i < len; i++){
            Vector[i] = Vec[i];
        }
    }
    ~CVector(){
        cout << "Deconstructure" << "\n"; 
        delete[] Vector; 
    }

    CVector(CVector &other){
        Vector = new float[other.length]; 
        for(int i = 0;i < other.length; i++){
            Vector[i] = other.Vector[i]; 
        }
        length = other.length; 
    }
    CVector operator+(CVector &other); 
    CVector operator-(CVector &other); 
    float operator*(CVector &other); 
    
    friend CVector operator*(MaTrix &other, CVector &a);

    float norm2(CVector &other){
        float sum = 0; 
        for(int i = 0;i < other.length;  i++){
            sum += other.Vector[i]*other.Vector[i]; 
        }
        return sqrt(sum); 
    }
    friend istream &operator>>(istream &in, CVector &a); 
    friend ostream &operator<<(ostream &out, CVector &a); 
    friend class MaTrix; 
}; 

CVector CVector::operator+(CVector &other){
    CVector res(other.length); 
    for(int i = 0;i < other.length; i ++){
        res.Vector[i] = other.Vector[i] + Vector[i]; 
    }
    return res; 
}

CVector CVector::operator-(CVector &other){
    CVector res(other.length); 
    for(int i = 0; i < other.length; i++){
        res.Vector[i] = Vector[i] - other.Vector[i]; 
    }
    return res; 
}

float CVector::operator*(CVector &other){
    float res = 0; 
    for(int i = 0;i < other.length;i ++){
        res += Vector[i]*other.Vector[i]; 
    }
    return res; 
}

istream &operator>>(istream &in, CVector &a){
    cout << "Enter dim of Vector\n"; 
    in >> a.length; 
    delete[] a.Vector;
    a.Vector = new float[a.length];  
    cout << "Enter components of Vector\n";
    for(int i = 0; i < a.length; i ++){
        in >> a.Vector[i]; 
    }
    return in; 
}

ostream &operator<<(ostream &out, CVector &a){
    out << "[ "; 
    for(int i = 0;i < a.length; i ++){
        out << a.Vector[i] << " "; 
    }
    out << "]"; 
    cout << endl; 
    return out; 
}

class MaTrix{
    int n, m; 
    float **arr; 
    public:
    MaTrix():MaTrix(0, 0){}
    MaTrix(int n):MaTrix(n, n){}
    MaTrix(int n, int m):n(n), m(m){
        arr = new float*[n]; 
        for(int i = 0;i < n;i ++){
            arr[i] = new float[m]; 
            for(int j = 0;j < m;j ++){
                arr[i][j] = 0; 
            }
        }
    }
    ~MaTrix(){
        cout << "Deconstructure" << "\n"; 
        for(int i = 0; i < n;i ++){
            delete[] arr[i]; 
        }
        delete[] arr; 
    }
    MaTrix(MaTrix &other):n(other.n), m(other.m){
        arr = new float*[n]; 
        for(int i = 0;i < n;i ++){
            arr[i] = new float[m]; 
            for(int j = 0; j < m;j ++){
                arr[i][j] = other.arr[i][j]; 
            }
        }
    }
    MaTrix operator+(MaTrix &other); 
    MaTrix operator-(MaTrix &other); 
    MaTrix operator*(MaTrix &other); 

    friend CVector operator*(MaTrix &other, CVector &a);

    friend istream &operator>>(istream &in, MaTrix &a); 
    friend ostream &operator<<(ostream &out, MaTrix &a); 
}; 
CVector operator*(MaTrix &other, CVector &a){
    CVector res(other.n);  
    if(other.m == a.length){
        for(int i = 0; i < other.n;i ++){
            for(int j = 0;j < other.m;j ++){
                res.Vector[i] += other.arr[i][j]*a.Vector[j]; 
            }
        }
    }
    else{
        cout << "Size of Array or Vector Invalid" << endl; 
    }
    return res; 
}
MaTrix MaTrix::operator+(MaTrix &other){
    MaTrix res(other.n, other.m); 
    if(other.n == n && other.m == m){
        for(int i = 0;i < n;i ++){
            for(int j = 0; j < m;j ++){
                res.arr[i][j] = other.arr[i][j] + arr[i][j]; 
            }
        }
    }
    else{
        cout << "Size invalid" << "\n"; 
        exit(1); 
    }
    return res; 
}

MaTrix MaTrix::operator-(MaTrix &other){
    MaTrix res(other.n, other.m); 
    if(other.n == n && other.m == m){
        for(int i = 0;i < n;i ++){
            for(int j = 0; j < m;j ++){
                res.arr[i][j] = arr[i][j] - other.arr[i][j]; 
            }
        }
    }
    else{
        cout << "Size invalid" << "\n"; 
        exit(1); 
    }
    return res; 
}

MaTrix MaTrix::operator*(MaTrix &other){
    MaTrix res(n, other.m); 
    if(m == other.n){
        for(int in = 0;in < n; in ++){
            for(int i = 0; i < other.m; i++){
                for(int j = 0;j < m; j ++){
                    res.arr[in][i] += arr[in][j]*other.arr[j][i]; 
                }
            }
        }
    }
    return res; 
}
istream &operator>>(istream &in, MaTrix &a){
    cout << "Enter dim of Array" << endl; 
    in >> a.n >> a.m; 
    delete[] a.arr; 
    a.arr = new float*[a.n]; 
    cout << "Enter components of Array" << "\n"; 
    for(int i = 0; i < a.n; i ++){
        a.arr[i] = new float[a.m]; 
        for(int j = 0; j < a.m;j ++){
            in >> a.arr[i][j]; 
        }
    }
    return in; 
}
ostream &operator<<(ostream &out, MaTrix &a){
    cout << "Array is\n"; 
    for(int i = 0;i < a.n;i ++){
        for(int j = 0;j < a.m;j ++){
            out << a.arr[i][j] << " "; 
        }
        out << "\n"; 
    } 
    return out; 
}
int main(){
    MaTrix A; 
    cin >> A; 
    MaTrix B; 
    cin >> B; 
    MaTrix C = A*B; 
    cout << C; 
    CVector D; 
    cin >> D; 
    cout << D; 
    CVector E = C*D;
    cout << E;  
    return 0; 
}
