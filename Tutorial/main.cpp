#include <iostream>

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
        void xinChao()
        {
            cout<<"Hello"<<endl;
            printf("Id Sinh vien la: %d", id);
        }
        void diHoc();
        ~SinhVien(); //destructor: ham huy
};
// khai bao method
void SinhVien::diHoc()
{
    cout<<"Di hoc"<<endl;
}
SinhVien::SinhVien()
{
    cout<<"Ham khoi tao duoc goi!"<<endl;
}
SinhVien::SinhVien(string student_code, string name, string birthday, double point)
{
    cout<<"Ham khoi tao co tham so.\nMa sinh vien = "<<student_code<<". Ten = "<<name<<". Ngay sinh"<<birthday<<". GPA = "<<point<<endl;
    id = student_code;
}
SinhVien::~SinhVien()
{
    // Neu khai bao class trong 1 pham vi nhu la ham, if-else, while.... Khi ket thuc pham vi do thi destructor se duoc goi
    cout<<"destructor se duoc goi"<<endl;
}
void testDestructor()
{
    SinhVien x;
}
int main()
{
    testDestructor();
    SinhVien y("H313", "Nguyen Minh Hieu", "31-03-2005", 4.0);
    SinhVien x; // neu co contructor thi no se chay ham contructor
    y.xinChao();
    x.diHoc();

    return 0;
}
