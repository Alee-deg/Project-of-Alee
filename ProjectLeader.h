#ifndef PROJECTLEADER_H
#define PROJECTLEADER_H
#include "Programmer.h"
#include<unordered_set>
class ProjectLeader : public Programmer{
    private:
    unordered_set<Programmer*> theTeam; 
    public:

    ProjectLeader(); 
    ProjectLeader(string name, string numberID, double salary, string language); 

    void addProgrammer(Programmer* programmer); 
    void removeProgrammer(Programmer* programmer);
     
    double calSumSalaryOfMember() const;

    void display() const override; 
    void displayMembers() const; 
}; 
#endif