Viết chương trình tính thể tích và diện tích bề mặt của hình trụ có bán kính r và chiều cao h.
Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo dài với chiều cao h.
Y/c viết hàm tạo không đối số và hàm tạo có đối số cho tất cả các lớp.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop hinh tron
class HinhTron
{
    private:
        float r;

    public:
        HinhTron();
        HinhTron(float r);
        void nhap();
        float tinhDT();
        float tinhCV();
};

//Khai bao lop hinh tru
class HinhTru: public HinhTron
{
    private:
        float h;

    public:
        HinhTru();
        HinhTru(float r,float h);
        void nhap();
        float tinhTT();
        float tinhDT();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong hinh tru
    HinhTru h;

    cout<<"Nhap vao kich thuoc hinh tru:\n";
    h.nhap();

    printf("\nThe tich hinh tru la: %0.1f",h.tinhTT());
    printf("\nDien tich hinh tru la: %0.1f",h.tinhDT());

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop hinh tron
HinhTron::HinhTron():r(0)
{

}

HinhTron::HinhTron(float r):r(r)
{

}

void HinhTron::nhap()
{
    cout<<"Nhap vao ban kinh: ";
    cin>>r;
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

//Ham thanh vien lop hinh tru
HinhTru::HinhTru():HinhTron(),h(0)
{

}

HinhTru::HinhTru(float r,float h):HinhTron(r),h(h)
{

}

void HinhTru::nhap()
{
    //Nhap bk
    HinhTron::nhap();

    //Nhap chieu cao
    cout<<"Nhap vao chieu cao: ";
    cin>>h;
}

float HinhTru::tinhTT()
{
    return HinhTron::tinhDT()*h;
}

float HinhTru::tinhDT()
{
    return 2*HinhTron::tinhDT() + HinhTron::tinhCV()*h;
}
