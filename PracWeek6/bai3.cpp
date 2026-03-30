#include<iostream>
#include<string>
#include<string.h>
#include<vector>

using namespace std; 

class transaction{
    protected:
    string codeTransaction; 
    string dateTransaction; 
    float unitPrice; 
    int quantities; 
    public:
    transaction():transaction("", "", 0, 0){}
    transaction(string cT, string dT, float uP, int quan):codeTransaction(cT), dateTransaction(dT), unitPrice(uP), quantities(quan){}
    transaction(const transaction& other){
        codeTransaction = other.codeTransaction; 
        dateTransaction = other.dateTransaction; 
        unitPrice = other.unitPrice; 
        quantities = other.quantities; 
    }
    virtual ~transaction() {
        cout << "Destructure Transaction" << codeTransaction << "\n"; 
    }
    virtual void input(){
        cout << "Enter codeTransaction" << "\n"; 
        getline(cin, codeTransaction); 
        cout << "Enter dateTransaction" << "\n"; 
        getline(cin, dateTransaction);  
        cout << "Enter unitPrice" << "\n"; 
        cin >> unitPrice; 
        cout << "Enter quantities" << "\n"; 
        cin >> quantities; 
        cin.ignore(); 
    }
    virtual void output() const{
        cout << "codeTransaction" << " " << codeTransaction << " " << "dateTransaction" << " " << dateTransaction
             << " " << "unitPrice" << " " << unitPrice << " " << "Quantities" << " " << quantities << endl; 
    }
    virtual float revenue() const{
        return unitPrice*quantities; 
    }
}; 
class goldTransaction: public transaction{
    private:
    string typeGold; 
    public:
    goldTransaction():goldTransaction("", "", 0, 0, ""){}
    goldTransaction(string cT, string dT, float uP, int quan, string tG):transaction(cT, dT, uP, quan), typeGold(tG){}
    goldTransaction(const goldTransaction &other):transaction(other), typeGold(other.typeGold){}
    ~goldTransaction() override{
        cout << "Destructure goldTransaction\n"; 
    }
    void input() override{
        transaction::input(); 
        cout << "Enter typeGold\n";
        getline(cin, typeGold); 
    }
    void output() const override{
        transaction::output(); 
        cout << "typedGold" << " " << typeGold << endl; 
    }
    float revenue() const override{
        return unitPrice*quantities; 
    }
}; 
class moneyTransaction: public transaction{
    private:
    float exchangRate; 
    string typeMoney; 
    public:
    ~moneyTransaction() override{
        cout << "Destructure moneyTr" << "\n"; 
    }
    moneyTransaction():moneyTransaction("", "", 0, 0, 0, ""){} 
    moneyTransaction(string cT, string dT, float uP, int quan, float exR, string tM):transaction(cT, dT, uP, quan), exchangRate(exR), typeMoney(tM){}
    moneyTransaction(const moneyTransaction& other):transaction(other), exchangRate(other.exchangRate), typeMoney(other.typeMoney){}
    void input() override{
        transaction::input(); 
        cout << "Enter typeMoney" << endl; 
        getline(cin, typeMoney); 
        cout << "Enter exchageRate" << endl; 
        cin >> exchangRate; 
        cin.ignore(); 
    }
    void output() const override{   
        transaction::output(); 
        cout << "exchangeRate: " << exchangRate << endl; 
        cout << "typeMoney: " << typeMoney << endl; 
     }
    float revenue() const override{
        if(typeMoney == "VN"){
            return unitPrice*quantities; 
        }   
        else{
            return unitPrice*quantities*exchangRate; 
        }
    }
}; 

int main(){
    vector<transaction*> re;
    int n = 3; 
    for(int i = 0;i < 3 ;i ++){
        transaction *c = new goldTransaction(); 
        c -> input(); 
        re.push_back(c); 
        cout << "\n"; 
    }
    for(int j = 0;j < 3;j ++){
        transaction *x = new moneyTransaction(); 
        x -> input(); 
        re.push_back(x); 
        cout << "\n"; 
    }
    float minMT = 1e9; 
    float maxGT = -1; 
    for(auto x : re){
        if(dynamic_cast<moneyTransaction*>(x) && x -> revenue() < minMT){
            minMT = x -> revenue(); 
        }
        if(dynamic_cast<goldTransaction*>(x) && x -> revenue() > maxGT){
            maxGT = x -> revenue(); 
        }
    }
    for(auto x : re){
        if(x -> revenue() > 1000000){
            x -> output(); 
            cout << "\n"; 
        }
    }
    cout << "Min revenue of moneyTransaction: " << minMT << endl;
    cout << "Max revenue of goldTransaction: " << maxGT << endl;
    for(auto x : re) delete x; 
    return 0; 
}