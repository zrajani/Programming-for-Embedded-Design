#include<iostream>
#include<conio.h> 
#include<process.h> 
using namespace std;
#define SIZE 4 
static int top=-1; 
class stack 
{ private: int ar[SIZE]; 
public: 
	void push(int item); 
	void pop(); 
	void peep();
}; 
void stack::push(int item) 
{ 
	if(top==SIZE-1) 
	{
		cout<<"\nThe Stack Over Flow!!";
	}
	else 
	{ 
		ar[++top]=item; 
		cout<<"\nElement succesfully pushed in the Stack!!!"; 
	} 
} 
void stack::pop() 
{ 
	if(top<0) 
		cout<<"\nStack Under flow!!!"; 
	else 
	{ 
		top--; 
		cout<<"\nElement sucessfully popped from the Stack!!!"; 
	} 
} 
void stack::peep() 
{ 
	if(top<0) 
		cout<<"\nThe Stack is Empty it cannot be Peeped!!!"; 
	else 
		for(int i=top;i>=0;i--) 
			cout<<ar[i]<<" "; 
} 
void main() 
{ 
	char choice; 
	int ch,num; stack ob; 
	do 
	{ 
		cout<<"\n\n\t\t\tS T A C K O P E R A T I O N S"; 
		cout<<"\n\t\t\t-------------------------------"; 
		cout<<"\n\n1.PUSH"; 
		cout<<"\n2.POP"; 
		cout<<"\n3.DISPLAY"; 
		cout<<"\n4.EXIT"; 
		cout<<"\n\nEnter your choice:"; 
		cin>>ch; 
		switch(ch) 
		{ 
		case 1: cout<<"\nEnter the Element you want to Push:"; 
			cin>>num; ob.push(num); 
			break; 
		case 2: ob.pop(); 
			break; 
		case 3: ob.peep(); 
			break; 
		case 4: 
			goto end;
		default: cout<<"\nPlease Enter a Valid Choice(1-4)!!!"; 
		}
	}
	while(1);
end:
	cout<<"End of Program";
	getch(); 
}
