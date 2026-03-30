#include <iostream>
#include <cmath>
using namespace std;

class NumberCheck {
private:
    int n;

public:
    void input() {
        cout << "Nhap so nguyen: ";
        cin >> n;
    }

    bool isPrime() {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    bool isPerfectSquare() {
        int x = sqrt(n);
        return x * x == n;
    }

    bool isPerfectNumber() {
        int sum = 0;
        for (int i = 1; i <= n/2; i++) {
            if (n % i == 0) sum += i;
        }
        return sum == n;
    }

    bool isPalindrome() {
        int temp = n;
        int rev = 0;

        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        return rev == n;
    }

    void display() {
        cout << "\nKet qua:\n";

        if (isPrime())
            cout << n << " la so nguyen to\n";
        else
            cout << n << " khong phai so nguyen to\n";

        if (isPerfectSquare())
            cout << n << " la so chinh phuong\n";
        else
            cout << n << " khong phai so chinh phuong\n";

        if (isPerfectNumber())
            cout << n << " la so hoan thien\n";
        else
            cout << n << " khong phai so hoan thien\n";

        if (isPalindrome())
            cout << n << " la so doi xung\n";
        else
            cout << n << " khong phai so doi xung\n";
    }
};

int main() {
    NumberCheck obj;

    obj.input();
    obj.display();

    return 0;
}
