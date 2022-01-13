#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;

class Image
{
    private:
        string name;
        string resolution;
        string location;
        string photoday;
        int numViews;
    public:
        Image();
        Image(string name, string resolution, string location, string photoday);
        void setNumViews();
        int getNumViews();
        string getLocation();
        string getName();
        void showInfor();
};

class List
{
    private:
        struct node
        {
            Image infor;
            node *link;
        }*F;
    public:
        List();
        ~List();
        void insert(Image img);
        Image findAImageByName(string imageName);
        Image findAImageByLocation(string location);
        Image showAImageMaxView();
        void disPlay();
};

//==== chuong trinh chinh
int main()
{
    Image img[100];
    List list;
    Image imgs;
    ifstream fin("image.txt");
    

    cout<<endl;
    return 0;
}
//==== dinh nghia ham====
Image::Image()
{

}

Image::Image(string name, string resolution, string location, string photoday)
{
    this->name=name;
    this->resolution=resolution;
    this->location=location;
    this->photoday=photoday;
    this->numViews=0;
}

void Image::setNumViews()
{
    this->numViews+=1;
}

int Image::getNumViews()
{
    return this->numViews;
}

string Image::getLocation()
{
    return this->location;
}

string Image::getName()
{
    return this->name;
}

void Image::showInfor()
{
    cout<<"\nten: "<<name<<", do phan giai: "<<resolution<<", dia diem chup: "<<location<<", thoi gian chup: "<<photoday<<", view: "<<numViews;
}

List::List()
{
    F=NULL;
}

List::~List()
{
    
}

Image List::findAImageByName(string imageName)
{
    node *P = F;
    while(P != NULL)
    {
        if(P->infor.getName().compare(imageName))
        {
            P->infor.setNumViews();
            return P->infor;
        }
        P = P->link;
    }
    return P->infor;
}

Image List::findAImageByLocation(string location)
{
    node *P = F;
    while(P != NULL)
    {
        if(P->infor.getLocation().compare(location))
        {
            return P->infor;
        }
        P=P->link;
    }
    return P->infor;
}

Image List::showAImageMaxView()
{
    int max = 0;
    node *P = F;
    Image img;
    while(P != NULL)
    {
        if(P->infor.getNumViews()>max)
        {
            max = P->infor.getNumViews();
            img = P->infor;
        }
        P = P->link;
    }
    return img;
}

void List::disPlay()
{
    node *P = F;
    while(P != NULL)
    {
        P->infor.showInfor();
        P=P->link;
    }
}

void List::insert(Image img)
{
    node *N = new node;
    N->infor = img;
    N->link = NULL;
    node *P = F;
    while(P->link != NULL)
    {
        P = P->link;
    }
    P -> link = N;
}
