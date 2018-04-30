#include<iostream>
#include<bits/stdc++.h>
#include<complex.h>
using namespace std;
struct comp{
	float r;
	float c;
};
struct comp *y;
comp* fft(float a[],int n)
{
	float wnreal = cos(2*3.14/n),wnimag = sin(2*3.14/n),treal,timag,wreal=1.0,wimag = 0;
	float b[n/2+1],c[n/2+1];
	for(int i=0,k=0;i<n;i+=2,k++)	
		b[k] = a[i];
	for(int i=1,k=0;i<n;i+=2,k++)	
		c[k] = a[i];
	struct comp *y0,*y1;
	y0 = fft(b,n/2);
	y1 = fft(c,n/2);
	for(int i=0;i<=(n/2-1);i++)
	{
		(y+i)->r = (y0+i)->r + wreal*((y1+i)->r) - wimag*((y1+i)->c);
		(y+i)->c = (y0+i)->c + wimag*((y1+i)->r) + wimag*((y1+i)->c);
		(y+i+n/2)->r= (y0+i)->r - wreal*((y1+i)->r) + wimag*((y1+i)->c);
		(y+i+n/2)->c= (y0+i)->c - wimag*((y1+i)->r) - wreal*((y1+i)->c);
	}
	return y;
}
int main()
{
	int n;
	cin>>n;
	float a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	fft(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<(y+i)->r<<" +"<<(y+i)->c<<endl;
	}
}
