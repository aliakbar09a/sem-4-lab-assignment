#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14
double real_a[10];
double img_a[10];

double real_A[10];
double img_A[10];

double real_tmp;
double img_tmp;

int main()
{
    int n,i,k;
    cout<<"enter n"<<endl;
    cin>>n;

    cout<<"enter real of a"<<endl;
    for(i=0;i<n;i++)
    cin>>real_a[i];

    cout<<"enter img of a"<<endl;
    for(i=0;i<n;i++)
    cin>>img_a[i];


    for(k=0;k<n;k++)
    {
            real_tmp=0.0;
            img_tmp=0.0;
        for(i=0;i<n;i++)
        {
            real_tmp+=real_a[i]*cos((2*k*pi*1.0/n)*i);
            img_tmp+=real_a[i]*sin((2*pi*k*1.0/n)*i);


        }
        real_A[k]=real_tmp;
        img_A[k]=img_tmp;
    }

    for(i=0;i<n;i++)
    {

    cout<<real_A[i]<<" +";
    cout<<img_A[i]<<"i"<<endl;
    }

}
