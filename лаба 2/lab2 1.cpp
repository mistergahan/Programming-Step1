#include <iostream>
using namespace std;

int main( int argc, char *argv[])
{
	int n, m,sum=0;

cout<< "Enter n" << endl;
cin >>n;
cout<< "Enter m" << endl;
cin >>m;

if(++n<m)
	cout<<" M is greater than N: EEERRROOOORR" << endl;
for( size_t i=1; i<n; ++i)
	if (i%5==0 && i%m !=0)
		sum +=i;
cout <<sum<< endl;
return 0;
}
