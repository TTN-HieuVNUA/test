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
    cout<<"\nnhap vao bien x can tim: ";
    cin>>x;
    lists.remove(x);
    cout<<"\nds sau khi xoa\n";
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
    if(F==NULL)
    {
        cout<<"ds rong!";
        return false;
    }
    else
    {
        node *P = F;
        while(P!= NULL)
        {
            if(P->infor==x)
            {
                return true;
                break;
            }
            else
            {
                P = P->R;
            }
        }
    }
    return false;
}

bool List::remove(int x)
{
    if(search(x) == false)
    {
        cout<<"\nko tim thay x";
        return false;
    }
    else
    {
        node *P = F;
        if(P->infor==x)
        {
            F = F->R;
            F->L=NULL;
            delete P;
            return true;
        }
        else
        {
            while(P!=NULL)
            {
                if(P->infor==x)
                {
                    node *M = P;
                    M = M->L;
                    M->R = P->R;
                    delete P;
                    return true;
                }
                else
                {
                    P = P->R;
                }
            }
        }
    }
    return false;
}
