#include<iostream>
#include<math.h>
#include<vector>

float binomialPow(float x, int n); 
class polynomial{
    int n; 
    float *coefficient; 
    public:
    polynomial() : n(1), coefficient(new float[1]{0}) {}

    polynomial(int degree) : n(degree + 1), coefficient(new float[degree + 1]()) {}

    polynomial(int degree, float* coe) : n(degree + 1), coefficient(new float[degree + 1]) {
        for (int i = 0; i < n; i++) {
            coefficient[i] = coe[i];
        }
    }
    ~polynomial(){
        delete[] coefficient; 
        std::cout << "Deconstructure\n"; 
    }
    polynomial(const polynomial& other) : n(other.n), coefficient(new float[other.n]) {
        for (int i = 0; i < n; i++) {
            coefficient[i] = other.coefficient[i];
        }
    }
    polynomial& operator=(const polynomial& other) {
        if (this != &other) {
            delete[] coefficient;
            n = other.n;
            coefficient = new float[n];
            for (int i = 0; i < n; i++) {
                coefficient[i] = other.coefficient[i];
            }
        }
        return *this;
    }
    void getValue(float x); 
    polynomial operator+(polynomial &a); 
    polynomial operator-(polynomial &a); 
    polynomial operator*(polynomial &a); 
    float operator[](int n); 
    friend std::ostream &operator<<(std::ostream &out, polynomial &a); 
    friend std::istream &operator>>(std::istream &in, polynomial &a); 
}; 
float polynomial::operator[](int n){
    return coefficient[n]; 
} 
std::ostream &operator<<(std::ostream &out, polynomial &a){
    for(int i = 0;i < a.n; i++){
        out <<(a.coefficient[i] >= 0 ? '+':'-') << std::fabs(a.coefficient[i]) << "*x^" << i;  
    }
    out << "\n"; 
    return out; 
}
std::istream &operator>>(std::istream &in, polynomial &a){
    std::cout << "Enter steps polynomial" << "\n";
    int n; std::cin >> n; 
    a.n = n + 1; 
    a.coefficient = new float[n + 1]; 
    for(int i = 0; i <= n;i ++){
        printf("a[%d]: ", i); 
        in >> a.coefficient[i]; 
    }
    return in; 
}
void polynomial::getValue(float x){
    float value = 0; 
    for(int i = 0; i <= n; i ++){
        value += coefficient[i]*binomialPow(x, i); 
    }
    std::cout << "Value is: "<<value << std::endl; 
}
polynomial polynomial::operator+(polynomial &a){
    polynomial res(n - 1); 
    for(int i = 0; i <= n;i ++){
        res.coefficient[i] = a.coefficient[i] + coefficient[i]; 
    }
    return res; 
}
polynomial polynomial::operator-(polynomial &b){
    polynomial res(n - 1); 
    for(int i = 0;i < n; i++){
        res.coefficient[i] = coefficient[i] - b.coefficient[i]; 
    }
    return res; 
}
polynomial polynomial::operator*(polynomial &b){
    polynomial res(n - 1); 
    for(int i = 0; i < b.n; i ++){
        for(int k = 0;k < n; k ++){
            res.coefficient[k] += b.coefficient[i]*coefficient[k];  
        }
    }
    return res; 
}
int main(){
    polynomial pol; 
    std::cin >> pol; 
    std::cout << pol;
    pol.getValue(3);  
    float arr[2] = {1, 1}; 
    int n = 1; 
    polynomial a(n, arr); 
    polynomial x = a*pol; 
    std::cout << x; 
    return 0; 
}
float binomialPow(float x, int n){
    if(n == 0){
        return 1; 
    }
    float X = binomialPow(x, n / 2); 
    if(n % 2 == 1){
        return X*X*x; 
    }
    else{
        return X*X; 
    }
}