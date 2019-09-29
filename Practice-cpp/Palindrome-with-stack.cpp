#include <iostream>
#include <string.h>
#include<conio.h>
using namespace std;
void push(char);
char pop();
 
char stack[100];
int top = -1;
 
void main()
{
    char str[100];
    int i, count = 0, len;
 
    cout<<"Enter string to check it is palindrome or not : ";
    cin>>str;
 
    len = strlen(str);
 
    for (i = 0; i < len; i++)
    {
        push(str[i]);
    }
 
    for (i = 0; i < len; i++)
    {
        if (str[i] == pop())
            count++;
    }
 
    if (count == len)
        cout<<str<<" is a Palindrome string\n";
    else
        cout<<str<<" is not a palindrome string\n";
	getch();
}
void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return(stack[top--]);
}
