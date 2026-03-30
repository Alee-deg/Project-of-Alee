#include <iostream>
#include <cstdlib>
using namespace std;

int GCD(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (b == 0) return a;
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return abs(a * b) / GCD(a, b);
}

int* simplifyAFraction(int a, int b) {
    int* newFrac = new int[2];

    if (b == 0) {
        newFrac[0] = 0;
        newFrac[1] = 0;
        return newFrac;
    }

    int gcd = GCD(a, b);
    a /= gcd;
    b /= gcd;

    if (b < 0) {
        a = -a;
        b = -b;
    }

    newFrac[0] = a;
    newFrac[1] = b;
    return newFrac;
}

int* msum(int numeratorA, int denominatorA, int numeratorB, int denominatorB) {
    int* save = new int[2];
    int lcm = LCM(denominatorA, denominatorB);
    int temp1 = lcm / denominatorA;
    int temp2 = lcm / denominatorB;
    numeratorA *= temp1;
    numeratorB *= temp2;
    int newNumerator = numeratorA + numeratorB;
    save[0] = newNumerator;
    save[1] = lcm;
    return save;
}

int* sub(int numeratorA, int denominatorA, int numeratorB, int denominatorB) {
    int* save = new int[2];
    int lcm = LCM(denominatorA, denominatorB);
    int temp1 = lcm / denominatorA;
    int temp2 = lcm / denominatorB;
    numeratorA *= temp1;
    numeratorB *= temp2;
    int newNumerator = numeratorA - numeratorB;
    save[0] = newNumerator;
    save[1] = lcm;
    return save;
}

int* product(int numeratorA, int denominatorA, int numeratorB, int denominatorB) {
    int* newFrac = new int[2];
    int numerator = numeratorA * numeratorB;
    int denominator = denominatorA * denominatorB;
    newFrac[0] = numerator;
    newFrac[1] = denominator;
    return newFrac;
}

int* divideFrac(int numeratorA, int denominatorA, int numeratorB, int denominatorB) {
    int* newFrac = new int[2];
    int numerator = numeratorA * denominatorB;
    int denominator = denominatorA * numeratorB;
    newFrac[0] = numerator;
    newFrac[1] = denominator;
    return newFrac;
}

int main() {
    cout << "Enter FracA\n";
    int numeratorA; cin >> numeratorA;
    int denominatorA; cin >> denominatorA;

    cout << "Enter FracB\n";
    int numeratorB; cin >> numeratorB;
    int denominatorB; cin >> denominatorB;

    if (denominatorA == 0 || denominatorB == 0) {
        cout << "Denominator cannot be 0\n";
        return 0;
    }

    if (numeratorB == 0) {
        cout << "Cannot divide by fraction with numerator 0\n";
    }

    cout << numeratorA << "/" << denominatorA << "\n";
    cout << numeratorB << "/" << denominatorB << "\n";

    int* Msum = msum(numeratorA, denominatorA, numeratorB, denominatorB);
    int* sumFrac = simplifyAFraction(Msum[0], Msum[1]);

    int* Sub = sub(numeratorA, denominatorA, numeratorB, denominatorB);
    int* SubFrac = simplifyAFraction(Sub[0], Sub[1]);

    int* Product = product(numeratorA, denominatorA, numeratorB, denominatorB);
    int* ProFrac = simplifyAFraction(Product[0], Product[1]);

    int* Divide = divideFrac(numeratorA, denominatorA, numeratorB, denominatorB);
    int* DivideFracResult = simplifyAFraction(Divide[0], Divide[1]);

    cout << "sum " << sumFrac[0] << "/" << sumFrac[1] << "\n";
    cout << "sub " << SubFrac[0] << "/" << SubFrac[1] << "\n";
    cout << "prod " << ProFrac[0] << "/" << ProFrac[1] << "\n";
    cout << "divide " << DivideFracResult[0] << "/" << DivideFracResult[1] << "\n";

    delete[] Msum;
    delete[] sumFrac;
    delete[] Sub;
    delete[] SubFrac;
    delete[] Product;
    delete[] ProFrac;
    delete[] Divide;
    delete[] DivideFracResult;

    return 0;
}