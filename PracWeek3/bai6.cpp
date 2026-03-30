#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std; 

class String{
    private:
        char* str; 
        int length; 
    public:
        String(){
            length = 0; 
            str = new char[1]; 
            str[0] = '\0'; 
        }
        String(const char *s){
            length = strlen(s); 
            str = new char[length + 1]; 
            strcpy(str, s); 
        }
        String(const String& other){
            cout << "Copy\n"; 
            length = other.length; 
            str = new char[length + 1]; 
            strcpy(str, other.str); 
        }
        ~String(){
            cout << "======================\n"; 
            delete[] str; 
        }
        int size() const{
            return length; 
        }
        String operator+(const String& other){
            String result; 
            delete[] result.str; 

            result.length = length + other.length; 
            result.str = new char[result.length + 1]; 

            strcpy(result.str, str); 
            strcat(result.str, other.str); 

            return result; 
        }
        void reverse(){
            for(int i = 0; i < length / 2; i ++){
                std::swap(str[i], str[length - i - 1]); 
            }
        }
        void toUpper(){
            for(int i = 0;i < length; i ++){
                str[i] = toupper(str[i]); 
            }
        }
        void toLower(){
            for(int i = 0; i < length; i++){
                str[i] = tolower(str[i]); 
            }
        }
        friend istream& operator>>(istream &in, String &s){
            char buffer[1000]; 
            in.getline(buffer, 1000); 

            delete[] s.str; 
            s.length = strlen(buffer); 
            s.str = new char[s.length + 1]; 
            strcpy(s.str, buffer); 
            return in; 
        }
        friend ostream& operator<<(ostream &out, const String &s){
            out << s.str; 
            return out; 
        }
}; 

int main() {
    String s1, s2;

    cout << "Nhap chuoi 1: ";
    cin >> s1;

    cout << "Nhap chuoi 2: ";
    cin >> s2;

    cout << "\nChuoi 1: " << s1 << endl;
    cout << "Chuoi 2: " << s2 << endl;

    // Độ dài
    cout << "Do dai chuoi 1: " << s1.size() << endl;

    // Nối chuỗi
    String s3 = s1 + s2;
    cout << "Noi chuoi: " << s3 << endl;

    // Đảo chuỗi
    s1.reverse();
    cout << "Dao chuoi 1: " << s1 << endl;

    // Chữ hoa
    s2.toUpper();
    cout << "Chuoi 2 viet hoa: " << s2 << endl;

    // Chữ thường
    s2.toLower();
    cout << "Chuoi 2 viet thuong: " << s2 << endl;

    String s4 = s3; 

    return 0;
}