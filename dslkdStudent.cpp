
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>

using namespace std;

// khai bao lop
class SinhVien
{
    private:
        int id;
        char name[50];
        int age;
    public:
        SinhVien();
        void hien(SinhVien sv);
        void show();
        void nhap(int id, char name[50], int age);
};

class List
{
    private:
        struct node
        {
            SinhVien infor;
            node *link;
        } *F;
    public:
        List();
        ~List();
        void display();
        bool insert(SinhVien sv);
        bool search(SinhVien sv);
        bool remove(int id);
};
//chuong trinh chinh
int main(){
    SinhVien *sv[50];
    List lists;
    ifstream fin("dssv.txt");
    int id, age;
    char name[50];
    int i = 0;
    while(fin>>id && fin>>name && fin>>age)
    {
        sv[i] = new SinhVien();
        sv[i]->nhap(id,name, age);
        ++i;
    }
    for(int j=0; j<i; j++)
    {
        sv[j]->show();
        SinhVien sv1 = *sv[j];
        lists.insert(sv1);
    }
    lists.display();
    return 0;
}

// dinh nghia ham
SinhVien::SinhVien()
{

}

void SinhVien::hien(SinhVien sv)
{
    cout<<"\nid: "<<sv.id<<"name: "<<sv.name<<", age"<<sv.age;
}

void SinhVien::show()
{
    cout<<"id: "<<id<<", name: "<<name<<", age: "<<age<<"\n";
}

void SinhVien::nhap(int id, char name[50], int age)
{
     this->id = id;
    strcpy(this->name,name);
    this-> age = age;
}

List::List()
{
    F = NULL;
}

List::~List()
{

}

void List::display()
{
    if(F==NULL)
    {
        cout<<"ds rong";
    }
    else
    {
        node *P = F;
        SinhVien sv;
        while(P != NULL)
        {
            sv.hien(P->infor);
            P=P->link;
        }
    }
}

bool List::insert(SinhVien sv)
{
    node *N = new node;
    N->link = NULL;
    N->infor = sv;
    if(F==NULL)
    {
        F = N;
        return true;
    }
    else
    {
        node *P = F;
        while(P->link != NULL)
        {
            P = P->link;
        }
        P->link = N;
        return true;
    }
    return false;
}

bool List::search(SinhVien sv)
{

    return false;
}

bool List::remove(int id)
{

    return false;
}

