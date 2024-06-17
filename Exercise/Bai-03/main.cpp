#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
long long GCD(long long a, long long b)
//Greatest Common Divisor: uoc chung lon nhat
{
    if (b==0) return a;
    return GCD(b, a%b);
}
class PhanSo
{
    private:
        long long tu, mau;
    public:
        PhanSo(long long tu, long long mau);
        friend istream& operator >> (istream &in, PhanSo &p);
        friend ostream& operator << (ostream &out, PhanSo p);
        void rutgon();
};
PhanSo::PhanSo(long long tu, long long mau)
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
    out << p.tu << "/" << p.mau;
    return out;
}

void PhanSo::rutgon()
{

    long long g = GCD(fabs(this->tu), fabs(this->mau));
    this->tu /= g;
    this->mau /= g;
}
int main()
{
    PhanSo p(1, 1);
    cin>>p;
    p.rutgon();
    cout<<p;
    return 0;
}
