#include<iostream>  // Standard Library Import
using namespace std;  // Standard Operation Usage

int Factorial(int fact)  // Function to calculate factorial of a number
{
    if(fact==1)
    {
      return 1;//Starting Case
    }
    else
    {
      return  fact=fact*Factorial(fact-1); // Recursive Call
    }
}

// Main Code Begins
int main()
{
    int fact_num;  // Factorial of which number
    cout<<"Enter to number to find Factorial: ";
    cin>>fact_num;
    if (fact_num>0)  // Check if number is greater than zero
    {
        fact_num=Factorial(fact_num); // function call
    }
    else
    {
    	cout<<"Enter Number greater than 0";
    }
    cout<<"\nFactorial of number is: "<<fact_num << endl;
    return 0;
} // End of the program
