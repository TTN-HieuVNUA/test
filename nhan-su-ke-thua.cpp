//HO TEN:   Tran Van Hieu
//MASV:     637630
//LOP:      K63ATTT
//DE:
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
class NhanSu
{
    private:
        char hoTen[100];
        int maSo;
    public:
        void nhap();
        void hien();
};

class GiaoVien:public NhanSu
{
    private:
        char monHoc[100];
    public:
        void nhap();
        void hien();
};

class CBQL:public NhanSu
{
    private:
        char chucVu[100];
    public:
        void nhap();
        void hien();
};

class NVPV:public NhanSu
{
    private:

    public:
        void nhap();
        void hien();
};
//==== chuong trinh chinh
int main(){

    cout << endl;
    return 0;
}
//==== dinh nghia ham====
void NhanSu::nhap()
{
    cout<<"\nnhap vao ten: ";
    scanf(" "); cin.get(hoTen,sizeof(hoTen));
    cout<<"\nnhap vao ma so: ";
    cin>>maSo;
}

void NhanSu::hien()
{
    cout<<"\nten nhan su: "<<hoTen<<"\nma so: "<<maSo;
}

void GiaoVien::nhap()
{
    NhanSu::nhap();
    cout<<"\nten mon hoc: ";
    scanf(" "); cin.get(monHoc,sizeof(monHoc));
}

void GiaoVien::hien()
{
    NhanSu::hien();
    cout<<"\nten mon hoc: "<<monHoc;
}

void CBQL::nhap()
{
    NhanSu::nhap();
    cout<<"\nchuc vu: ";
    scanf(" "); cin.get(chucVu,sizeof(chucVu));
}

void CBQL::hien()
{
    NhanSu::hien();
    cout<<"\nchuc vu: "<<chucVu;
}

void NVPV::nhap()
{
    NhanSu::nhap();
}

void NVPV::hien()
{
    NhanSu::hien();
}
