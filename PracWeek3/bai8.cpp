#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int n; 
class cNhanVienSX{
    string name; 
    string id; 
    string dateOfBirth; 
    int products;
    int costOfAnProduct;
    public:
    cNhanVienSX()
    : cNhanVienSX("", "", "", 0, 0){}
    cNhanVienSX(string name, string id, string Birth)
    : cNhanVienSX(name, id, Birth, 0, 0){}
    cNhanVienSX(string name, string id)
    : cNhanVienSX(name, id, "", 0, 0){}
    ~cNhanVienSX(){
        cout << "Deconstructure" << endl; 
    }
    cNhanVienSX(cNhanVienSX &other){
        name = other.name; 
        id = other.id;
        dateOfBirth = other.dateOfBirth; 
        products = other.products; 
        costOfAnProduct = other.costOfAnProduct;  
    }
    cNhanVienSX(string name, string id, string Birth, int producted, int cost):
    name(name), 
    id(id),
    dateOfBirth(Birth),
    products(producted),
    costOfAnProduct(cost){}
    // Get
    string getId(){return id;}
    string getName(){return name;}
    string getDateOfBirth(){return dateOfBirth;}
    int getProducts(){return products;}
    int getCost(){return costOfAnProduct;}
    int getSalary(){
        return products*costOfAnProduct; 
    }
    int getBirthYear(){
        string a, b, c; 
        stringstream ss(getDateOfBirth()); 
        ss >> a >> b >> c; 
        return stoi(c); 
    }
    int getAge(){
        return 2026 - getBirthYear(); 
    }
    // Set
    void setId(string id){this -> id = id;}
    void setName(string name){this -> name = name;}
    void setDateOfBirth(string dob){this -> dateOfBirth = dob;}
    void setProducts(int products){this -> products = products;}
    void setCost(int cost){this -> costOfAnProduct = cost;}
    //input, output
    friend istream &operator>>(istream &in, cNhanVienSX &a);
    friend ostream &operator<<(ostream &out, cNhanVienSX &a); 
}; 
istream &operator>>(istream &in, cNhanVienSX &a){
    cout << "Enter in order.\n"; 
    cout << "1.name\t2.id\t3.dateOfBirth\t4.Products\t5.costOfAnProducts\n"; 
    in.ignore(); 
    getline(in, a.name);
    getline(in, a.id);  
    getline(in, a.dateOfBirth);
    in >> a.products; 
    in >> a.costOfAnProduct;  
    return in;
}
ostream &operator<<(ostream &out, cNhanVienSX &a){
    out << a.name << " " << a.id << " " << "/" << a.dateOfBirth << "/" <<" " << a.products << " " << a.costOfAnProduct << "\n"; 
    cout << a.getSalary() << endl; 
    return out; 
}
void enter(cNhanVienSX *employees){
    for(int i = 0; i < n;i ++){
        cin >> employees[i]; 
    }
}
void traverse(cNhanVienSX *employees){
    for(int i = 0;i < n; i++){
        cout << employees[i]; 
    }
}
int getMinSalary(cNhanVienSX *employees){
    int min = employees[0].getSalary(); 
    for(int i = 1; i < n;i ++){
        if(employees[i].getSalary() < min){
            min = employees[i].getSalary(); 
        }
    }
    return min; 
}
int sumSalary(cNhanVienSX *employees){
    int sum = 0; 
    for(int i = 0; i < n; i ++){
        sum += employees[i].getSalary(); 
    }
    return sum; 
}
int getMaxAge(cNhanVienSX *employees){
    int max = employees[0].getAge(); 
    for(int i = 1; i < n; i ++){
        if(employees[i].getAge() > max){
            max = employees[i].getAge(); 
        }
    }
    return max; 
}

int main(){
    cout << "Enter quantities Employees\n"; 
    cin >> n; 
    cNhanVienSX employees[n]; 
    enter(employees); 
    traverse(employees); 
    cout << getMinSalary(employees) << endl; 
    cout << sumSalary(employees) << endl; 
    cout << getMaxAge(employees) << endl; 
    return 0; 
}