#include <iostream>
using namespace std;

class BangCuuChuong {
public:

    void bangN(int n) {
        for(int i = 1; i <= 10; i++) {
            cout << n << " x " << i << " = " << n*i << endl;
        }
    }

    void bangMN(int m, int n) {
        for(int i = m; i <= n; i++) {
            cout << "\nBang cuu chuong " << i << endl;
            bangN(i);
        }
    }

    void bangTongHop() {
        for(int i = 1; i <= 9; i++) {
            cout << "\nBang cuu chuong " << i << endl;
            bangN(i);
        }
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== MENU =====\n";
            cout << "1. Bang cuu chuong thu n\n";
            cout << "2. Bang cuu chuong tu m den n\n";
            cout << "3. Bang cuu chuong tong hop\n";
            cout << "0. Thoat\n";
            cout << "Chon: ";
            cin >> choice;

            switch(choice) {
                case 1: {
                    int n;
                    cout << "Nhap n: ";
                    cin >> n;
                    bangN(n);
                    break;
                }

                case 2: {
                    int m, n;
                    cout << "Nhap m: ";
                    cin >> m;
                    cout << "Nhap n: ";
                    cin >> n;
                    bangMN(m,n);
                    break;
                }

                case 3:
                    bangTongHop();
                    break;

                case 0:
                    cout << "Thoat chuong trinh\n";
                    break;

                default:
                    cout << "Lua chon khong hop le\n";
            }

        } while(choice != 0);
    }
};

int main() {
    BangCuuChuong app;
    app.menu();
    return 0;
}