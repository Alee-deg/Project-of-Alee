#include<iostream>
#include<ctime>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std; 
class CTime{
    private:
    int hour, minute, second; 
    void normalize(){
        int total = hour*3600 + minute*60 + second;
        total %= 86400; 
        if(total < 0) total += 86400; 
        hour = total / 3600; 
        minute = (total % 3600) / 60; 
        second = total % 60;  
    }
    public:
    CTime(int h = 0, int m = 0, int s = 0):hour(h), minute(m), second(s){
        normalize(); 
    }
    CTime operator+(int x) const{
        CTime temp(*this); 
        temp.second += x; 
        temp.normalize(); 
        return temp; 
    }
    CTime operator-(int x) const{
        CTime temp(*this); 
        temp.second -= x; 
        temp.normalize(); 
        return temp; 
    }
    CTime& operator++(){
        second ++; 
        normalize(); 
        return *this; 
    }
    CTime operator++(int){
        CTime temp(*this); 
        second ++; 
        normalize(); 
        return temp; 
    }
    CTime& operator--(){
        second --; 
        normalize();
        return *this;  
    }
    CTime operator--(int){
        CTime temp(*this); 
        second --; 
        normalize(); 
        return temp; 
    }
    friend istream& operator>>(istream& in, CTime& t) {
        in >> t.hour >> t.minute >> t.second;
        t.normalize();
        return in;
    }

    friend ostream& operator<<(ostream& out, const CTime& t) {
        out << setfill('0') << setw(2) << t.hour << ":"
            << setw(2) << t.minute << ":"
            << setw(2) << t.second;
        return out;
    }
};
int main() {
    while (true) {
        time_t now = time(0); // Lay current time
        tm* ltm = localtime(&now); // Lay time local

        CTime current(ltm->tm_hour, ltm->tm_min, ltm->tm_sec); // set

        // Xóa màn hình
        cout << "\033[2J\033[1;1H";

        // In lệch phải tương đối
        cout << setw(70) << current << endl;

        this_thread::sleep_for(chrono::seconds(1)); // Cho may ngu 1s
    }

    return 0;
}