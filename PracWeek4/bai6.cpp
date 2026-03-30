#include<iostream>

using namespace std; 

class CDate{
private:
    int day, month, year;

    bool isLeapYear(int y) const {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    int daysInMonth(int m, int y) const {
        switch (m) {
            case 1: case 3: case 5: case 7:
            case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(y) ? 29 : 28;
            default:
                return 0;
        }
    }

    void normalize() {
        if (month < 1) month = 1;
        if (month > 12) month = 12;

        int maxDay = daysInMonth(month, year);
        if (day < 1) day = 1;
        if (day > maxDay) day = maxDay;
    }

    long long toSerial() const {
        long long total = 0;

        for (int y = 1; y < year; y++) {
            total += isLeapYear(y) ? 366 : 365;
        }

        for (int m = 1; m < month; m++) {
            total += daysInMonth(m, year);
        }

        total += day;
        return total;
    }

    void fromSerial(long long serial) {
        year = 1;
        while (true) {
            int daysOfYear = isLeapYear(year) ? 366 : 365;
            if (serial > daysOfYear) {
                serial -= daysOfYear;
                year++;
            } else break;
        }

        month = 1;
        while (true) {
            int dim = daysInMonth(month, year);
            if (serial > dim) {
                serial -= dim;
                month++;
            } else break;
        }

        day = (int)serial;
    }
    public:
    CDate(int day = 0, int month = 0, int year = 0):day(day), month(month), year(year){}
    CDate& operator++(){
        day ++; 
        normalize(); 
        return *this;  
    }
    CDate operator++(int){
        CDate temp(*this); 
        day ++; 
        normalize(); 
        return temp; 
    }
    CDate& operator--(){
        day --; 
        normalize();
        return *this; 
    }
    CDate operator--(int){
        CDate temp(*this); 
        day --; 
        normalize(); 
        return temp; 
    }
    CDate operator-(int a){
        day -= a; 
        normalize(); 
        return *this; 
    } 
    CDate operator+(int b){
        day -= b; 
        normalize(); 
        return *this; 
    }
    long long operator-(const CDate& other) const {
        long long a = this->toSerial();
        long long b = other.toSerial();
        return (a >= b) ? (a - b) : (b - a);
    }
    friend ostream &operator<<(ostream &out, CDate& a); 
    friend istream &operator>>(istream &in, CDate& a); 
}; 


