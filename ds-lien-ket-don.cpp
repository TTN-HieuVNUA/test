Bài 32(lthdtbai32.cpp): Cho tệp văn bản "daysonguyen-bai32.txt" chứa dãy số nguyên,
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản, lưu dãy số trong
danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong danh sach lien ket don (DSLKD)
class SList
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F;

    public:
        SList();
        ~SList();
        void lastInsert(int x);
        void display();
        bool search(int x);
        bool remove(int x);
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong DSLKD
    SList list;

    //Tao 1 doi tuong tep vao
    ifstream fin("daysonguyen-bai32.txt");

    //Khai bao bien
    int x;

    //Doc day so tu tep luu vao DSLKD
    while(fin>>x) list.lastInsert(x);

    cout<<"Day so trong DSLKD la:\n";
    list.display();

    cout<<"\n\nNhap vao phan tu x: ";
    cin>>x;

    if(list.search(x))
    {
        //Xoa phan tu bang x
        list.remove(x);

        //Dua ra DSLKD sau xoa
        cout<<"\nDay so trong DSLKD sau khi xoa "<<x<<" la:\n";
        list.display();
    }
    else cout<<"\nTrong DSLKD khong co phan tu bang "<<x;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SList::SList():F(NULL)
{

}

SList::~SList()
{
    while(F)
    {
        node *P = F;
        F = F->link;
        delete P;
    }
}

void SList::lastInsert(int x)
{
    //1.Tao nut moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;


    //2.Noi nut moi vao sau nut cuoi
    if(F==NULL) F = N;
    else
    {
        //Tim toi nut cuoi cung, P
        node *P = F;
        while(P->link) P = P->link;

        //Noi nut moi vao sau nut cuoi P
        P->link = N;
    }
}

void SList::display()
{
    node *P = F;
    while(P)
    {
        cout<<P->infor<<"  ";
        P = P->link;
    }
}

bool SList::search(int x)
{
    node *P = F;

    //Tim nut co phan tu bang x
    while(P)
    {
        if(P->infor==x) return 1;
        else P = P->link;
    }

    //Khong tim thay x
    return 0;
}

bool SList::remove(int x)
{
    //1.Tim nut M co phan tu bang x va nut P truoc nut M
    node *M = F,*P;
    while(M)
    {
        if(M->infor==x) break;
        else
        {
            P = M;
            M = M->link;
        }
    }

    //2.Loai bo bo nut M co phan tu bang x
    if(M)
    {
        //Ngat ket noi voi nut M
        if(M==F) F = F->link;
        else P->link = M->link;

        //Huy nut M
        delete M;
        return 1;
    }

    //3.Khong tim thay x, khong xoa
    return 0;
}
