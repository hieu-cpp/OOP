#include <iostream>
#include <iomanip>
/*
Cho truoc doi tuong so phuc gom 2 thuoc tinh a va b (a: phan thuc, b: phan ao) bieu dien voi phuc z = a + bi;
a. Tao lop doi tuong da cho
b. Dinh nghia luong nhap va xuat
c. Dinh nghia lai cac phep toan +, -, *, / cho doi tuong tren
*/
using namespace std;

class SoPhuc
{
    private:
        double a, b;
        static int dem;
    public:
        SoPhuc(double a=0, double b=0);
        friend istream &operator >> (istream &in, SoPhuc &z);
        friend ostream &operator << (ostream &out, SoPhuc z);
        double getPhanThuc()
        {
            return this->a;
        }
        double getPhanAo()
        {
            return this->b;
        }
        SoPhuc operator + (SoPhuc another);
        SoPhuc operator - (SoPhuc another);
        SoPhuc operator * (SoPhuc another);
        SoPhuc operator / (SoPhuc another);
};
istream &operator >> (istream &in, SoPhuc &z)
{
    cout<<"Nhap so phuc z :\nNhap phan thuc a = ";
    cin>>z.a;
    cout<<"Nhap phan ao b = "; cin>>z.b;
    return in;
}
ostream &operator << (ostream &out, SoPhuc z)
{

    cout<<"z = "<<z.a<<" + "<<z.b<<"i"<<endl;
    return out;
}
SoPhuc SoPhuc::operator + (SoPhuc another)
{
    SoPhuc tong(this->a + another.a, this->b+another.b);
    return tong;
}
SoPhuc SoPhuc::operator - (SoPhuc another)
{
    SoPhuc hieu(this->a - another.a, this->b-another.b);
    return hieu;
}
SoPhuc SoPhuc::operator * (SoPhuc another)
{
    double phanthuc = this->a*another.a - this->b*another.b;
    double phanao = this->a*another.b + this->b*another.a;
    SoPhuc tich(phanthuc, phanao);
    return tich;
}
SoPhuc SoPhuc::operator / (SoPhuc another)
{
    double phanthuc = (double) (this->a*another.a + this->b*another.b)/(another.a * another.a + another.b * another.b);
    double phanao = (double) (this->b*another.a - this->a*another.b)/(another.a * another.a + another.b * another.b);
    SoPhuc thuong(phanthuc, phanao);
    return thuong;
}
SoPhuc::SoPhuc(double a, double b)
{
    this->a = a;
    this->b = b;
}
int main()
{
    SoPhuc z1, z2;
    cin>>z1>>z2;
    cout<<z1<<z2;
    cout<<"Tong: "<<z1+z2<<endl;
    cout<<"Hieu: "<<z1-z2<<endl;
    cout<<"Tich: "<<z1*z2<<endl;
    if(z2.getPhanThuc() == 0 && z2.getPhanAo() == 0) cout<<"Khong ton tai phep chia"<<endl;
    else cout<<"Thuong: "<<z1/z2<<endl;
    return 0;
}
