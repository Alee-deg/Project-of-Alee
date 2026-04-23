#include "Softwarehouse.h"
#define INF 2*1e9

SoftwareHouse::SoftwareHouse():SoftwareHouse(""){}
SoftwareHouse::SoftwareHouse(string name){
    this -> setName(name); 
}

void SoftwareHouse::setName(string name){this -> name = name;}
string SoftwareHouse::getName() const{return this -> name;}

void SoftwareHouse::addProgrammer(Programmer* programmer){
    if(this -> theStaff.find(programmer) == this -> theStaff.end()){
        if(programmer -> isMemberOfDepartment()){
            cout << "The programmer is curently a member of another Department" << endl; 
        }
        else{
            this -> theStaff.insert(programmer); 
            programmer -> attendDepartment(this); 
            cout << "Done!" << endl; 
        }
    }
    else{
        cout << "The Programmer is already exists" << endl; 
    }
}

void SoftwareHouse::removeProgrammer(Programmer* programmer){
    if(this -> theStaff.find(programmer) == this -> theStaff.end()){
        cout << "The programmer is not exists" << endl; 
    }
    else{
        auto it = this -> theStaff.find(programmer); 
        programmer -> leaveDepartment(); 
        theStaff.erase(programmer); 
        cout << "Done!" << endl; 
    }
}

double SoftwareHouse::getSalaryOfAProgrammer(Programmer* programmer) const{return programmer -> getSalary();}

double SoftwareHouse::getSumsalary() const{
    double sum = 0; 
    for(auto &member : this -> theStaff){
        sum += member -> getSalary(); 
    }
    return sum; 
}

double SoftwareHouse::getHighestSalary() const{
    double maxSalary = -INF; 
    for(auto &member : this -> theStaff){
        if(maxSalary < member -> getSalary()){
            maxSalary = member -> getSalary(); 
        }
    }
    return maxSalary; 
}

double SoftwareHouse::getLowestSalary() const{
    double minSalary = INF; 
    for(auto &member : this -> theStaff){
        if(minSalary > member -> getSalary()){
            minSalary = member -> getSalary(); 
        }
    }
    return minSalary; 
}

void SoftwareHouse::displayInfoOfAProgrammer(Programmer* programmer) const{
    if(this -> theStaff.find(programmer) == this -> theStaff.end()){
        cout << "The Programmer is not exists" << endl; 
    }
    else{
        programmer -> display(); 
        cout << "Done!" << endl; 
    }
    cout << endl; 
}

void SoftwareHouse::display() const{
    for(auto member : theStaff){
        member -> display(); 
    }
    cout << endl; 
}
