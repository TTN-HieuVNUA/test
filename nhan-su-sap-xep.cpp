Bài 39b (lthdtbai39b.cpp): Một nhân sự luôn có họ tên và ngày sinh.
Sinh viên là một loại nhân sự có thêm mã sinh viên và điểm tbc.
Đọc danh sách n sinh viên từ tệp văn bản "sinhvien.txt".
Sắp xếp danh sách sinh viên theo điểm tbc giảm dần. Đưa ra màn hình danh sách sinh viên đã nhập
có kèm theo đánh gia, nếu điểm tbc >= 8.0 thì đánh giá là sinh viên giỏi.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop
class NhanSu
{
    private:
        char hoTen[31];
        char ngaySinh[11];

    public:
        void thietLapTT(const char *hoTen,const char *ngaySinh);
        void hien();
};

class SinhVien:public NhanSu
{
    private:
        char maSV[10];
        float diemTBC;

    public:
        void thietLapTT(const char *maSV,const char *hoTen,const char *ngaySinh,float diemTBC);
        void hien();
        float layDiemTBC();
};

//===chuong trinh chinh===
int main()
{
    //Tao doi tuong tep vao
    ifstream fin("sinhvien.txt");

    //Khai bao bien
    char maSV[10];
    char hoTen[31];
    char ngaySinh[11];
    float diemTBC;
    int n;
    char tg[3]="";

    //Doc so luong sv tu tep
    fin>>n;

    //Tao mang dong n doi tuong sv de chua n sv tu tep
    SinhVien *a = new SinhVien[n];

    //Doc danh sach n sv tu tep vao n doi tuong sv
    cout<<"Danh sach sinh vien ban dau doc tu tep la:";
    for(int i=0;i<n;i++)
    {
        //Doc enter de chuyen con tro tep xuong dong duoi
        fin.getline(tg,sizeof(tg));

        //Doc va tach cac thong tin cua sv thu i
        fin.getline(maSV,sizeof(maSV),'\t');
        fin.getline(hoTen,sizeof(hoTen),'\t');
        fin.getline(ngaySinh,sizeof(ngaySinh),'\t');
        fin>>diemTBC;

        //Dua thong tin sv doc duoc tu tep vao doi tuong sv
        a[i].thietLapTT(maSV,hoTen,ngaySinh,diemTBC);

        //Dua ra man hinh
        printf("\nSinh vien thu %d:\n",i+1);
        a[i].hien();
        cout<<endl;
    }

    //Sap xep danh sach sv theo diem tbc giam dan
    for(int i=0;i<n-1;i++)
        for(int j=n-1;j>i;j--)
            if(a[j].layDiemTBC()>a[j-1].layDiemTBC())
            {
                SinhVien tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }

    cout<<"\n\nDanh sach sinh vien sau khi sap xep theo diem tbc giam dan la:";
    for(int i=0;i<n;i++)
    {
        printf("\nSinh vien thu %d:\n",i+1);
        a[i].hien();
        cout<<endl;
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void NhanSu::thietLapTT(const char *hoTen,const char *ngaySinh)
{
    strcpy(this->hoTen,hoTen);
    strcpy(this->ngaySinh,ngaySinh);
}

void NhanSu::hien()
{
    cout<<"\nHo ten: "<<hoTen;
    cout<<"\nNgay sinh: "<<ngaySinh;
}

void SinhVien::thietLapTT(const char *maSV,const char *hoTen,const char *ngaySinh,float diemTBC)
{
    NhanSu::thietLapTT(hoTen,ngaySinh);
    strcpy(this->maSV,maSV);
    this->diemTBC = diemTBC;
}

void SinhVien::hien()
{
    cout<<"Ma sinh vien: "<<maSV;
    NhanSu::hien();
    cout<<"\nDiem TBC: "<<diemTBC;
    if(diemTBC>=8) cout<<"\nDay la sinh vien gioi!";
}

float SinhVien::layDiemTBC()
{
    return diemTBC;
}

