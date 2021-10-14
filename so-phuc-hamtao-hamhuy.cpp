Tính tổng hai số phức. Yêu cầu:
1) Sử dụng toán tử + để cộng 2 số phức
2) Sử dụng toán tử nhập >> để nhập vào số phức
3) Sử dụng toán tử xuất << để đưa ra số phức
4) Viết 1 hàm tạo không đối số để khởi tạo phần thực và ảo bằng 0
5) Viết 1 hàm tạo một đối số để khởi tạo phần thực bằng đối số và ảo bằng 0
6) Viết 1 hàm tạo hai đối số để khởi tạo phần thực và ảo bằng đối số
7) Viết 1 hàm hàm hủy
8) Viết 1 hàm tạo sao chép
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop so phuc
class SoPhuc
{
    private:
        float a,b;

    public:
        SoPhuc(); //Ham tao khong doi so
        SoPhuc(float a); //Ham tao mot doi so
        SoPhuc(float a,float b); //Ham tao hai doi so
        ~SoPhuc(); //Ham huy
        SoPhuc(SoPhuc &p); //Ham tao sao chep

        SoPhuc operator+(SoPhuc p2);

        //Ham ban
        friend istream& operator>>(istream &cin,SoPhuc &p);
        friend ostream& operator<<(ostream &cout,SoPhuc &p);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuon so phuc
    SoPhuc p1,p2(-5),tong(2,6);

    //Nhap
    cout<<"Nhap vao so phuc p1:\n";
    cin>>p1; //Uoc gi cin>>p1;
    cout<<"Nhap vao so phuc p2:\n";
    cin>>p2;

    //Cong
    tong = p1 + p2; //Uoc gi co the p1 + p2

    //Dua ra
    cout<<"\nSo phuc p1 = "<<p1; //Uoc gi cout<<p1;
    cout<<"\nSo phuc p2 = "<<p2;
    cout<<"\nSo phuc p1 + p2 = "<<tong;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SoPhuc::SoPhuc():a(0),b(0)
{
    cout<<"\nHam tao khong doi so da thuc hien.";
}

SoPhuc::SoPhuc(float a):a(a),b(0)
{
    cout<<"\nHam tao mot doi so da thuc hien.";
}

SoPhuc::SoPhuc(float a,float b):a(a),b(b)
{
    cout<<"\nHam tao hai doi so da thuc hien.";
}

SoPhuc::~SoPhuc()
{
    cout<<"\nHam huy da thuc hien.";
}

SoPhuc::SoPhuc(SoPhuc &p)
{
    a = p.a;
    b = p.b;

    cout<<"\nHam tao sao chep da thuc hien.";
}

SoPhuc SoPhuc::operator+(SoPhuc p2)
{
    SoPhuc tg;

    tg.a = a + p2.a;
    tg.b = b + p2.b;

    return tg;
}

//Ham ban, ham thong thuong, khong nam trong doi tuong
istream& operator>>(istream &cin,SoPhuc &p)
{
    cout<<"Nhap vao phan thuc, phan ao cua so phuc: ";
    cin>>p.a>>p.b;

    return cin;
}

ostream& operator<<(ostream &cout,SoPhuc &p)
{
    if(p.b>=0) cout<<p.a<<" + j"<<p.b;
    else cout<<p.a<<" - j"<<-p.b;

    return cout;
}


