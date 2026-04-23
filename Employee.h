#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<iostream>

using namespace std;

class Employee{
    private:
    string name; 
    string numberID;
    double salary; 
    public:
    Employee(); 
    Employee(string name, string numberID, double salary); 

    void setName(string name); 
    string getName() const;
    void setNumberID(string numberID); 
    string getNumberID() const; 
    void setSalary(double salary); 
    double getSalary() const;
    
    virtual void display() const; 
}; 
#endif