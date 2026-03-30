#include<iostream>
#include<initializer_list>

using namespace std; 

template<typename T>
class vector{
    private:
    T* data; 
    size_t sz; 
    size_t cap; 
    public:
    vector() : data(nullptr), sz(0), cap(0){}
    vector(size_t n) : sz(n), cap(n){
        data = new T[cap]; 
        for(size_t i = 0;i < sz;i  ++){
            data[i] = T(); 
        }
    } 
    vector(initializer_list<T> init){
        sz = init.size(); 
        cap = sz; 
        data = new T[cap]; 

        size_t i = 0; 
        for(const T& val : init){
            data[i ++] = val; 
        }
    }
    vector(size_t n, const T& value): sz(n), cap(n){
        data = new T[cap]; 
        for(size_t i = 0; i < sz; i ++){
            data[i] = value; 
        }
    }
    vector(const vector& other):sz(other.sz), cap(other.cap){
        data = new T[cap]; 
        for(size_t i = 0; i < sz;i ++){
            data[i] = other.data[i]; 
        }
    }
    vector& operator=(const vector& other){
        if(this == &other) return *this; 
        delete[] data; 
        sz = other.sz; 
        cap = other.cap; 
        data = new T[cap]; 
        for(size_t i = 0;i < sz; i ++){
            data[i] = other.data[i]; 
        }
        return *this; 
    }
    ~vector(){
        cout << "Destructure" << "\n"; 
        delete[] data; 
    }
    size_t size() const{
        return sz; 
    }
    size_t capacity() const{
        return cap; 
    }
    bool empty() const{
        return sz == 0; 
    }
    void reserve(size_t newCap){
        if(newCap <= cap) return; 
        T* newData = new T[newCap]; 
        for(size_t i = 0; i < sz; i++){
            newData[i] = data[i]; 
        }
        delete[] data; 
        data = newData; 
        cap = newCap; 
    }
    void reSize(size_t newSize){
        if(newSize > cap){
            reserve(newSize); 
        }
        if(newSize > sz){
            for(size_t i = sz;i < newSize; i ++){
                data[i] = T(); 
            }
        }
        sz = newSize; 
    }
    void reSize(size_t newSize, const T& value){
        if(newSize > cap){
            reserve(newSize); 
        }
        if(newSize > sz){
            for(size_t i = sz; i < newSize; i++){
                data[i] = value; 
            }
        }
        sz = newSize; 
    }
    void push_back(const T& value){
        if(sz == cap){
            reserve(cap == 0 ? 1 : cap*2);    
        }
        data[sz++] = value; 
    }
    void pop_back(){
        if(sz > 0) sz --; 
    }
    T &operator[](size_t index){
        return data[index]; 
    }
    const T& operator[](size_t index) const{
        return data[index]; 
    }
    T& front(){
        return data[0];
    }
    T& back(){
        return data[sz - 1]; 
    }
    void clear(){
        sz = 0; 
    }
    T* begin(){
        return data; 
    }
    T* end(){
        return data + sz; 
    }
    const T* begin() const{
        return data; 
    }
    const T* end() const {
        return data + sz; 
    }
    void insert(size_t pos, const T& value){
        if(pos > sz) return; 

        if(sz == cap){
            reserve(cap == 0 ? 1 : cap * 2); 
        }
        for(size_t i = sz; i > pos; i --){
            data[i] = data[i - 1]; 
        }
        data[pos] = value; 
        sz++; 
    }
    void erase(size_t pos){
        if(pos >= sz) return; 

        for(size_t i = pos; i + 1 < sz; i ++){
            data[i] = data[i + 1]; 
        }
        sz --; 
    }
    void print() const{
        for(size_t i = 0; i < sz; i ++){
            cout << data[i] << " "; 
        }
        cout << "\n"; 
    }
}; 

int main(){
    vector<int> v; 
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 9}; 
    v1.print(); 
    v.push_back(10); 
    v.push_back(20); 
    v.push_back(30); 
    v.print(); 

    v.insert(1, 99); 
    v.print();

    v.erase(2); 
    v.print(); 

    for(auto* x = v.begin(); x != v.end(); ++x){
        cout << *x << " "; 
    }
    cout << "\n"; 
    return 0; 
}