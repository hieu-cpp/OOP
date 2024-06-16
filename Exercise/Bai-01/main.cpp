#include <iostream>
#include <iomanip>
#include <math.h>
/*
Cho truoc lop doi tuong Diem gom hai thuoc tinh (x, y)
a. Toa lop doi tuong da cho
b. Dinh nghia luong nhap (istream) va luong xuat (ostream) cho doi tuong
c. Nhap vao 3 diem, tinh dien tich va chu vi cua tam giac duoc tao thanh boi 3 diem da cho.
*/

using namespace std;
class Diem
{
    public:
        void increaseDem();
        int getDem();
        friend istream &operator >> (istream &in, Diem &a);
        friend ostream &operator << (ostream &out, Diem a);
        double distance(Diem u);
        friend bool validTriangle(Diem a, Diem b, Diem c);
        friend double chuVi(Diem a, Diem b, Diem c);
        friend double dienTich(Diem a, Diem b, Diem c);
    private:
        double x, y;
        static int dem;
};
int main()
{
    Diem x, y, z;
    cin>>x>>y>>z;
    cout<<x<<y<<z;
    if(!validTriangle(x, y, z)) cout << "3 diem da cho khong tao thanh hinh tam giac";
    else
    {
        cout<<"Chu vi tam giac la: "<<fixed<<setprecision(4)<<chuVi(x, y, z)<<endl;
        cout<<"Dien tich tam giac la: "<<fixed<<setprecision(4)<<dienTich(x, y, z)<<endl;
    }
    return 0;
}
int Diem::dem = 0;
void Diem::increaseDem()
{
    this->dem += 1;
}
int Diem::getDem()
{
    return this->dem;
}
istream &operator >> (istream &in, Diem &a)
{
    a.increaseDem();
    cout<<"Nhap diem thu "<< a.getDem()<<endl;
    cout << "x = "; cin>> a.x;
    cout << "y = "; cin>> a.y;
    return in;
}
ostream &operator << (ostream &out, Diem a)
{
    out << "("<<a.x<<", "<<a.y<<")"<<endl;
    return out;
}
double Diem::distance(Diem u)
{
    return sqrt(pow(this->x - u.x, 2) + pow(this->y - u.y, 2));
}
bool validTriangle(Diem a, Diem b, Diem c)
{
    double AB, AC, BC;
    AB = a.distance(b);
    AC = a.distance(c);
    BC = b.distance(c);
    return AB + AC > BC && AB+BC>AC && AC+BC>AB;
}
double chuVi(Diem a, Diem b, Diem c)
{
    return a.distance(b) + a.distance(c) + b.distance(c);
}
double dienTich(Diem a, Diem b, Diem c)
{
    double nuaChuVi = chuVi(a, b, c) / 2.0;
    return sqrt(nuaChuVi * (nuaChuVi - a.distance(b)) * (nuaChuVi - a.distance(c)) * (nuaChuVi - b.distance(c)));
}
