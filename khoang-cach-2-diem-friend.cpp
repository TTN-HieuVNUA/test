Bài 19(lthdtbai19.cpp): Cho điểm A(x1,y1) và điểm B(x2,y2). Tính khoảng cách AB.
1) Sử dụng toán tử nhập >> để nhập vào tọa độ;
2) Sử dụng toán tử xuất << để đưa tọa độ ra màn hình;
3) Có thể tự động khởi tạo tạo độ bằng 0 hoặc khởi tạo bằng 2 giá trị cho trước.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop diem trong mat phang
class Diem
{
    private:
        float x,y;

    public:
        Diem();
        Diem(float x, float y);
        float tinhKC(Diem &d2);

        //Ham ban
        friend istream& operator>>(istream &cin,Diem &d);
        friend ostream& operator<<(ostream &cout,Diem &d);
};

//===Chuong trinh chinh===
int main()
{
    //Tao 2 doi diem trong mat phang
    Diem A,B;

    cout<<"Nhap vao diem A:\n";
    cin>>A;
    cout<<"Nhap vao diem B:\n";
    cin>>B;

    cout<<"\nDiem A"<<A;
    cout<<"\nDiem B"<<B;
    printf("\nKhoang cach AB = %0.1f",A.tinhKC(B));

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
Diem::Diem():x(0),y(0)
{

}

Diem::Diem(float x, float y):x(x),y(y)
{

}

float Diem::tinhKC(Diem &d2)
{
    return sqrt((d2.x-x)*(d2.x-x) + (d2.y-y)*(d2.y-y));
}

//Ham ban, ham thong thuong khong nam tron doi tuong
istream& operator>>(istream &cin,Diem &d)
{
    cout<<"Nhap toa do (dang x y): ";
    cin>>d.x>>d.y;

    return cin;
}

ostream& operator<<(ostream &cout,Diem &d)
{
    cout<<"("<<d.x<<","<<d.y<<")";

    return cout;
}

