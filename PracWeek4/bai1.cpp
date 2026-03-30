#include<iostream>
#include<cmath>
#include<math.h>
class complex{
    float real; 
    float image; 
    public:
    complex(float real):complex(real, 0){}
    complex():complex(0, 0){}
    complex(float real, float image){
        this -> real = real; 
        this -> image = image; 
    }
    ~complex(){
        std::cout << "Deconstructure" << std::endl; 
    }
    complex(complex &other){
        std::cout << "\n" << std::endl; 
        real = other.real; 
        image = other.image; 
    }
    complex operator+(complex b); 
    complex operator-(complex b); 
    complex operator*(complex b); 
    complex operator/(complex b);  
    bool operator==(complex b);
    bool operator!=(complex b); 

    friend std::istream &operator>>(std::istream &in, complex &a);
    friend std::ostream &operator<<(std::ostream &out, complex &a); 

    friend complex operator+(complex a, float b); 
    friend complex operator-(complex a, float b); 
    friend complex operator*(complex a, float b); 
    friend complex operator/(complex a, float b); 
    friend complex operator/(float b, complex a); 
}; 
std::istream &operator>>(std::istream &in, complex &a){
    std::cout << "Enter part real\n"; 
    in >> a.real; 
    std::cout << "Enter part image\n"; 
    in >> a.image; 
    return in; 
}
std::ostream &operator<<(std::ostream &out, complex &a){
    std::cout << "Complex\n"; 
    out << a.real << (a.image >= 0 ? '+' : '-') << fabs(a.image) << "*" << "i" << std::endl;
    return out; 
}
bool complex::operator==(complex b){
    if(real == b.real && image == image){
        return true; 
    }
    return false; 
}
bool complex::operator!=(complex b){
    if(operator==(b)){
        return false; 
    }
    return true; 
}

complex operator+(complex a, float b){
    complex c; 
    c.real = a.real + b; 
    c.image = a.image; 
    return c; 
}
complex operator-(complex a, float b){
    complex c; 
    c.real = a.real + b; 
    c.image = a.image;
    return c;  
}
complex operator*(complex a, float b){
    complex c; 
    c.real = a.real*b; 
    c.image = a.image*b; 
    return c; 
}
complex operator/(complex a, float b){
    if(b == 0){
        std::cout << "Divide for 0" << std::endl; 
        exit(1); 
    }
    complex c; 
    c.real = a.real / b; 
    c.image = c.image / b; 
    return c; 
}
complex operator/(float a, complex b){
    if(b.image == 0 && b.real == 0){
        std::cout << "Divide for 0" << std::endl; 
        exit(1); 
    }
    complex c; 
    c.real = (a*b.real) / (b.real*b.real + b.image*b.image); 
    c.image = (a*(-b.image)) / (b.real*b.real + b.image*b.image); 
    return c; 
}


complex complex::operator+(complex b){
    complex c; 
    c.image = image + b.image; 
    c.real = real + b.real; 
    return c;
}
complex complex::operator-(complex b){
    complex c; 
    c.real = real - b.real; 
    c.image = image - b.image; 
    return c; 
}
complex complex::operator*(complex b){
    complex c; 
    c.real = real*b.real - image*b.image; 
    c.image = real*b.image + image*b.real; 
    return c; 
}
complex complex::operator/(complex b){
    complex c; 
    c.real = (real*b.real + image*b.image) / (b.image*b.image + b.real*b.real); 
    c.image = (b.real*image - real*b.image) / (b.image*b.image + b.real*b.real); 
    return c; 
}
int main(){
    complex a;
    std::cin >> a; 
    std::cout << a << std::endl; 
    complex b; 
    std::cin >> b; 
    std::cout << b << std::endl; 
    if(a == b){
        std::cout << "a equal b" << std::endl; 
    }
    else{
        std:: cout << "a is different b" << std::endl; 
    }
    complex c = a + b;
    std::cout << c; 
    float q = 1; 
    complex w(-1, 2); 
    complex v = w + q; 
    std::cout << v << std::endl; 
    return 0;  
}