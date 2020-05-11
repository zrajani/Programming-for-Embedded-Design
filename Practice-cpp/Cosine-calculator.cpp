//Program Name: Cosine Calculator 
//Software: Microsoft Visual Studio 2015
//Alternative Software: Eclipse (With some modification in the code) such as making void main() to int main()

//Author: Zain Rajani 

// Pre-Processor Directives
# include <iostream>  
# include <conio.h>  
# include <math.h> 

//Using functions from the namespace such as cin,cout,endl,etc.
using namespace std;

//The main code begins here 
void main()   
{   
 int i, n ;   
 float x, val, sum = 1, t = 1 ;    
 cout<<"Enter the value for x : ";   
 cin>>x;  //The value of which cosine needs to be calculated
 cout<<"\nEnter the value for n : ";   
 cin>>n;   // The value of precision
 val = x ;   //Storing the value of x just for printing the statement later on
 x = x * 3.14159 / 180 ;   //Converting the value entered in degrees to radians
 for(i = 1 ; i < n + 1 ; i++)   
 {   
  // The entire loop will compute thhe value of cos(x)
  t = t * pow((float) (-1), (float) (2 * i - 1)) *   
   x * x / (2 * i * (2 * i - 1)) ;   
  sum = sum + t ;   
 }  
 //Printing/Output Statements
 cout<<"\nCosine value of"<<val<<" is : "<<sum;   
 getch() ;   // Not required if Eclipse is used
}   
//End of the main code 
