Bài 43(lthdtbai43.cpp): Viết chương trình quản lý nhân sự của một trường học;
nhân sự gồm có giảng viên và sinh viên; giảng viên có mã gv, họ tên và số bài báo;
sinh viên có mã sv, họ tên và điểm tbc. Nhập vào một số nhân sự trong đó có cả giảng viên
và sinh viên. Đưa ra thông tin của các nhân sự đã nhập kèm theo đánh giá:
giảng viên đánh giá là giỏi nếu số bài báo >=5, sinh viên đánh giá là giỏi
nếu điểm TBC>=8.0. Y/c cài đặt đa hình động.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop nhan su
class NhanSu
{
    private:
        char hoTen[31];

    public:
        virtual void nhap();
        virtual void hien();
};

//Khai bao lop giang vien
class GiangVien:public NhanSu
{
    private:
        char maGV[11];
        int soBB;

    public:
        void nhap();
        void hien();
};

//Khai bao lop sinh vien
class SinhVien:public NhanSu
{
    private:
        char maSV[11];
        float diemTBC;

    public:
        void nhap();
        void hien();
};

//Ham thong thuong
NhanSu* nhapDL();
void hienTT(NhanSu* ns);

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    NhanSu *dsNhanSu[100];
    char traLoi;
    int n=0;

    do
    {
        //Nhap thong tin
        dsNhanSu[n++] = nhapDL();

        //Hoi nhap tiep hay la khong?
        cout<<"\nNhap tiep khong(c/k)? ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');

    //Dua ra thong tin da nhap
    cout<<"\nDanh sach nhan su da nhap la:";
    for(int i=0;i<n;i++)
    {
        printf("\nNhan su thu %d:\n",i+1);
        hienTT(dsNhanSu[i]);
        cout<<endl;
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham==
void NhanSu::nhap()
{
    cout<<"Nhap vao ho ten: ";
    scanf(" "); cin.get(hoTen,sizeof(hoTen));
}

void NhanSu::hien()
{
    cout<<"\n\tHo ten: "<<hoTen;
}

void GiangVien::nhap()
{
    cout<<"Nhap vao ma giang vien: ";
    cin>>maGV;
    NhanSu::nhap();
    cout<<"Nhap so bai bao: ";
    cin>>soBB;
}

void GiangVien::hien()
{
    cout<<"Giang vien:";
    cout<<"\n\tMa giang vien: "<<maGV;
    NhanSu::hien();
    cout<<"\n\tSo bai bao: "<<soBB;
}


void SinhVien::nhap()
{
    cout<<"Nhap vao ma sinh vien: ";
    cin>>maSV;
    NhanSu::nhap();
    cout<<"Nhap diem TBC: ";
    cin>>diemTBC;
}

void SinhVien::hien()
{
    cout<<"Sinh vien:";
    cout<<"\n\tMa sinh vien: "<<maSV;
    NhanSu::hien();
    printf("\n\tDiem TBC: %0.1f",diemTBC);
}

//Ham thong thuong
NhanSu* nhapDL()
{
    NhanSu *ns;
    char chon;

    cout<<"Lua chon danh muc de nhap thong tin (1-Giang Vien,2-Sinh Vien): ";
    cin>>chon;

    if(chon=='1') ns = new GiangVien;
    else ns = new SinhVien;

    //Dung da hinh dong de nhap thong tin muc da chon
    ns->nhap();

    //Tra ve thong tin muc da nhap
    return ns;
}

void hienTT(NhanSu* ns)
{
    //Dung da hinh dong dua ra thong tin
    ns->hien();
}
