Bài 29(lthdtbai29.cpp): Nhập vào một số nguyên dương, đưa ra số hex tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang hex.
Ngăn xếp sử dụng cấu trúc lưu trữ phân tán.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Stack
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *T;

    public:
        Stack();
        ~Stack();
        Stack(const Stack &s);
        Stack operator=(const Stack &s2);
        void push(int x);
        int pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(NULL)
{

}

Stack::~Stack()
{
    while(T)
    {
        node *P=T;
        T=T->link;
        delete P;
    }
}

Stack::Stack(const Stack &s):T(NULL)
{
    node *P=s.T,*N,*Bottom;

    //Duyet qua cac phan tu cua ngan xep s da co
    while(P)
    {
        //Tao nut moi cua ngan xep moi, copy du lieu sang
        N = new node;
        N->infor = P->infor;
        N->link = NULL;

        //Noi nut moi vao duoi nut day cua ngan xep moi
        if(T==NULL)
        {
            T = Bottom = N;
        }
        else
        {
            Bottom->link = N;
            Bottom = N;
        }

        //Cho P tro xuong nut tiep theo ben duoi
        P = P->link;
    }
}

Stack Stack::operator=(const Stack &s2)
{

}

void Stack::push(int x)
{

}

int Stack::pop()
{

}

bool Stack::isEmpty()
{

}

