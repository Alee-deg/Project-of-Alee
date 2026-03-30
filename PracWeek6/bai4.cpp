#include <iostream>
#include <string>
using namespace std;

class student {
protected:
    string numberId;
    string name;
    string address;
    float average;
    int totalCredit;

public:
    student() : student("", "", "", 0, 0) {}

    student(string id, string name, string add, float avg, int tolCre)
        : numberId(id), name(name), address(add), average(avg), totalCredit(tolCre) {}

    student(const student& other)
        : numberId(other.numberId), name(other.name), address(other.address),
          average(other.average), totalCredit(other.totalCredit) {}

    virtual ~student() {
        cout << "student destructor\n";
    }

    virtual void input() {
        cout << "Enter numberID\n";
        getline(cin, numberId);

        cout << "Enter name\n";
        getline(cin, name);

        cout << "Enter address\n";
        getline(cin, address);

        cout << "Enter totalCredits\n";
        cin >> totalCredit;

        cout << "Enter average\n";
        cin >> average;
        cin.ignore();
    }

    virtual void output() const {
        cout << "numberID: " << numberId << "\n";
        cout << "Name: " << name << "\n";
        cout << "Address: " << address << "\n";
        cout << "TotalCredits: " << totalCredit << "\n";
        cout << "Average: " << average << "\n";
    }

    virtual float getAverage() const = 0;
    virtual int getTotalCredits() const = 0;
    virtual float getGraduateExamScore() const = 0;
    virtual float getThesisScore() const = 0;
};

class college : public student {
private:
    float graduationExamScore;

public:
    college() : college("", "", "", 0, 0, 0) {}

    college(string id, string name, string add, float avg, int tolCre, float graduationExamScore)
        : student(id, name, add, avg, tolCre), graduationExamScore(graduationExamScore) {}

    college(const college& other)
        : student(other), graduationExamScore(other.graduationExamScore) {}

    ~college() override {
        cout << "college destructor\n";
    }

    void input() override {
        student::input();
        cout << "Enter graduateExamScore\n";
        cin >> graduationExamScore;
        cin.ignore();
    }

    void output() const override {
        student::output();
        cout << "GraduateExamScore: " << graduationExamScore << "\n";
    }

    float getAverage() const override {
        return average;
    }

    int getTotalCredits() const override {
        return totalCredit;
    }

    float getGraduateExamScore() const override {
        return graduationExamScore;
    }

    float getThesisScore() const override {
        return 0.0f;
    }
};

class university : public student {
private:
    string thesisName;
    float thesisScore;

public:
    university() : university("", "", "", 0, 0, "", 0) {}

    university(string id, string name, string add, float avg, int tolCre, string thesisName, float thesisScore)
        : student(id, name, add, avg, tolCre), thesisName(thesisName), thesisScore(thesisScore) {}

    university(const university& other)
        : student(other), thesisName(other.thesisName), thesisScore(other.thesisScore) {}

    ~university() override {
        cout << "university destructor\n";
    }

    void input() override {
        student::input();
        cout << "Enter thesisName\n";
        getline(cin, thesisName);

        cout << "Enter thesisScore\n";
        cin >> thesisScore;
        cin.ignore();
    }

    void output() const override {
        student::output();
        cout << "ThesisName: " << thesisName << "\n";
        cout << "ThesisScore: " << thesisScore << "\n";
    }

    float getAverage() const override {
        return average;
    }

    int getTotalCredits() const override {
        return totalCredit;
    }

    float getThesisScore() const override {
        return thesisScore;
    }

    float getGraduateExamScore() const override {
        return 0.0f;
    }
};

int main() {
    int n = 2;
    student* st[100];

    for (int i = 0; i < n; i++) {
        student* x = new college();
        x->input();
        st[i] = x;
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        student* y = new university();
        y->input();
        st[i + n] = y;
        cout << "\n";
    }

    for (int i = 0; i < 2 * n; i++) {
        st[i]->output();
        cout << "\n";
    }


    for(int i = 0;i < 2*n; i ++){
        if(dynamic_cast<college*>(st[i])){
            if(st[i] -> getTotalCredits() > 110 && st[i] -> getAverage() > 5.0 && st[i] -> getGraduateExamScore() > 5){
                st[i] -> output(); 
            }
            else{
                cout << "Fall" << endl; 
                st[i] -> output(); 
            }
        }
        else{
            if(st[i] -> getTotalCredits() > 145 && st[i] -> getAverage() > 5.0 && st[i] -> getThesisScore() > 5){
                st[i] -> output(); 
            }
            else{
                cout << "Fall" << endl; 
                st[i] -> output(); 
            }
        }
    }
    float max = st[0] -> getAverage(); 
    student* temp = st[0]; 
    for(int i = 1; i < 2*n; i++){
        if(st[i] -> getAverage() > max){
            max = st[i] -> getAverage(); 
            temp = st[i]; 
        }
    }
    cout << "Student has the higest score\n"; 
    temp -> output(); 
    for (int i = 0; i < 2 * n; i++) {
        delete st[i];
    }
    return 0;
}