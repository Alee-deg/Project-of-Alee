#include "ProjectLeader.h"

ProjectLeader::ProjectLeader():ProjectLeader("","", 0, ""){}; 
ProjectLeader::ProjectLeader(string name, string numberID, double salary, string language):
Programmer(name, numberID, salary, language){};

void ProjectLeader::addProgrammer(Programmer* programmer){
    if(this -> theTeam.find(programmer) == this -> theTeam.end()){
        if(programmer -> isMemberOfProject()){
            cout << "The programmer is currently a member of another Project!" << endl; 
        }
        else{
            this -> theTeam.insert(programmer); 
            programmer -> attendProject(this); 
            cout << "Done!"<< endl; 
        }
    }
    else{
        cout << "The programmer is already into Project\n"; 
    }
}

void ProjectLeader::removeProgrammer(Programmer* programmer){
    if(this -> theTeam.find(programmer) == this -> theTeam.end()){
        cout << "The programmer is not exists\n";
        return;  
    }
    auto it = this -> theTeam.find(programmer); 
    theTeam.erase(it); 
    programmer -> leaveProject(); 
    cout << "Done!" << endl; 
}

double ProjectLeader::calSumSalaryOfMember() const{
    double sum = 0; 
    for(auto &member : theTeam){
        sum += member -> getSalary(); 
    }
    return sum;
}

void ProjectLeader::display() const{
    cout << "ProjectLeader\n";
    Programmer::display(); 
    cout << endl; 
}

void ProjectLeader::displayMembers() const{
    cout << "All member\n"; 
    for(auto member : theTeam){
        member->display(); 
    }
}