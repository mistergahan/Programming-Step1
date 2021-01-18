#include <iostream>
#include <iomanip>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	float a; 
	float s;

	cin>>a;
	if (a>=0){
		s=1.0;
		for (int i=2;i<9;i=i+2)
         s=s*(i*i);
         s=s-a;
         
    	}
    	else {
		
    		s=1;
		for (int i=3;i<10;i=i+3)
         s=s*(i-2);
		}
		cout<<"при а = "<<a <<fixed <<setprecision(6)<<" s = "<<s<<endl;;
		system("pause");
	return 0;
}
