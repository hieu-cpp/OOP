#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Encapsulation: đóng gói

class SinhVien
{
    private:
        string id, ten, ngay_sinh;
        double gpa;
    public:
        SinhVien(); // constructor: ham khoi tao, chay ngay khi goi class
        SinhVien(string, string, string, double); //cung la contructor, neu khi goi class co tham so thi thay vi goi contructor tren no se goi ham contructor nay
        void nhapThongTin();
        void inThongTin();
        double getGpa(); // lay ra gia tri private cua class
        void setGpa(double);
        string getName();
        ~SinhVien(); //destructor: ham huy
};
void SinhVien::nhapThongTin()
{
    cout<<"Nhap id: ";
    cin>>this->id;
    cin.ignore();
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
double SinhVien::getGpa()
{
    return this->gpa;
}
void SinhVien::setGpa(double gpa)
{
    this->gpa = gpa;
}
string SinhVien::getName()
{
    return this->ten;
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
bool comparatorGpa(SinhVien a, SinhVien b)
{
    return a.getGpa()>b.getGpa();
}
int main()
{
    int n; cin>>n;
    SinhVien a[100];
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap thong tin hoc sinh "<<i+1<<endl;
        a[i].nhapThongTin();
    }
    sort(a, a+n, comparatorGpa); // sort theo gpa
    for(int i=0; i<n; i++)
        a[i].inThongTin();
    // chinh sua private prop
    SinhVien x;
    x.setGpa(3.0)

//    string soSanh = soSanhGpa(a[0], a[1]) ? "lon" : "thap";
//    cout<<"Sinh vien "<<a[0].getName()<<" co gpa "<<soSanh<<" hon sinh vien "<<a[1].getName()<<endl;
    return 0;
}
