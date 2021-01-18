#include <iostream>
#include <cmath>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float f(float x, int);
float df(float x,int);
float dih(float a, float b, float eps, int );
float newton(float a, float eps, int);
float iterration(float a, float eps, int);


int main(int argc, char** argv) {
	setlocale(LC_ALL, "rus");
	float a, b, eps=0.000001, kor;
	
	cin>>a;
	cin>>b;
	cout<<endl;
	cout<<"x-cos(x)"<<endl;

	kor=dih(a,b,eps,1);
	cout<<kor<<" ?????????"<<endl;
	cout<<endl;
	
	kor=newton(a,eps,1);
	cout<<kor<<" ??????"<<endl;
	cout<<endl;

	kor=iterration(a,eps,1);
	cout<<kor<<" ?????. ?????????"<<endl;
	cout<<endl;

	cout<<"x-10cos(x)"<<endl;

	kor=dih(a,b,eps,10);
	cout<<kor<<" ?????????"<<endl;
	cout<<endl;
	
	kor=newton(a,eps,10);
	cout<<kor<<" ??????"<<endl;
	cout<<endl;

	kor=iterration(a,eps,10);
	cout<<kor<<" ?????. ?????????"<<endl;

	 system ("pause");
	return 0;
}



float f(float x, int k)
{
	return (x-k*cos(x));
}



float df(float x,int k)
{
	return (1+k*sin(x));
}


float dih(float a, float b, float eps,int k)
{
	float c, x;
	int i;
	i=0;
	while ( abs(a-b)>eps)
	{
		c=(a+b)/2;
		if((f(a,k)*f(c,k))>0)
		{
			a=c;
		}
		else
		{
			b=c;
		}
		i++;
	}
	x=(a+b)/2;
	cout<<i<<" iterrations"<<endl;
	return x;
}


float newton(float a, float eps, int k)
{
	float x0, xn;
	int i;
	i=0;
	x0=a;
	xn=x0-f(x0,k)/df(x0,k);
	while (fabs(xn-x0)>eps)
	{
		x0=xn;
		xn=x0-f(x0,k)/df(x0,k);	
		i++;
	}
   cout<<i<<" iterrations"<<endl;
	return xn;
}

float iterration(float a, float eps, int k)
{
 float x0,xn; 
 int i;
	i=0;
  x0=a; 
  xn=k*cos(x0); 
 while (fabs(xn-x0)>eps) 
  { 
   x0=xn; 
   xn=k*cos(x0); 
   i++;
   if (i>100000)
	   break;
  } 
 
 cout<<i<<" iterrations"<<endl;
 return xn;
}


