# include <iostream>  
# include <conio.h>  
# include <math.h> 
using namespace std;
void main()   
{   
 int i, n ;   
 float x, val, sum = 1, t = 1 ;    
 cout<<"Enter the value for x : ";   
 cin>>x;
 cout<<"\nEnter the value for n : ";   
 cin>>n;   
 val = x ;   
 x = x * 3.14159 / 180 ;   
 for(i = 1 ; i < n + 1 ; i++)   
 {   
  t = t * pow((float) (-1), (float) (2 * i - 1)) *   
   x * x / (2 * i * (2 * i - 1)) ;   
  sum = sum + t ;   
 }   
 cout<<"\nCosine value of"<<val<<" is : "<<sum;   
 getch() ;   
}   
