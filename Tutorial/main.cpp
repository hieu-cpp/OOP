#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Encapsulation: đóng gói

class SinhVien
{
    private:
    // cac thuoc tinh khac se su dung rieng cho tung object mot, rieng static no se la chung cho ca class
        string id, ten, ngay_sinh;
        double gpa;
        static int dem;
    public:
        SinhVien(); // constructor: ham khoi tao, chay ngay khi goi class
        SinhVien(string, string, string, double); //cung la contructor, neu khi goi class co tham so thi thay vi goi contructor tren no se goi ham contructor nay
        void nhapThongTin();
        void inThongTin();
        void tangDem();
        int getDem();
        ~SinhVien(); //destructor: ham huy
};
int SinhVien::dem = 0;
void SinhVien::tangDem()
{
    ++dem;
}
int SinhVien::getDem()
{
    return this->dem;
}
void SinhVien::nhapThongTin()
{
    // tu dong tang id ma khong can nhap
    ++dem;
    this->id = "SV" + string(3-to_string(dem).length(), '0') + to_string(dem);
    // SV001, SV002
    cin.ignore(); // khong bi troi lenh getline
    cout<<"Nhap ten: ";
    getline(cin, this->ten);
    cout<<"Nhap ngay sinh: ";
    cin>>this->ngay_sinh;
    cout<<"Nhap GPA: ";
    cin>>this->gpa;
}
void SinhVien::inThongTin()
{
    cout<<this->id<<" "<<this->ten<<" "<<this->ngay_sinh<<" "<<fixed<<setprecision(2)<<this->gpa<<endl;
}
SinhVien::SinhVien()
{

}
SinhVien::SinhVien(string student_code, string name, string birthday, double point)
{
    this->id = student_code;
    this->ten = name;
    this->ngay_sinh = birthday;
    this->gpa = point;
}
SinhVien::~SinhVien()
{

}
int main()
{
//    SinhVien x;
//    x.tangDem(); // dem=1
//    x.tangDem(); // dem=2
//    SinhVien y;
//    cout<<y.getDem()<<endl; // output = 2
    // tuc la bien static se la cua chung tat ca obj

    int n; cin>>n;
    SinhVien a[100];
    for(int i=0; i<n; i++)
        a[i].nhapThongTin();
    for (int i=0; i<n; i++)
        a[i].inThongTin();
}
