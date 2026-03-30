#include<iostream>
#include<algorithm>
#include<math.h>

class complex{
    float real; 
    float image; 
    public:
    complex sum(complex b){
        complex c; 

        return c; 
    }
    complex(){
        real = 0; 
        image = 0; 
    }
    complex(float a, float b){
        real = a; 
        image = b; 
    }
    friend std::ostream &operator<<(std::ostream &out, const complex &a);
    friend std::istream &operator>>(std::istream &in, complex &a); 
    complex operator+(complex b); 
    complex operator-(complex b); 
    complex operator*(complex b); 
    complex operator/(complex b);  
}; 
std::ostream &operator<<(std::ostream &out, const complex &a){
    out << a.real << (a.image < 0 ? "-" : "+") << fabs(a.image) <<"i"<< std::endl; 
    return out; 
}
std::istream &operator>>(std::istream &in, complex &a){
    std::cout << "Enter part real\n"; 
    in >> a.real; 
    std::cout << "Enter part image\n"; 
    in >> a.image; 
    return in; 
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
    complex b; 
    std::cin >> b; 
    complex c = a + b; 
    complex c = a.sum(b); 
    
    complex c = a * b; 
    std::cout << c; 
    return 0; 
}