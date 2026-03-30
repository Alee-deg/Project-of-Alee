#include<iostream>
#include<string>

class Person{
    std::string name;
    int dateOfBirth; 
    public:
    Person(){
        name = "Hau"; 
        dateOfBirth = 2006;  
    } 
    Person(std::string Name, int dateOfBirth){
        name = Name; 
        this -> dateOfBirth = dateOfBirth; 
    }
    ~Person(){
        std::cout << "Deconstructure" << std::endl; 
    }
    Person(Person &other){
        name = other.name; 
        dateOfBirth = other.dateOfBirth; 
    }
    int getAge(){
        return 2026 - dateOfBirth; 
    }
    void display(){
        std::cout << name << " " << dateOfBirth << std::endl; 
    }
    friend std::istream &operator>>(std::istream &in, Person &a); 
    friend std::ostream &operator<<(std::ostream &out, const Person &a); 
};

std::istream &operator>>(std::istream &in, Person &a){
    std::cout<<"Enter name" << std::endl; 
    getline(in, a.name); 
    std::cout<<"Enter dateOfBirth" << std::endl; 
    in >> a.dateOfBirth;  
    return in; 
}
std::ostream &operator<<(std::ostream &out, const Person &a){
    out << a.name << " " << 2026 - a.dateOfBirth << std::endl; 
    return out; 
}
int main(){
    Person a; 
    std::cin >> a; 
    std::cout << a; 
    return 0; 
}