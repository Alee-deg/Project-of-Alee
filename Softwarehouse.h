#ifndef SOFTWAREHOUSE_H
#define SOFTWAREHOUSE_H
#include "Programmer.h"
#include<unordered_set>
class SoftwareHouse{
    private:
    string name; 
    unordered_set<Programmer*> theStaff; 
    public:
    SoftwareHouse(); 
    SoftwareHouse(string name); 
    void setName(string name);
    string getName() const; 
    void addProgrammer(Programmer* programmer);
    void removeProgrammer(Programmer* programmer); 
    double getSalaryOfAProgrammer(Programmer* programmer) const;
    double getHighestSalary() const; 
    double getLowestSalary() const; 
    double getSumsalary() const; 
    void displayInfoOfAProgrammer(Programmer* programmer) const;
    void display() const; 
}; 
#endif