#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Forward declaration
class SinhVien;
class GiaoVien;

class SinhVien
{
    friend class GiaoVien; // khi do class GiaoVien se co the truy cap vao private props cua class SinhVien

    private:
    // cac thuoc tinh khac se su dung rieng cho tung object mot, rieng static no se la chung cho ca class
        string id, ten, ngay_sinh;
        double gpa;
        static int dem;
    public:
        SinhVien(); // constructor: ham khoi tao, chay ngay khi goi class
        SinhVien(string, string, string, double); //cung la contructor, neu khi goi class co tham so thi thay vi goi contructor tren no se goi ham contructor nay
        void nhapThongTin();
        void inThongTin(); // member function
        friend void inThongTin(SinhVien); // friend function: cho phep ham ben ngoai truy cap vao bien private cua obj
        friend void chuanHoaTen(SinhVien &);
        ~SinhVien(); //destructor: ham huy
};
int SinhVien::dem = 0;
void inThongTin(SinhVien a)
{
    cout << a.id << " " << a.ten << endl;
}
void chuanHoaTen(SinhVien &a)
{
    // nguyen VAN A => Nguyen Van A
    string res = "";
    stringstream ss(a.ten);
    string token;
    while(ss>>token)
    {
        res+=toupper(token[0]);
        for(int i=1; i<token.length(); i++)
            res += tolower(token[i]);
        res += " ";
    }
    res.erase(res.length()-1);
    a.ten = res;
}
void SinhVien::nhapThongTin()
{
    // tu dong tang id ma khong can nhap
    ++dem;
    this->id = "SV" + string(3-to_string(dem).length(), '0') + to_string(dem);
    // SV001, SV002
    cout<<"Nhap ten: "; getline(cin, this->ten);
    cout<<"Nhap ngay sinh: ";cin>>this->ngay_sinh;
    cout<<"Nhap GPA: "; cin>>this->gpa;
    cin.ignore(); // khong bi troi lenh getline
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
class GiaoVien
{
    private:
        string khoa;
    public:
        void update(SinhVien&);
};
void GiaoVien::update(SinhVien &a)
{
    a.gpa = 3.4;
}
int main()
{
    SinhVien x;
    x.nhapThongTin();
    GiaoVien y;
    y.update(x);
    chuanHoaTen(x);
    inThongTin(x);
    x.inThongTin();

    return 0;
}
