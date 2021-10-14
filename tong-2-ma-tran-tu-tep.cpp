Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
tệp văn bản "matran-A.txt", ma trận Bmxn để trong tệp văn bản "matran-B.txt".
Đưa các ma trận ra màn hình theo định dạng hàng, cột.
Yêu cầu thêm:
1) Sử dụng toán tử nhập >> để đọc vào ma trận từ tệp;
2) Sử dụng toán tử xuất << để đưa ma trận ra màn hình theo định dạng hàng, cột;
3) Sử dụng toán tử + để cộng 2 ma trận và trả về ma trận tổng;
4) Có thể tự động khởi tạo kích thước bằng 0.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong ma tran
class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m,n;

    public:
        MaTran();
        MaTran operator+(MaTran &mt2);

        //Ham ban
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream& operator<<(ostream &cout,MaTran &mt);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong ma tran
    MaTran A,B,C;

    //Tao 2 doi tuong tep vao
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    //Doc 2 ma tran tu tep vao doi tuong ma tran
    finA>>A;
    finB>>B;

    //Cong 2 ma tran
    C = A + B;

    //Dua ra
    cout<<"Ma tran A:\n"<<A;
    cout<<"\n\nMa tran B:\n"<<B;
    cout<<"\n\nMa tran C = A + B:\n"<<C;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator+(MaTran &mt2)
{
    MaTran tong;

    //Neu 2 ma tran cung kich thuoc thi cong
    if(m==mt2.m && n==mt2.n)
    {
        tong.m = m;
        tong.n = n;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                tong.a[i][j] = a[i][j] + mt2.a[i][j];
    }
    else cout<<"Hai ma tran khong cung kich thuoc, khong cong duoc.";

    //Tra ve ma tran tong
    return tong;
}

//Ham ban
ifstream& operator>>(ifstream &fin,MaTran &mt)
{
    //Doc vao kich thuoc ma tran tu tep
    fin>>mt.m>>mt.n;

    //Doc cac phan tu cua ma tran tu tep
    for(int i=0;i<mt.m;i++)
        for(int j=0;j<mt.n;j++)
            fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout,MaTran &mt)
{
    for(int i=0;i<mt.m;i++)
    {
        //Dua ra hang i
        for(int j=0;j<mt.n;j++)
            printf("%6d",mt.a[i][j]);

        //Xuong dong
        cout<<endl;
    }

    return cout;
}

