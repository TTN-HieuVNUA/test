//Ho ten : Le Minh Hieu
//MaSV : 637627
//Lop : K63ATTT
/*De: Tính diện tích các hình: Hình tam giác biết 3 cạnh a,b,c; hình chữ nhật biết 2 cạnh a,b; hình tròn biết bán kính r; hình trụ biết bán kính r và chiều cao h.
Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo dài với chiều cao h.
Nhập vào một số hình tùy theo yêu cầu, trong đó cả cả hình tam giác, chữ nhật, tròn, trụ.
Đưa ra diện tích các hình đã nhập. Yêu cầu cài đặt đa hình động.
*/
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

//Lop co so
class Hinh
{
    private:

    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
};

//Lop dan xuat
class HinhTG:public Hinh
{
    private:
        float a,b,c;

    public:
        void nhap();
        float tinhDT();
};

class HinhCN:public Hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
};

class HinhTron:public Hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

class HinhTru:public HinhTron
{
    private:
        float h;

    public:
        void nhap();
        float tinhDT();
};


//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhTG::nhap()
{
    do
    {
        cout<<"Nhap vao 3 canh tam giac: ";
        cin>>a>>b>>c;

        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 so da nhap khong phai 3 canh tam gaic. Nhap lai.\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

float HinhTG::tinhDT()
{
    if(a+b>c && a+c>b & b+c>a)
    {
        float p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    return 0;
}

void HinhCN::nhap()
{
    cout<<"Nhap vao 2 canh hinh chu nhat: ";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
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

void HinhTru::nhap()
{
    //Nhap ban kinh
    HinhTron::nhap();

    //Nhap chieu cao
    cout<<"Nhap vao chieu cao: ";
    cin>>h;
}

float HinhTru::tinhDT()
{
    return 2*HinhTron::tinhDT() + HinhTron::tinhCV()*h;
}
