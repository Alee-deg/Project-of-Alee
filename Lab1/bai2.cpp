#include<iostream>
#include<string>

class Account{
    std::string theNumbers; 
    int theBalance; 
    public:
    Account(){
        theNumbers = "000916029456"; 
        theBalance = 9000000;
    }
    Account(std::string numbers, int bal){
        theNumbers = numbers; 
        theBalance = bal; 
    }
    Account(Account& other){
        theNumbers = other.theNumbers; 
        theBalance = other.theBalance; 
    }
    ~Account(){
        std::cout << "Deconstructure" << std::endl; 
    }
    void credit(int anAmount){
        theBalance += anAmount; 
    }
    void debit(int anAmount){
        if(anAmount <= theBalance){
            theBalance -= anAmount; 
        }
        else{
            std::cout << "The balance is lower than anAmount" << std::endl; 
        }
    }
    int getBalance(){
        return theBalance; 
    }
    void display(){
        std::cout << theBalance << " " << theNumbers << std::endl; 
    }
    friend std::istream &operator>>(std::istream &in, Account &a); 
    friend std::ostream &operator<<(std::ostream &out, const Account &a); 
}; 
std::istream &operator>>(std::istream &in, Account &a){
    std::cout << "Enter the numbers" << std::endl; 
    getline(in, a.theNumbers); 
    std::cout << "Enter the balance" << std::endl; 
    in >> a.theNumbers; 
    return in; 
}
std::ostream &operator<<(std::ostream &out, const Account &a){
    out << a.theNumbers << " " << a.theBalance << "\n"; 
    return out; 
}

int main(){
    Account a; 
    std::cin >> a; 
    std::cout << a; 
    return 0; 
}