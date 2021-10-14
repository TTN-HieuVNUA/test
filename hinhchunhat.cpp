#include <iostream>  
using namespace std; 
class hinhchunhat{
	private:
		float canhA;
		float canhB;
	public:
		hinhchunhat(){}
		hinhchunhat(float a, float b){
			canhA = a;
			canhB = b;
		}
		void Scanner(){
			cout<<"canh a: ";
			cin>>canhA;
			cout<<"canh b: ";
			cin>>canhB;
		}
		float chuVi(){
			return (canhA+canhB)/2;
		}
		float dienTichs(){
			return (canhA+canhB)*2;
		}
		void toString(){
			cout<<"canh a:" << canhA <<"\ncanh b:" << canhB;
		}
};
int main(){
	hinhchunhat hcn1 = hinhchunhat();
	hcn1.Scanner();
	hcn1.toString();
	cout<<"\nchu vi la: "<<hcn1.chuVi()<<"\n";
	cout<<"dien tich la: "<<hcn1.dienTichs();
	cout << endl;
	return 0;
}

