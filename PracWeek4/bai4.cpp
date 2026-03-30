#include<iostream>
#include<ctime>
#include<cstdlib>
#include<math.h>

class cArray{
    private:
        int *arr;
        int length; 
    public:
    cArray(){
        arr = new int[1]; 
        length = 0; 
    }
    cArray(int len){
        arr = new int[len]; 
        length = len; 
    }
    ~cArray(){
        std::cout << "Deconstructure\n"; 
        delete[] arr; 
    }
    cArray(const cArray& other){
        std::cout << "Copy" << std::endl; 
        length = other.length; 
        arr = new int[length];
        for(int i = 0; i < length; i ++){
            arr[i] = other.arr[i]; 
        } 
    }
    void random(){
        for(int i = 0;i < length; i++){
            arr[i] = rand() % 101; 
        }
    }
    friend std::ostream &operator<<(std::ostream &out, const cArray &ar); 
    int count(int target);
    bool ins(); 
    int findMinOdd(); 
    int findMaxFactor(); 
    void sortArr(); 
};
std::ostream &operator<<(std::ostream &out, const cArray &ar){
    for(int i = 0;i < ar.length;i ++){
        out << ar.arr[i] << " "; 
    }
    std::cout << "\n"; 
    return out; 
}
int cArray::count(int target){
    int cnt = 0; 
    for(int i = 0;i < length; i ++){
        if(arr[i] == target){
            cnt ++; 
        }
    }
    return cnt; 
}
bool cArray::ins(){
    bool in = true; 
    for(int i = 0; i < length - 1; i ++){
        if(arr[i] > arr[i + 1]){
            in = false; 
        }
    }
    return in; 
}
int cArray::findMinOdd(){
    int min = 101; 
    for(int i = 0; i < length; i ++){
        if(arr[i] < min && arr[i] % 2 == 1){
            min = arr[i]; 
        }
    }
    return min; 
}
bool inspectFactor(int number){
    if(number < 2){
        return false; 
    }
    if(number == 2){
        return true; 
    }
    if(number % 2 == 0){
        return false; 
    }
    for(int i = 3; i <= sqrt(number); i += 2){
        if(number % i == 0){
            return false; 
        }
    }
    return true; 
}
int cArray::findMaxFactor(){
    int max = -1; 
    for(int i = 0; i < length; i++){
        if(arr[i] > max && inspectFactor(arr[i])){
            max = arr[i]; 
        }
    }
    return max; 
}
void swap(int &a, int &b){
    int temp = a; 
    a = b; 
    b = temp; 
}
int partition(int *arr, int left, int right){
    int mid = (left + right) / 2; 
    int value_at_mid = arr[mid]; 
    while(left <= right){
        while(left >= 0 && left <= right && arr[left] < value_at_mid){
            left ++; 
        }
        while(right >= 0 && left <= right && arr[right] > value_at_mid){
            right --; 
        }
        if(left <= right){
            swap(arr[left], arr[right]); 
            left ++; 
            right --; 
        }
    }
    return left; 
}
void quickSort(int *arr, int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right); 

        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot, right);  
    }
}
void cArray::sortArr(){
    quickSort(arr, 0, length - 1); 
}; 
int main(){
    cArray arr(100); 
    arr.random(); 
    std::cout << arr; 
    std:: cout << arr.count(23) << std::endl; 
    std:: cout << arr.findMaxFactor() << std::endl;
    std:: cout << arr.findMinOdd() << std::endl; 
    std:: cout << "Ascending ?: " << arr.ins() << std::endl;
    arr.sortArr(); 
    std::cout << arr;
    cArray b = arr; 
    return 0;  
}
