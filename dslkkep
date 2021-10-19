#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

// khai bao lop
class List
{
    private:
        struct node
        {
            int infor;// truong luu tru thong tin
            node *L; // con tro luu tru node phia truoc
            node *R; // con tro luu tru node ke tiep
        }* F, *D; // con tro luu 2 node dau va cuoi
    public:
        List();
        ~List();
        void display();
        bool insert(int x);
        bool search(int x);
        bool remove(int x);
};
//chuong trinh chinh
int main(){
    List lists;

    ifstream fin("daysonguyen-bai32.txt");
    int x;
    while(fin>>x)
    {
        lists.insert(x);
    }
    lists.display();
    return 0;
}

// dinh nghia ham
List::List()
{
    F = NULL;
    D = NULL;
}

List::~List()
{

}

void List::display()
{
    if(F==NULL)
    {
        cout<<"ds rong!";
    }
    else
    {
        node *P = F; // gan con tro P = con tro tro den node dau tien
        while(P != NULL)
        {
            cout<<P->infor<<" ";
            P = P->R; // chuyen con tro P sang node tiep theo
        }
    }
}

bool List::insert(int x)
{
    node *N = new node; // khoi tao 1 node moi
    N->R=NULL;
    N->infor=x;
    if(F==NULL)
    {
        N->L = NULL;
        F = N;
        D = N;
        return true;
    }
    else
    {
        D ->R = N;
        N -> L = D;
        D = N;
        return true;
    }
    return false;
}

bool List::search(int x)
{

    return false;
}

bool List::remove(int x)
{

    return false;
}
