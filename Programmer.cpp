#include "Programmer.h"

Programmer::Programmer():Programmer("", "", 0, ""){}; 
Programmer::Programmer(string name, string numberID, double salary, string language,
                       SoftwareHouse* isMember, ProjectLeader* isMemberOfProject):
Employee(name, numberID, salary){
    this -> setLanguage(language); 
    this -> setIsMemberOfProject(isMemberOfProject); 
    this -> setIsMember(isMember); 
}

void Programmer::setLanguage(string language){this -> language = language;}
string Programmer::getLanguage() const{return this -> language;}

void Programmer::setIsMember(SoftwareHouse* softwareHouse){this -> softwareHouse = softwareHouse;}  
SoftwareHouse* Programmer::getIsMember() const{return this -> softwareHouse;}

void Programmer::setIsMemberOfProject(ProjectLeader *projectLeader){this -> projectLeader = projectLeader;} 
ProjectLeader* Programmer::getIsMemberOfProject() const{return this -> projectLeader;} 

void Programmer::attendDepartment(SoftwareHouse* softwareHouse){this -> setIsMember(softwareHouse);}
void Programmer::leaveDepartment(){this -> setIsMember(NULL);}
bool Programmer::isMemberOfDepartment(){return this -> getIsMember() != NULL;}

void Programmer::attendProject(ProjectLeader* projectLeader){this -> projectLeader = projectLeader;}
void Programmer::leaveProject(){this -> setIsMemberOfProject(NULL);}
bool Programmer::isMemberOfProject(){return this -> getIsMemberOfProject() != NULL;}

void Programmer::display() const{
    Employee::display(); 
    cout << "Language   :" << this -> getLanguage() << endl; 
}


