//Ho ten: Le Tuan Tu
//MaSV: 653321
//Lop: K65CNPMA
//De:
/*
Bài 15(lthdtbai15.cpp): Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c. Ba cạnh a,b,c có thể nhập vào
từ bàn phím hoặc từ tệp văn bản.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop tam giac
class TamGiac
{
    private:
        float a,b,c;

    public:
        void nhap();
        void docTep(const char *tenTep);
        float tinhDT();
        float tinhCV();
};


//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong tam giac
    TamGiac tg;

    tg.nhap();

    printf("Dien tich tam giac la: %0.1f",tg.tinhDT());
    printf("\nChu vi tam giac la: %0.1f",tg.tinhCV());

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void TamGiac::nhap()
{
    do
    {
        cout<<"Nhap vao 3 canh cua tam giac: ";
        cin>>a>>b>>c;

        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 so da nhap khong phai 3 canh tam giac. Nhap lai!\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

void TamGiac::docTep(const char *tenTep)
{
    //Tao doi tuong tep vao
    ifstream fin("tamgiac.txt");

    //Doc 3 canh tam giac tu tep
    fin>>a>>b>>c;

    if(a+b<=c || a+c<=b || b+c<=a)
        cout<<"3 so tren tep tamgiac.txt khong phai 3 canh tam giac.";
}

float TamGiac::tinhDT()
{
    //Neu gia tri trong a,b,c khong hop le thi tra ve 0
    if(a+b<=c || a+c<=b || b+c<=a) return 0;

    //Neu hop le, tinh va tra ve dien tich
    float p = (a+b+c)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float TamGiac::tinhCV()
{
    //Neu gia tri trong a,b,c khong hop le thi tra ve 0
    if(a+b<=c || a+c<=b || b+c<=a) return 0;

    //Neu hop le, tinh va tra ve chu vi
    return a+b+c;
}

