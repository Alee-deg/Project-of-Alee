#include "Employee.h"

Employee::Employee():Employee("", "", 0){}; 

Employee::Employee(string name, string numberID, double salary){
    this -> setName(name); 
    this -> setNumberID(numberID); 
    this -> setSalary(salary); 
}

void Employee::setName(string name){this -> name = name;}
string Employee::getName() const {return this -> name;}
void Employee::setNumberID(string numberID){this -> numberID = numberID;}
string Employee::getNumberID() const{return this -> numberID;}
void Employee::setSalary(double salary){this -> salary = salary;}
double Employee::getSalary() const {return this -> salary;}

void Employee::display() const{
    cout << "Name       :" << this -> getName() << endl; 
    cout << "NumberID   :" << this -> getNumberID() << endl; 
    cout << "Salary     :" << this -> getSalary() << endl; 
}