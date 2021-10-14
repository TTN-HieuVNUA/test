Bài 31(lthdtbai31.cpp): Cho tệp văn bản "daysonguyen-bai31.txt" chứa một dãy số nguyên,
trên tệp không có thông tin về số lượng số. Đọc từng số của dãy số từ tệp,
nếu là số nguyên tố thì đưa vào hàng đợi. Đưa ra màn hình dãy số đọc từ tệp và
dãy số nguyên tố trong hàng đợi. Yêu cầu cài đặt và sử dụng hàng đợi lưu trữ phân tán.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop doi tuong hang doi
class Queue
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F,*R;

    public:
        Queue();
        ~Queue();
        void insert(int x);
        int remove();
        bool isEmpty();
};

//Khai bao ham thong thuong
bool laNguyenTo(int x);

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong hang doi
    Queue Q;

    //Tao 1 doi tuong tep vao
    ifstream fin("daysonguyen-bai31.txt");

    //Khai bao bien
    int x;

    //Doc day so tu tep
    cout<<"Day so nguyen doc duoc tu tep la:\n";
    while(fin>>x)
    {
        cout<<x<<"  ";
        if(laNguyenTo(x)) Q.insert(x);
    }

    cout<<"\n\nCac so nguyen to co trong day so la:\n";
    while(!Q.isEmpty()) cout<<Q.remove()<<"  ";

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Queue::Queue():F(NULL),R(NULL)
{

}

Queue::~Queue()
{
    while(F)
    {
        node *P=F;
        F = F->link;
        delete P;
    }
}

void Queue::insert(int x)
{
    //1.Tao nut nho moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao sau nut R
    if(R==NULL) F = N;
    else R->link = N;

    //3.Cho R tro sang nut moi
    R = N;
}

int Queue::remove()
{
    //1.Kiem tra rong
    if(F==NULL)
    {
        cout<<"Hang doi da rong.";
        return 1;
    }

    //2.Giu lai phan tu loi truoc (dau hang doi)
    int tg = F->infor;
    node *P = F;

    //3.Cho F tro sang nut tiep theo
    if(F==R) F = R = NULL;
    else F = F->link;

    //4.Huy nut va tra ve phan tu da loai bo
    delete P;
    return tg;
}

bool Queue::isEmpty()
{
    return F==NULL;
}

//Ham thong thuong
bool laNguyenTo(int x)
{
    //Neu x chia het cho so nao trong khoang tu 2 den can ban 2 cua x thi x khong phai la nguyen to
    for(int i=2;i<=(int)sqrt(x);i++)
        if(x%i==0) return 0;

    //La nguyen to
    return 1;
}
