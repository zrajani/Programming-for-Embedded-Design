/*
 * LU_Decomposition.cpp
 *
 *  Created on: Oct. 21, 2019
 *      Author: zain
 */
#include<iostream>
using namespace std;
void LUdecomposition(float a[10][10], float l[10][10], float u[10][10], int n) {
   int i = 0, j = 0, k = 0;
   for (i = 0; i < n; i++)
   {
	   for (j = 0; j < n; j++)
	   {
         if (j < i)
         l[j][i] = 0;
         else {
            l[j][i] = a[j][i];
            for (k = 0; k < i; k++)
            {
               l[j][i] = l[j][i] - l[j][k] * u[k][i];
            }
         }
      }
      for (j = 0; j < n; j++)
      {
         if (j < i)
            u[i][j] = 0;
         else if (j == i)
            u[i][j] = 1;
         else
         {
            u[i][j] = a[i][j] / l[i][i];
            for (k = 0; k < i; k++) {
               u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
          }
        }
      }
   }
}
int main()
{
   float a[10][10], l[10][10], u[10][10],b[10][10];
   float x[10],y[10];
   int n = 0, i = 0, j = 0;

   cout << "Enter size of square matrix : "<<endl;
   cin >> n;

   cout<<"Enter matrix values: "<<endl;
   for (i = 0; i < n; i++)
	   for (j = 0; j < n; j++)
		   	   cin >> a[i][j];
   LUdecomposition(a, l, u, n);
   cout << "L Decomposition is as follows: "<<endl;
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         cout<<l[i][j]<<" ";
      }
      cout << endl;
   }
   cout << "U Decomposition is as follows: "<<endl;
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         cout<<u[i][j]<<" ";
      }
      cout << endl;
   }

   cout<<"Enter the value of b matrix";
   for (i=1;i<=n;i++)
   {
	   cin>>b[i][1];
   }
   for (i=1;i<=n;++i)
   {
	   int sum=0;
	   for (j=1;j<=n;++j)
	   {
		   sum=sum+l[i][j]*b[i][1];
	   }
	   y[i]=sum;
   }
   cout<<y[1]<<"\t"<<y[2]<<"\t"<<y[3]<<"\n";
   return 0;
}
