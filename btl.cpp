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
        void setName(char name[100]);
        void setResolution(char res[50]);
        void setLocation(char loc[50]);
        void setPhotoday(char pho[50]);
        void setNumviews(int views);
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

void getListImage(List &list);
void getListImageByLocation(string location, List &list, List listImage);
void menu();
//==== chuong trinh chinh
int main()
{
    menu();
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
    cout<<"\nten: "<<name<<"\t||size: "<<resolution<<"\t||location: "<<location<<"\t||time: "<<photoday<<"\t||view: "<<numViews;
}

void Image::setName(char name[100])
{
    this->name = name;
}
void Image::setResolution(char res[50])
{
    this->resolution=res;
}

void Image::setLocation(char loc[50])
{
    this->location=loc;
}

void Image::setPhotoday(char pho[50])
{
    this->photoday = pho;
}

void Image::setNumviews(int views)
{
    this->numViews=views;
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
        if(P->infor.getName().compare(imageName)==0)
        {
            P->infor.setNumViews();
            return P->infor;
        }
        else
        {
           P = P->link;
        }
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
    if(P==NULL)
    {
        cout<<"\nkhong co buc anh nao\n";
        return;
    }
    else
    {
        cout<<"\n======================================================================================\n";
        while(P != NULL)
        {
            P->infor.showInfor();
            P=P->link;
        }
        cout<<"\n======================================================================================\n";
    }
}

void List::insert(Image img)
{
    node *N = new node;
    N->infor = img;
    N->link = NULL;
    node *P = F;
    if(F==NULL)
    {
        F=N;
    }
    else
    {
        while(P->link != NULL)
        {
            P = P->link;
        }
        P -> link = N;
    }
}

void getListImage(List &list)
{
    Image img[100];
    Image imgs;
    ifstream fin("image.txt");
    int n;
    char tg[3];
    fin>>n;
    
    Image image;
    char name[500];
    char size[20];
    char location[200];
    char dates[50];
    int views;
    for(int i=0; i<n; i++)
    {
        fin.getline(tg,sizeof(tg));
        fin.getline(name, sizeof(name), '\t');
        fin.getline(size, sizeof(size), '\t');
        fin.getline(location, sizeof(location), '\t');
        fin.getline(dates, sizeof(dates), '\t');
        fin>>views;

        image.setName(name);
        image.setResolution(size);
        image.setLocation(location);
        image.setPhotoday(dates);
        image.setNumviews(views);
        list.insert(image);
    }
}

void getListImageByLocation(string location, List &list, List listImage)
{
     
}

void menu()
{
    int select,num;
    string name;
    List list;
    getListImage(list);
    do
    {
        cout<<"================================================\n";
        cout<<"||1.hien thi tat ca thong tin anh\n";
        cout<<"||2.them thong tin 1 buc anh\n";
        cout<<"||3.tim kiem buc anh theo ten\n";
        cout<<"||4.buc anh duoc xem nhieu nhat\n";
        cout<<"||5.cac buc anh chup tai 1 dia diem\n";
        cout<<"||6.thoat\n";
        cout<<"================================================\n";
        cout<<"\nnhap lua chon cua ban: ";
        cin>>select;
        switch(select)
        {
            case 1:
                cout<<"\ntat ca thong tin anh la: \n";
                list.disPlay();
                cout<<"\n";
                break;
            case 2:
                cout<<"\nnhap so luong anh ban muon them: \n";
                cin>>num;
                /*Image image;
                string name;
                string size;
                string dates;
                string location;
                for(int i=0; i<num; i++)
                {
                    cout<<"\nnhap vao ten: \n";
                    cin>>name;
                    cout<<"\nnhap vao size: \n";
                    cin>>size;
                    cout<<"\nnhap vao dia diem: \n";
                    cin>>location;
                    cout<<"\nnhap vao ngay chup: \n";
                    cin>>dates;
                }*/
                break;
            case 3:
                cout<<"\nnhap ten buc anh: \n";
                cin>>name;
                list.findAImageByName(name).showInfor();
                cout<<"\n";
                break;
            case 4:
                cout<<"\nbuc anh duoc xem nhieu nhat la: \n";
                list.showAImageMaxView().showInfor();
                cout<<"\n";
                break;
            case 5:
                cout<<"\nnhap vao dia diem chup\n";
                cin>>name;
                cout<<"\ncac buc anh duoc chup o "<<name<<" la: \n";
                break;
            case 6:
                break;
            default:
                cout<<"\nmoi nhap lai: \n";
                break;
        }
    }
    while(select !=6);
}
