#include<iostream>
using namespace std; 

class AreaCalculator{
    public:
    double circleArea(double r){
        return 3.14159 * r * r; 
    }
    double rectangleArea(double a, double b){
        return a*b; 
    }
    double triangleArea(double base, double height){
        return 0.5 * base * height; 
    }
    void menu(){
        int choice; 
        do{
            cout << "\n===== MENU ====\n"; 
            cout << "1.Dien tich hinh tron\n"; 
            cout << "2.Dien tich hinh chu nhat\n"; 
            cout << "3.Dien tich hinh tam giac\n"; 
            cout << "0.Thoat\n"; 
            cout << "Chon: "; 
            cin >> choice; 
            switch(choice){
                case1: {
                    double r; 
                    cout << "Nhap ban kinh: "; 
                    cin >> r; 
                    cout << "Dien tich: " << circleArea(r) << endl; 
                    break; 
                }
                case 2: {
                    double a, b; 
                    cout << "Nhap chieu dai: "; 
                    cin >> a; 
                    cout << "Nhap chieu rong: "; 
                    cin >> b; 
                    cout << "Dien tich: " << rectangleArea(a, b) << endl; 
                    break; 
                }
                case 3: {
                    double base, height; 
                    cout << "Nhap day: "; 
                    cin >> base; 
                    cout << "Nhap chieu cao: "; 
                    cin >> height; 
                    cout << "Dien tich: " << triangleArea(base, height) << endl; 
                    break; 
                }
                case 0:
                    cout << "Thoat chuong trinh\n"; 
                    break; 
                default:
                    cout << "Lua chon khong hop le\n"; 
            }
        } while(choice != 0); 
    }
}; 

int main(){
    AreaCalculator app; 
    app.menu(); 
    return 0; 
}