#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

using namespace std; 

class book{
    protected:
    string entryDate; 
    string bookCode; 
    float unitPrice; 
    int quantity; 
    string publishingHouse; 
    public:
    book():book("", "", 0, 0, ""){}
    book(string entryD, string bC, float uP, int quti, string pubH):entryDate(entryD), bookCode(bC), unitPrice(uP), quantity(quti), publishingHouse(pubH){}
    book(const book& other){
        bookCode = other.bookCode; 
        unitPrice = other.unitPrice; 
        quantity = other.quantity; 
        publishingHouse = other.publishingHouse;
        entryDate = other.entryDate;  
    }
    virtual ~book(){
        cout << "Destructor book" << "\n"; 
    }
    virtual void input(){
        cout << "Enter entryDate" << "\n"; 
        getline(cin, entryDate); 
        cout << "Enter bookCode" << "\n"; 
        getline(cin, bookCode); 
        cout << "Enter uniPrice" << "\n"; 
        cin >> unitPrice; 
        cout << "Enter quantity" << "\n"; 
        cin >> quantity; 
        cin.ignore(); 
        cout << "Enter publishingHouse" << "\n"; 
        getline(cin, publishingHouse); 
    }
    virtual void output() const{
        cout << "bookCode: " << bookCode << "\n"; 
        cout << "unitPrice: " << unitPrice << "\n"; 
        cout << "quantity: " << quantity << "\n"; 
        cout << "publishingHouse: " << publishingHouse << "\n";  
    }
    virtual float revenue() const{
        return unitPrice*quantity; 
    }
}; 
class textBook :public book{
    private:
    string state; 
    public:
    textBook():textBook("","", 0, 0, "", ""){}
    textBook(string entryD, string cB, float uP, int qua, string pubH,string state):book(entryD, cB, uP, qua, pubH), state(state){}
    textBook(const textBook &other):book(other), state(other.state){}
    ~textBook(){
        cout << "deconstructure textBook" << "\n"; 
    }
    void input() override{
        book::input(); 
        cout << "Enter state: " << "\n"; 
        getline(cin, state); 
    }
    void output() const override{
        book::output(); 
        cout << "State: " << state << endl; 
    }
    float revenue() const override{
        return (state == "new" ? quantity*unitPrice : quantity*unitPrice*0.5); 
    }
}; 
class referenceBook: public book{
    private:
    float tax; 
    public:
    referenceBook():referenceBook("", "", 0, 0, "", 0){}
    referenceBook(string entryD, string cB, float uP, int qua, string pubH, float tax):book(entryD, cB, uP, qua, pubH), tax(tax){}
    referenceBook(const referenceBook& other):book(other), tax(other.tax){}
    ~referenceBook(){
        cout << "Destructure" << "\n"; 
    }
    void input() override {
        book::input(); 
        cout << "Enter tax" << endl; 
        cin >> tax; 
        cin.ignore(); 
    }
    void output() const override {
        book::output(); 
        cout << "Tax: " << tax << endl; 
    }
    float revenue() const override{
        return unitPrice*quantity + tax; 
    }
}; 


int main(){
    vector<book*> bok; 
    int n = 3; 
    cout << "Enter information for TextBook" << "\n"; 
    for(int i = 0; i < n; i ++){
        book *en = new textBook(); 
        en -> input(); 
        bok.push_back(en); 
        cout << "\n"; 
    }
    cout << "Enter information for ReferenceBook" << "\n"; 
    for(int i = 0;i < n; i++){
        book *de = new referenceBook(); 
        de -> input();
        bok.push_back(de); 
        cout << "\n"; 
    }
    float revTB = 0;
    float revRB = 0;  
    float sumRev = 0; 
    for(auto x : bok){
        x -> output(); 
        sumRev += x -> revenue(); 
        if(dynamic_cast<referenceBook*>(x)) revRB += x -> revenue(); 
        if(dynamic_cast<textBook*>(x)) revTB += x -> revenue(); 
    }
    cout << "Sum revenue: " << sumRev << "\n";
    cout << "Revenue of TextBook" << revTB << "\n"; 
    cout << "Revenue of ReferenceBook" << revRB << "\n"; 

    for(auto x : bok) delete x; 
    return 0;  
}
