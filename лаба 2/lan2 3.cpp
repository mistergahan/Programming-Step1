#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>

#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std;

 int _tmain(int argc, _TCHAR* argv[])
{

 double x, s, ai, ai1,h,eps,y,n;
 int fact;
 h=0.2;
 eps=0.000001;
 x=0.0;
  while (x<=1)
	  {
	   y=(1-pow(x,2)/2)*cos(x)-(x/2)*sin(x);
       s=0.0;
	   ai=1.0;
	   ai1=0.0;
	   n=0;
	   while (fabs(ai)>=eps)
		   {
			fact=1;
			for (int i = 1; i <=2*n; i++)
			{
			 fact=fact*i;
			}
			ai1=pow(-1.0,n)*(2*pow(n,2)+1)*pow(x,2*n)/fact;
			s=s+ai1;
			n=n+1;
			ai=ai1;
		   }

	   cout<<"x="<<setw(9)<< x<<"  y="<<setw(9)<<y<<"  s="<<setw(9)<<s<<"  n="<<setw(2)<<n<<endl;
	   x=x+h;
	  }


_getch();

	return 0;
}
