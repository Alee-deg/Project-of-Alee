#include "Employee.h"
#include "Programmer.h"
#include "ProjectLeader.h"
#include "Softwarehouse.h"
#include<iostream>

int main(){
    //Create a new organisation
    SoftwareHouse *sh = new SoftwareHouse("Objects-R-Us");
    //Create some new programmers
    Programmer *p1 = new Programmer("John", "123", 2000, "Ada"); 
    Programmer *p2 = new Programmer("Ken", "234", 2500, "C++"); 
    Programmer *p3 = new Programmer("Peter", "456", 3000, "Java");
    //Create some new project leaders
    ProjectLeader *p11 = new ProjectLeader("Jon", "567", 4000, "C");
    ProjectLeader *p12 = new ProjectLeader("Jessie", "789", 4000, "Java"); 
    //Assign each programmer to a project leader
    p11->addProgrammer(p3); 
    p11->addProgrammer(p2);
    p12->addProgrammer(p1); 
    //Hire each programmer and project leader
    sh->addProgrammer(p1); 
    sh->addProgrammer(p2);
    sh->addProgrammer(p3);
    sh->addProgrammer(p11);
    sh->addProgrammer(p12); 
    sh->display(); 
    //display Member
    p11->displayMembers();
    //getSumSalary of Project
    cout << p11 -> calSumSalaryOfMember() << endl; 
    //getSumSalary of Software House
    cout << sh->getSumsalary() << endl; 
    //get programmer has the highest salary
    cout << sh->getHighestSalary() << endl; 
    //get programmer has the lowest salary
    cout << sh->getLowestSalary() << endl; 
    //remove member is not exists in project
    p11->removeProgrammer(p1);
    //remove member is exists in project
    p11->removeProgrammer(p2); 
    //remove member in sh
    sh->removeProgrammer(p1); 
    //remove member is not exists in sh
    Programmer* p4 = new Programmer; 
    sh -> removeProgrammer(p4); 
    //display
    sh->display(); 
    delete sh, p1, p2, p3, p4, p11, p12; 
    return 0; 
}