#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Forward declaration
class SinhVien;

class SinhVien
{
    private:
        string id, ten, ngay_sinh;
        double gpa;
    public:
        // 1.nap chong toan tu (overload operator): ghi de lai cac logic da duoc dinh nghia san trong cpp
        // 1,1 nap chong toan tu nhap
        friend istream& operator >> (istream &in, SinhVien &a);
        /*
            istream: kieu tra ve istream
            istream &in: tham so thu nhat, co the dat bat ki ten gi khong nhat thiet la "in"
            SinhVien &a: tham so thu hai, do la toan tu nhap nen phai co tham chieu & de thay doi du lieu
        - NOTE: + co the thay cin >> n thi (cin ~ tham so thu nhat) va (n ~ tham so thu hai)
                + tham so la nhung gia tri truoc sau cua toan tu(operator)
        */
        // 1.2 nap chong toan tu xuat
        friend ostream& operator << (ostream &out, SinhVien a);
        // 1.3 nap chong toan tu so sanh gpa
        bool operator < (SinhVien another);
        /*
        - NOTE: + neu dung friend thi tham so truyen vao phai >= 2 do day la 1 ham "ben ngoai" pham vi class
                + con neu khai bao nhu ham so sanh tren thi do chinh la member function nen chi can truyen 1 param
                  vi du: x<y thi x se la SinhVien hien tai va dem di so sanh voi y (another)
                + tuong tu neu dung friend function thi x se la param thu nhat, y se la param thu hai
        */
        friend bool operator > (SinhVien a, SinhVien b);
        // khi do x = a, y = b
};
istream& operator >> (istream &in, SinhVien &a)
{
    cout <<"Nhap id: ";
    in>>a.id;
    cout<<"Nhap ten: "; in.ignore();
    getline(in, a.ten);
    cout <<"Nhap ngay sinh: ";
    in>>a.ngay_sinh;
    cout <<"Nhap diem: "; in>>a.gpa;
    return in;
}
ostream& operator << (ostream &out, SinhVien a)
{
    out <<a.id<< " " << a.ten<< " "<<a.ngay_sinh<< " " <<fixed<<setprecision(2)<<a.gpa<<endl;
    return out;
}
bool SinhVien::operator < (SinhVien another)
{
    // khi x < y thi this o day se la x, con another se la y
    return this->gpa < another.gpa;
}
bool operator > (SinhVien a, SinhVien b)
{
    // khi  x > y thi se truyen params a = x; b = y
    return a.gpa > b.gpa;
}
int main()
{
    int n; cin>>n; // o day n co data type la int duoc dinh nghia san va co the dung >> de nhap gia tri va << de xuat gia tri
    SinhVien x, y; // nhung khong co data type la SinhVien nen de dung toan tu >> va << thi phai nap chong toan tu
    cin >> x >> y;
    cout << x;
    if(x<y) cout <<"Yes";
    else cout<<"No";
    return 0;
}
