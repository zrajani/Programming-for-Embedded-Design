#include<iostream>
#include<math.h>

float fun(float,float);
main()
    {
        int i,j,c;
        float x[100],y[100],h,m[100],m1,m2,a,s[100],w;
        cout<<"  Enter the initial value of x:";
        cin>>x[0];
        cout<<"\n  Enter the value of increment h:";
        cin>>h;
        cout<<"\n  Enter the final value of x:";
        cin>>a;
        cout<<"\n  Enter the initial value of the variable y :";
        cin>>y[0];
        s[0]=y[0];
        for(i=1;x[i-1]<a;i++)
            {
                w=100.0;
               x[i]= x[i-1]+h;
               m[i]=fun(x[i-1],y[i-1]);
               c=0;
               while(w>0.0001)
                {
                    m1=fun(x[i],s[c]);
                    m2=(m[i]+m1)/2;
                    s[c+1]=y[i-1]+m2*h;
                    w=s[c]-s[c+1];
                    w=fabs(w);
                    c=c+1;
                }
              y[i]=s[c];
            }
        cout<<"\n\n The respective values of x and y are\n     x  \t     y\n\n";
        for(j=0;j<i;j++)
            {
                cout<<x[j]<<"\t"<<y[j];
                cout<<"\n";
            }
    }
float fun(float a,float b)
    {
        float c;
        c=1+(a*a)+b;
        return(c);
    }
