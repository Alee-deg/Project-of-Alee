#include<iostream>
#include<math.h>
#include<cmath>

class cTamGiac{
    private:
    std::pair<double, double> A; 
    std:: pair<double, double> B; 
    std:: pair<double, double> C; 
    public:
    cTamGiac(){
        A.first = A.second = 0;
        B.first = B.second = 0; 
        C.first = C.second = 0;  
    }
    cTamGiac(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c){
        A.first = a.first; 
        A.second = a.second; 
        B.first = b.first; 
        B.second = b.second; 
        C.first = c.first; 
        C.second = c.second; 
    }
    ~cTamGiac(){
        std:: cout << "Deconstructure" << std::endl; 
    }   
    cTamGiac(cTamGiac &other){
        std:: cout << "Copy Constructure" << std::endl; 
        A.first = other.A.first; 
        A.second = other.A.second; 
        B.first = other.B.first; 
        B.second = other.B.second; 
        C.first = other.C.first; 
        C.second = other.C.second; 
    }
    friend std::istream& operator>>(std::istream &in, cTamGiac &tri); 
    friend std::ostream& operator<<(std::ostream &out, const cTamGiac &tri); 
    void ins(); 
    float calPerimeter(); 
    float calArea(); 
    void traslation(int ox, int oy); 
    void Rotation(double angle, int x, int y); 
    void Enlargement(double a, double b, double k); 
    void reduction(double a, double b, double k); 
}; 
std::istream& operator>>(std::istream &in, cTamGiac &tri){
    std:: cout << "Enter the components A\n"; 
    in >> tri.A.first >> tri.A.second; 
    std:: cout << "Enter the components B\n"; 
    in >> tri.B.first >> tri.B.first; 
    std:: cout << "Enter the components C\n"; 
    in >> tri.C.first >> tri.C.second;
    return in;  
}
std::ostream& operator<<(std::ostream &out, const cTamGiac &tri){
    std::cout << "Components of A:\n"; 
    out << tri.A.first << " " << tri.A.second << std::endl; 
    std::cout << "Components of B:\n"; 
    out << tri.B.first << " " << tri.B.second << std::endl; 
    std::cout << "Components of C:\n"; 
    out << tri.C.first << " " << tri.C.second << std::endl; 
    return out; 
}
float norm2(int a, int b){
    return sqrt((1.0)*a*a + (1.0)*b*b); 
}
void cTamGiac::ins(){
    float lengthA = norm2(A.first, A.second); 
    float lengthB = norm2(B.first, B.second); 
    float lengthC = norm2(C.first, C.second); 
    if(lengthA == lengthB && lengthB == lengthC){
        std::cout<< "Equilateral triagle" << "\n";  
    }
    else if((lengthA == lengthB && lengthB != lengthC)
    || (lengthB == lengthC && lengthA != lengthC)
    || (lengthA == lengthC && lengthA != lengthB)){
        std::cout << "Iossceles triagle" << "\n"; 
    }
    else if((lengthA*lengthA == (lengthB*lengthB + lengthC*lengthC))
    ||(lengthB*lengthB == (lengthA*lengthA + lengthC*lengthC))
    ||(lengthC*lengthC == (lengthB*lengthB + lengthA*lengthA))){
        std::cout << "Right triangle" << std::endl; 
    }
    else{
        std::cout << "Normal triagle" << std::endl; 
    }
}
float cTamGiac::calPerimeter(){
    float lengthA = norm2(A.first, A.second); 
    float lengthB = norm2(B.first, B.second); 
    float lengthC = norm2(C.first, C.second); 
    return (lengthA + lengthB + lengthC) / 3; 
}
float cTamGiac::calArea(){
    float lengthA = norm2(A.first, A.second); 
    float lengthB = norm2(B.first, B.second); 
    float lengthC = norm2(C.first, C.second); 
    float p = calPerimeter() / 2; 
    return sqrt(p*(p - lengthA)*(p - lengthB)*(p - lengthC)); 
}
void cTamGiac::traslation(int ox, int oy){
    A.first += ox; 
    A.second += oy; 
    B.first += ox; 
    B.second += oy; 
    C.first += ox; 
    C.second += oy; 
}
void rotatePoint(double &x, double &y, double a, double b, double angle){
    double rad = angle * M_PI / 180; 
    double x1 = x - a; 
    double y1 = y - b; 

    double x_new = x1*cos(rad) - y1*sin(rad); 
    double y_new = x1*sin(rad) - y1*cos(rad); 

    x = x_new + a; 
    y = y_new + b; 
} 
void cTamGiac::Rotation(double angle, int x, int y){

    rotatePoint(A.first, A.second, x, y, angle);
    rotatePoint(B.first, B.second, x, y, angle); 
    rotatePoint(C.first, C.second, x, y, angle);  
}
void scalePoint(double &x, double &y, double a, double b, double k) {
    x = a + k * (x - a);
    y = b + k * (y - b);
}
void cTamGiac::Enlargement(double a, double b, double k){
    scalePoint(A.first, A.second, a, b, k); 
    scalePoint(B.first, B.second, a, b, k); 
    scalePoint(C.first, C.second, a, b, k); 
}
void cTamGiac::reduction(double a, double b, double k){
    scalePoint(A.first, A.second, a, b, k); 
    scalePoint(B.first, B.second, a, b, k); 
    scalePoint(C.first, C.second, a, b, k); 
}

int main(){
    cTamGiac tamgiac({1, 2}, {3, 4}, {1, 1}); 
    std::cout << tamgiac.calArea() << std::endl;
    std::cout << tamgiac.calPerimeter() << std::endl; 
    return 0; 
}

