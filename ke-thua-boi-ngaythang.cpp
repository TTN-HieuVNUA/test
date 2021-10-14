//Ho ten: Le Tuan Tu
//MaSV: 652231
//Lop:
//De:
/*
Thời điểm là một loại ngày tháng và cũng là một loại thời gian nhưng có thêm địa điểm.
Ngày tháng có ngày, tháng, năm. Thời gian có giờ và phút.
Nhập vào một thời điểm, đưa ra thời điểm đó ở dạng Địa điểm, dd/mm/yy - h:mm.
Ví dụ: Hà Nội, 30/09/19 – 14:27.
Y/c viết hàm tạo không có đối số và có đối số cho tất cả các lớp.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop doi tuong ngay thang
class NgayThang
{
    private:
        int ngay,thang,nam;

    public:
        NgayThang();
        NgayThang(int ngay,int thang,int nam);
        void nhap();
        void hien();
};

//Khai bao lop doi tuong thoi gian
class ThoiGian
{
    private:
        int gio,phut;

    public:
        ThoiGian();
        ThoiGian(int gio,int phut);
        void nhap();
        void hien();
};

//Khai bao lop doi tuong thoi diem
class ThoiDiem:public NgayThang,public ThoiGian
{
    private:
        char diaDiem[31];

    public:
        ThoiDiem();
        ThoiDiem(int ngay,int thang,int nam,int gio,int phut,const char *diaDiem);
        void nhap();
        void hien();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong thoi diem
    ThoiDiem td;

    //Tuong tac
    cout<<"Nhap vao 1 thoi diem:\n";
    td.nhap();

    cout<<"\nThoi diem da nhap la:\n";
    td.hien();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
NgayThang::NgayThang():ngay(0),thang(0),nam(0)
{

}

NgayThang::NgayThang(int ngay,int thang,int nam):ngay(ngay),thang(thang),nam(nam)
{

}

void NgayThang::nhap()
{
    char kt;

    cout<<"dang (dd/mm/yy): ";
    cin>>ngay>>kt>>thang>>kt>>nam;
}

void NgayThang::hien()
{
    printf("%02d/%02d/%d",ngay,thang,nam);
}

ThoiGian::ThoiGian():gio(0),phut(0)
{

}

ThoiGian::ThoiGian(int gio,int phut):gio(gio),phut(phut)
{

}

void ThoiGian::nhap()
{
    char kt;

    cout<<"(dang h:mm): ";
    cin>>gio>>kt>>phut;
}

void ThoiGian::hien()
{
    printf("%d:%02d",gio,phut);
}

ThoiDiem::ThoiDiem():NgayThang(),ThoiGian()
{
    strcpy(diaDiem,"");
}

ThoiDiem::ThoiDiem(int ngay,int thang,int nam,int gio,int phut,const char *diaDiem):NgayThang(ngay,thang,nam),ThoiGian(gio,phut)
{
    strcpy(this->diaDiem,diaDiem);
}

void ThoiDiem::nhap()
{
    cout<<"Nhap vao dia diem: ";
    scanf(" ");cin.get(diaDiem,sizeof(diaDiem));
    cout<<"Nhap vao ngay thang ";
    NgayThang::nhap();
    cout<<"Nhap vao thoi gian ";
    ThoiGian::nhap();
}

void ThoiDiem::hien()
{
    cout<<diaDiem<<", ";
    NgayThang::hien();
    cout<<" - ";
    ThoiGian::hien();
}

