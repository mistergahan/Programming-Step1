#include <iostream>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	unsigned short n=1;
	double y;
	
  while (n!=0) 	{
  	cin>>n;
  	y=0;
  	for (int i=1; i<=n; i++)
    y=sqrt(2*i+y);
  	cout<<y<<endl;
		
	}
	return 0;
}
