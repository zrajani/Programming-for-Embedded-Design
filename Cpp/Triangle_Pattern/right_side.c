#include <stdio.h>  // Preprocessing Directives

int main() // Code Begins Here
{
	int i,j,n=5; // Variable Declaration
	// Print Upper Triangle
	for(i=1;i<=n;++i)
	{
		for(j=i;j>=1;j--)
		{
			printf("%d",j);
			printf("\t");
		}
		printf("\n");
	}
	// Print Lower Triangle
	for(i=n;i>=1;--i)
	{
		for(j=i-1;j>=1;j--)
		{
			printf("%d",j);
			printf("\t");
		}
		printf("\n");
	}
} // Code Ends Here
