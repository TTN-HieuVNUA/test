Bài 16(lthdtbai16.cpp): Đọc vào bán kính và màu nền (Xanh, Đỏ, Tím, Vàng) của n hình tròn
từ tệp văn bản "hinhtron.txt". Đưa ra màn hình bán kính, màu nền, diện tích và chu vi
của các hình tròn. Tính tổng diện tích và chu vi của n hình tròn.
Đếm số lượng hình tròn có nền màu Xanh, Đỏ, Tím, Vàng.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop hinh tron
class HinhTron
{
    private:
        float r;
        char mauNen[7];

    public:
        void thietLapR(float r);
        void thietLapMauNen(const char *mauNen);
        void hien();
        float tinhDT();
        float tinhCV();
        int layMaMau();
};

//===chuong trinh chinh===
int main()
{
    //Tao doi tuong tep vao
    ifstream fin("hinhtron.txt");

    //Khai bao bien
    int n;
    float r,tongDT=0,tongCV=0;
    char mauNen[7];
    int dem[4]={0};

    //Doc so luong hinh tron tu tep
    fin>>n;

    //Tao mang n doi tuong hinh tron
    HinhTron *a = new HinhTron[n];

    //Doc n hinh tron tu tep vao n doi tuong
    for(int i=0;i<n;i++)
    {
        //Doc ban kinh va mau nen tu tep
        fin>>r>>mauNen;

        //Dua ban kinh va mau nen vao doi tuong
        a[i].thietLapR(r);
        a[i].thietLapMauNen(mauNen);
    }

    //Dua ra thong ve cac hinh tron, tinh tong dt, cv va dem
    cout<<"Thong tin ve cac hinh tron doc duoc tu tep la:";
    for(int i=0;i<n;i++)
    {
        cout<<"\nHinh tron thu "<<i+1<<":\n";
        a[i].hien();
        cout<<endl;

        //Tinh tong dt,cv
        tongDT += a[i].tinhDT();
        tongCV += a[i].tinhCV();

        //Dem so hinh tron theo mau
        dem[a[i].layMaMau()]++;
    }

    printf("\nTong dien tich cua %d hinh tron la: %0.1f",n,tongDT);
    printf("\nTong chu vi cua %d hinh tron la: %0.1f",n,tongCV);
    cout<<"\nSo luong hinh tron theo cac mau la:";
    cout<<"\n  - Xanh: "<<dem[0];
    cout<<"\n  - Đỏ: "<<dem[1];
    cout<<"\n  - Tím: "<<dem[2];
    cout<<"\n  - Vàng: "<<dem[3];

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhTron::thietLapR(float r)
{
    this->r = r;
}

void HinhTron::thietLapMauNen(const char *mauNen)
{
    strcpy(this->mauNen, mauNen);
}

void HinhTron::hien()
{
    cout<<"Hinh tron co:";
    cout<<"\n\tBan kinh: "<<r;
    cout<<"\n\tMau nen: "<<mauNen;
    printf("\n\tDien tich: %0.1f",3.14*r*r);
    printf("\n\tChu vi: %0.1f",2*3.14*r);
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

int HinhTron::layMaMau()
{
    if(strcasecmp(mauNen,"Xanh")==0) return 0;
    if(strcasecmp(mauNen,"Đỏ")==0) return 1;
    if(strcasecmp(mauNen,"Tím")==0) return 2;
    if(strcasecmp(mauNen,"Vàng")==0) return 3;
}

