#include<iostream>

class Frac{
    int numerator; 
    int denominator; 
    public:
    Frac(int a, int b){
        if(b != 0){
            numerator = a; 
            denominator = b; 
        }
    }
    Frac(){
        numerator = 0; 
        denominator = 0; 
    }
    int GCD(int a, int b); 
    int LCM(int a, int b); 
    Frac simplify(Frac a); 
    Frac operator+(Frac b); 
    Frac operator-(Frac b); 
    Frac operator/(Frac b); 
    Frac operator*(Frac b); 
    bool operator>(Frac b); 
    bool operator<(Frac b); 
    void display(){
        std::cout << numerator << "/" << denominator << std::endl; 
    }
    friend std::ostream& operator<<(std::ostream& out, const Frac& a); 
    friend std::istream& operator>>(std::istream& in, Frac& b);
};
int Frac::GCD(int a, int b){
    if(a % b == 0){
        return b; 
    }
    return GCD(b, a % b); 
} 
int Frac::LCM(int a, int b){
    return a * b / GCD(a, b); 
}
Frac Frac::simplify(Frac a){
    int gcd = GCD(a.denominator, a.numerator);
    Frac c; 
    c.numerator = a.numerator / gcd; 
    c.denominator = a.denominator / gcd; 
    return c;  
}
Frac Frac::operator+(Frac b){
    Frac c; 
    int lcm = LCM(denominator, b.denominator); 
    c.numerator = (lcm/denominator)*numerator + (lcm/b.denominator)*b.numerator; 
    c.denominator = lcm;
    c = simplify(c); 
    return c; 
}
Frac Frac::operator-(Frac b){
    int lcm = LCM(denominator, b.denominator); 
    Frac c; 
    c.numerator = (lcm / denominator)*numerator - (lcm / b.denominator)*b.numerator; 
    c.denominator = lcm; 
    c = simplify(c); 
    return c; 
}
Frac Frac::operator*(Frac b){
    Frac c; 
    c.numerator = numerator * b.numerator; 
    c.denominator = denominator*b.denominator; 
    c = simplify(c); 
    return c; 
}
Frac Frac::operator/(Frac b){
    Frac c; 
    c.numerator = numerator*b.denominator; 
    c.denominator = denominator*b.numerator; 
    c = simplify(c); 
    return c; 
}
std::ostream& operator<<(std::ostream& out, const Frac& a){
    out << a.numerator << "/" << a.denominator << std::endl;
    return out; 
}
std::istream& operator>>(std::istream& in, Frac& a){
    std::cout << "Enter numerator\n"; 
    in >> a.numerator; 
    std::cout << "Enter denominator\n"; 
    in >> a.denominator; 
    return in; 
}
int main(){
    Frac a(2, 4); 
    Frac b(2, 3); 
    Frac c = a-b;
    c.display();  
    std::cout << c; 
    std::cout << a; 
    std::cout << b;
    Frac d; 
    std::cin >> d; 
    std::cout << d; 
    return 0; 
}