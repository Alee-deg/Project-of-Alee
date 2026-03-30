#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std; 

class ChuyenXe{
    protected:
    string maSo, hoTen, soXe; 
    double doanhThu; 
    public:
    ChuyenXe(string ms = "", string ht = "", string sx = "",double dt = 0):
    maSo(ms), hoTen(ht), soXe(sx), doanhThu(dt){}
    virtual ~ChuyenXe(){
        cout << "Giai phong Chuyenxe: " << maSo << endl; 
    }
    virtual void nhap(){
        cout << "Nhap ma so chuyen: "; cin >> maSo; 
        cin.ignore(); 
        cout << "Nhap ho ten tai xe: "; getline(cin, hoTen); 
        cout << "Nhap so xe: "; cin >> soXe; 
        cout << "Nhap doanh thu: "; cin >> doanhThu; 
    } 
    virtual void xuat() const{
        cout << "MS: " << left << setw(10) << maSo
             << "| Ten: " << setw(20) << hoTen
             << "| Xe: " << setw(10) << soXe 
             << "| DT: " << fixed << setprecision(0) << doanhThu; 
    }
    void xuat(string loiNhan) const{
        cout << "[" << loiNhan << "] "; 
        this -> xuat(); 
    }
    double getDoanhThu() const {return doanhThu; }
}; 
class ChuyenXeNoiThanh: public ChuyenXe{
    private:
    int soTuyen; 
    double soKm; 
    public:
    ChuyenXeNoiThanh():ChuyenXe(), soTuyen(0), soKm(0){}
    void nhap() override{
        ChuyenXe::nhap(); 
        cout << "So tuyen: "; cin >> soTuyen; 
        cout << "So km di duoc: "; cin >> soKm; 
    }
    void xuat() const override{
        ChuyenXe::xuat(); 
        cout << " | Tuyen: " << setw(5) << soTuyen
             << " | Km: " << soKm << "km" << endl; 
    }
}; 
class ChuyenXeNgoaiThanh: public ChuyenXe{
    private:
    string noiDen; 
    int soNgay; 
    public:
    ChuyenXeNgoaiThanh(): ChuyenXe(), noiDen(""), soNgay(0){}
    void nhap() override{
        ChuyenXe::nhap(); 
        cin.ignore(); 
        cout << "Noi den: "; getline(cin, noiDen); 
        cout << "So ngay di duoc: "; cin >> soNgay;  
    }
    void xuat() const override{
        ChuyenXe::xuat(); 
        cout << " | Den: " << setw(10) << noiDen
             << " | Ngay: " << soNgay << " ngay" << endl; 
    }
}; 
int main(){
    vector<ChuyenXe*> dsChuyenXe; 
    int n = 2; 
    
    cout << "--- NHAP THONG TIN CHUYEN XE ---\n";
    for(int i = 0; i < n; i++){
        cout << "\nNoi thanh " << i + 1 << ":\n"; 
        ChuyenXe* c = new ChuyenXeNoiThanh(); 
        c -> nhap();   
        dsChuyenXe.push_back(c); 
    }
    for(int i = 0; i < n; ++i){
        cout << "\nNgoaiThanh " << i + 1 << ":\n"; 
        ChuyenXe* c = new ChuyenXeNgoaiThanh(); 
        c -> nhap(); 
        dsChuyenXe.push_back(c); 
    }
    cout << "\n---DANH SACH CAC CHUYEN XE ---\n"; 
    double tongDT = 0, dtNoiThanh = 0, dtNgoaiThanh = 0; 

    for(auto cx : dsChuyenXe){
        cx -> xuat("LOG"); 

        tongDT += cx -> getDoanhThu(); 

        if(dynamic_cast<ChuyenXeNoiThanh*>(cx)) dtNoiThanh += cx -> getDoanhThu();
        if(dynamic_cast<ChuyenXeNgoaiThanh*>(cx)) dtNgoaiThanh += cx -> getDoanhThu();
    }
    cout << "\n" << string(50, '-') << endl; 
    cout << "Tong doanh thu noi thanh: " << dtNoiThanh << endl; 
    cout << "Tong doanh thu ngoai thanh: " << dtNgoaiThanh << endl; 
    cout << "** TONG DOANH THU CHUNG: " << tongDT << "**" << endl; 

    for(auto cx : dsChuyenXe) delete cx; 

    return 0; 
}