#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Employee.h"
class SoftwareHouse; 
class ProjectLeader; 
class Programmer : public Employee{
    private:
    string language; 
    SoftwareHouse* softwareHouse;
    ProjectLeader* projectLeader; 
    public:
    Programmer(); 
    Programmer(string name, string numberID, double salary, string language,
               SoftwareHouse* isMember = NULL, ProjectLeader* isMemberOfProject = NULL); 

    void setLanguage(string language);
    string getLanguage() const;

    void setIsMember(SoftwareHouse* house);  
    SoftwareHouse* getIsMember() const; 

    void setIsMemberOfProject(ProjectLeader *memberOfProject); 
    ProjectLeader* getIsMemberOfProject() const; 

    void attendDepartment(SoftwareHouse* softwareHouse);
    void leaveDepartment(); 
    bool isMemberOfDepartment(); 

    void attendProject(ProjectLeader* projectLeader);
    void leaveProject();     
    bool isMemberOfProject(); 
     
    void display() const override;
}; 
#endif