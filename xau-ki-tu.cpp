/*
Bài 37(lthdtbai37.cpp): Tạo lớp đối tượng xâu ký tự có các đặc điểm giống như xâu ký tự
trong Pascal: Có thể khởi tạo đối tượng xâu bằng một hằng xâu; có thể gán hằng xâu hoặc
đối tượng xâu cho đối tượng xâu; có thể dùng phép toán + để nối xâu; có thể dùng các
phép toán so sánh để so sánh xâu; có thể dùng cin và cout để nhập vào và đưa ra đối tượng xâu.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop doi tuong xau ky tu
class String
{
    private:
        enum {size=256};
        char str[size];

    public:
        String();
        String(const char *str);
        String& operator+(String &s2);
        String& operator+(const char *str);
        bool operator>(String &s2);
        bool operator>=(String &s2);
        bool operator<(String &s2);
        bool operator<=(String &s2);
        bool operator==(String &s2);
        bool operator!=(String &s2);

        //Ham ban
        friend istream& operator>>(istream &cin,String &s);
        friend ostream& operator<<(ostream &cout,String &s);
};

//===chuong trinh chinh===
int main()
{
    //Tao doi tuong xau
    String hoDem="Dao Tat",ten="Tung",hoTen;

    cout<<"Ho ten: "<<hoDem<<" "<<ten;

    cout<<"\n\nNhap vao ho dem: ";
    cin>>hoDem;
    cout<<"Nhap vao ten: ";
    cin>>ten;

    hoTen + hoDem + " " + ten;

    cout<<"\nHo ten vua nhap la: "<<hoTen;

    cout<<endl;
    return 0;
}
//===dinh nghia ham==
String::String()
{
    strcpy(str,"");
}

String::String(const char *str)
{
    strcpy(this->str,str);
}

String& String::operator+(String &s2)
{
    //Kiem tra do dai
    if(strlen(str) + strlen(s2.str)<size)
        strcat(str,s2.str);

    //Tra ve ve doi tuong tuong ben trai
    return *this;
}

String& String::operator+(const char *str)
{
    //Kiem tra do dai
    if(strlen(this->str) + strlen(str)<size)
        strcat(this->str,str);

    //Tra ve ve doi tuong tuong ben trai
    return *this;
}

bool String::operator>(String &s2)
{
    return strcasecmp(str,s2.str)>0;
}

bool String::operator>=(String &s2)
{
    return strcasecmp(str,s2.str)>=0;
}

bool String::operator<(String &s2)
{
    return strcasecmp(str,s2.str)<0;
}

bool String::operator<=(String &s2)
{
    return strcasecmp(str,s2.str)<=0;
}

bool String::operator==(String &s2)
{
    return strcasecmp(str,s2.str)==0;
}

bool String::operator!=(String &s2)
{
    return strcasecmp(str,s2.str)!=0;
}

//Ham ban
istream& operator>>(istream &cin,String &s)
{
    scanf(" "); cin.get(s.str,sizeof(s.str));

    return cin;
}

ostream& operator<<(ostream &cout,String &s)
{
    cout<<s.str;

    return cout;
}

