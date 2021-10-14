//DE:       tinh tong 2 phan so
#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>

using namespace std;
class PhanSo
{
    private:
        int tuSo, mauSo;

    public:
        PhanSo();
        PhanSo(int tuSo, int mauSo);
        void Nhap();
        int UCLN(int tuSo, int mauSo, int min);
        PhanSo toiGian();
        void Show();
        PhanSo Cong(PhanSo &ps1);

};

//==== chuong trinh chinh
int main()
{
    // tao 2 doi tuong phan so
    PhanSo ps1, ps2;

    // nhap phan so
    ps1.Nhap();
    ps2.Nhap();

    // cong va toi gian phan so
    ps1.Cong(ps2).toiGian().Show();

    cout << endl;
    return 0;
}
//==== dinh nghia ham====
PhanSo::PhanSo()
{

}

PhanSo::PhanSo(int tuSo, int mauSo)
{
    this->tuSo = tuSo;
    this->mauSo = mauSo;
}

void PhanSo::Nhap()
{
    cout<<"phan so: ";
    cin>>tuSo>> mauSo;
}

int PhanSo::UCLN(int tuSo, int mauSo, int min)
{
    if(tuSo % min==0 && mauSo % min==0)
    {
        return min;
    }
    else
    {
        min--;
        return UCLN(tuSo, mauSo, min);
    }
}

PhanSo PhanSo::toiGian()
{
    int min = fmin(this->tuSo, this->mauSo);
    int ucln = UCLN(this->tuSo, this->mauSo, min);

    return PhanSo(this->tuSo/ucln, this->mauSo/ucln);
}

void PhanSo::Show()
{
    cout<<this->tuSo<<"/"<<this->mauSo;
}

PhanSo PhanSo::Cong(PhanSo &ps1)
{
    int tuSoMoi = this->tuSo*ps1.mauSo + ps1.tuSo*this->mauSo;
    int mauSoMoi = this->mauSo*ps1.mauSo;

    return PhanSo(tuSoMoi, mauSoMoi);
}
