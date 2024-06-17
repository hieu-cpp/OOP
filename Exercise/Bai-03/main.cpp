#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
long long UCLN(long long a, long long b)
//Greatest Common Divisor: uoc chung lon nhat
{
    if (b==0) return a;
    return UCLN(b, a%b);
}
long long BCNN(long long a, long long b)
{
    return (a/UCLN(a, b))*b;
}
class PhanSo
{
    private:
        long long tu, mau;
    public:
        PhanSo(long long tu, long long mau);
        friend istream& operator >> (istream &in, PhanSo &p);
        friend ostream& operator << (ostream &out, PhanSo p);
        friend PhanSo operator + (PhanSo a, PhanSo b);
        friend PhanSo operator - (PhanSo a, PhanSo b);
        friend PhanSo operator * (PhanSo a, PhanSo b);
        friend PhanSo operator / (PhanSo a, PhanSo b);
        void rutgon();
};
PhanSo::PhanSo(long long tu=1, long long mau=1)
{
    this->tu = tu;
    this->mau = mau;
}
istream& operator >> (istream& in, PhanSo& p)
{
    cout<<"Nhap tu so: "; cin>>p.tu;
    cout<<"Nhap mau so: "; cin>>p.mau;
    return in;
}
ostream& operator << (ostream& out, PhanSo p)
{
    out << p.tu << "/" << p.mau<<endl;
    return out;
}
PhanSo operator+(PhanSo a, PhanSo b)
{
    PhanSo tong;
    long long mau_chung = BCNN(fabs(a.mau), fabs(b.mau));
    tong.tu = a.tu * (mau_chung/a.mau) + b.tu * (mau_chung / b.mau);
    tong.mau = mau_chung;
    tong.rutgon();
    return tong;
}
PhanSo operator-(PhanSo a, PhanSo b)
{
    PhanSo hieu;
    long long mau_chung = BCNN(fabs(a.mau), fabs(b.mau));
    hieu.tu = a.tu * (mau_chung/a.mau) - b.tu * (mau_chung / b.mau);
    hieu.mau = mau_chung;
    hieu.rutgon();
    return hieu;
}
PhanSo operator*(PhanSo a, PhanSo b)
{
    PhanSo tich(a.tu*b.tu, a.mau*b.mau);
    tich.rutgon();
    return tich;
}
PhanSo operator/(PhanSo a, PhanSo b)
{
    PhanSo thuong(a.tu*b.mau, a.mau*b.tu);
    thuong.rutgon();
    return thuong;
}
void PhanSo::rutgon()
{
    long long g = UCLN(fabs(this->tu), fabs(this->mau));
    this->tu /= g;
    this->mau /= g;
}
int main()
{
    PhanSo p;
    cin>>p;
    p.rutgon();
    cout<<p;
    PhanSo q;
    cin>>q;
    cout << p+q;
    cout << p-q;
    cout << p*q;
    cout << p/q;
    return 0;
}
