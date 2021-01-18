#include <time.h> 
#include <stdlib.h> // srand, rand
#include <iostream>
using namespace std;


int iRandom( int a, int b );
void puzirek_vozr(int *a,int n,int *nsrav,int *nper);
void puzirek_ubyv(int *a,int n,int *nsrav,int *nper);
void sortir_vozr(int *a,int n,int *nsrav,int *nper);
void sortir_ubyv(int *a,int n,int *nsrav,int *nper);


int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Russian");
int n = 5; 
int  i; 
int nsrav, nper;


int *a=new int[n];
int *b=new int[n];

cout<<"Massive length="<<n<<endl;

cout<<endl;
cout<<"Generated massive:"<<endl;
for( i = 0; i < n; i++ ) 
{ *(a+i) =iRandom( -99, 99 ); 
*(b+i)=*(a+i);
cout<< *(a+i)<<" ";
}
cout<<endl;
cout<<endl;


cout<<"Unsorted massive:"<<endl;
puzirek_vozr(a,n,&nsrav,&nper);
cout<<"puzirek_vozr"<<endl;
cout<<"nsrav="<<nsrav<<endl;
cout<<"nper="<<nper<<endl;

for( i = 0; i < n; i++ ) 
{  
cout<< *(a+i)<<" ";
}
cout<<endl;
cout<<endl;

cout<<"Sorted massive:"<<endl;
puzirek_vozr(a,n,&nsrav,&nper);
cout<<"puzirek_vozr"<<endl;
cout<<"nsrav="<<nsrav<<endl;
cout<<"nper="<<nper<<endl;

for( i = 0; i < n; i++ ) 
{  
cout<< *(a+i)<<" ";
}
cout<<endl;
cout<<endl;

cout<<"Sorted massive:"<<endl;
puzirek_ubyv(a,n,&nsrav,&nper);
cout<<"puzirek_ubyv"<<endl;
cout<<"nsrav="<<nsrav<<endl;
cout<<"nper="<<nper<<endl;

for( i = 0; i < n; i++ ) 
{  
cout<< *(a+i)<<" ";
}
cout<<endl;
cout<<endl;




cout<<"Unsorted massive:"<<endl;
sortir_vozr(b,n,&nsrav,&nper);
cout<<"sortir_vozr"<<endl;
cout<<"nsrav="<<nsrav<<endl;
cout<<"nper="<<nper<<endl;

for( i = 0; i < n; i++ ) 
{  
cout<< *(b+i)<<" ";
}
cout<<endl;
cout<<endl;

cout<<"Sorted massive:"<<endl;
sortir_vozr(b,n,&nsrav,&nper);
cout<<"sortir_vozr"<<endl;
cout<<"nsrav="<<nsrav<<endl;
cout<<"nper="<<nper<<endl;

for( i = 0; i < n; i++ ) 
{  
cout<< *(b+i)<<" ";
}
cout<<endl;
cout<<endl;

cout<<"Sorted massive:"<<endl;
sortir_ubyv(b,n,&nsrav,&nper);
cout<<"sortir_ubyv"<<endl;
cout<<"nsrav="<<nsrav<<endl;
cout<<"nper="<<nper<<endl;
for( i = 0; i < n; i++ ) 
{  
cout<< *(b+i)<<" ";
}
cout<<endl;
cout<<endl;

n=5;
for (int j=1; j<=3; j++)
{ a=new int[n];
	for( i = 0; i < n; i++ ) 
      *(a+i) =iRandom( -99, 99 ); 
      
      cout<<"n="<<n<<endl;
      puzirek_vozr(a,n,&nsrav,&nper);
      cout<<"puzirek  nsrav="<<nsrav;
      cout<<"  nper="<<nper<<endl;
      
      for( i = 0; i < n; i++ ) 
      *(a+i) =iRandom( -99, 99 ); 
    
      sortir_vozr(a,n,&nsrav,&nper);
	  cout<<"sortir  nsrav="<<nsrav;
      cout<<"  nper="<<nper<<endl;      
      n=n*10;
}


delete a; delete b;
system("pause");

return 0;

}

int iRandom( int a, int b )

{

return a + ( b - a +1) * rand()/RAND_MAX ;

}

void puzirek_ubyv(int *a,int n,int *nsrav,int *nper)
{ 
int i,j,tmp;
int starttime, endtime;
//int nsrav,nper;

*nsrav=0;
*nper=0;


 starttime=clock();
 
	for(i = 0 ; i < n - 1; i++) 
	{ 
       for(j = 0 ; j < n - i - 1 ; j++) 
	   { 
	    *nsrav=*nsrav+1; 
           if( *(a+j) < *(a+j+1) )
		   {           
              tmp = *(a+j);
              *(a+j) = *(a+j+1) ;
              *(a+j+1)= tmp; 
              *nper=*nper+1;
           }
        }
    }
   
endtime=clock();
//cout<<"puzirek_ubyv worktime="<<endtime-starttime<<endl;
}

void sortir_ubyv(int *a,int n,int *nsrav,int *nper)
{
	int i,j,min,tmp;
	int starttime, endtime;
	//int nsrav,nper;
	
	*nsrav=0;
	*nper=0;
	
 starttime=clock();
 
for (int i = 0; i < n - 1; i++) 
      {
         min = i;
         for (int j = i + 1; j < n; j++) 
          {
          	*nsrav=*nsrav+1;
            if (*(a+j) > *(a+min)) 
             {
                 min= j;
             }
         }
 
        if (min!= i) { 
		     tmp = *(a+i);
              *(a+i) = *(a+min) ;
              *(a+min)= tmp; 
              *nper=*nper+1;
            
         }
     }
	endtime=clock();
//cout<<"sortir_ubyv worktime="<<(endtime-starttime)/CLK_TCK<<endl;
}

void sortir_vozr(int *a,int n,int *nsrav,int *nper)
{
	int i,j,min,tmp;
	int starttime, endtime;
	//int nsrav,nper;
	
	*nsrav=0;
    *nper=0;

 starttime=clock();
 
for (int i = 0; i < n - 1; i++) 
      {
         min = i;
         for (int j = i + 1; j < n; j++) 
          {
          	*nsrav=*nsrav+1;
            if (*(a+j) < *(a+min)) 
             {
                 min= j;
             }
         }
 
        if (min!= i) { 
		     tmp = *(a+i);
              *(a+i) = *(a+min) ;
              *(a+min)= tmp; 
              *nper=*nper+1;
            
         }
		if (*nper==0) break;
     }


	endtime=clock();
//cout<<"sortir vozr worktime="<<(endtime-starttime)/CLK_TCK<<endl;
}

void puzirek_vozr(int *a,int n,int *nsrav,int *nper)
{ 
int i,j,tmp;
int starttime, endtime;
//int nsrav,nper;

*nsrav=0;
*nper=0;


 starttime=clock();
 
	for(i = 0 ; i < n - 1; i++) 
	{ 
       for(j = 0 ; j < n - i - 1 ; j++) 
	   { 
	    *nsrav=*nsrav+1; 
           if( *(a+j) > *(a+j+1) )
		   {           
              tmp = *(a+j);
              *(a+j) = *(a+j+1) ;
              *(a+j+1)= tmp; 
              *nper=*nper+1;
           }
        }
	   if (*nper==0) break;
    }


endtime=clock();
//cout<<"puzirek vozr worktime="<<endtime-starttime<<endl;
}


