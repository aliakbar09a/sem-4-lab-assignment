#include<bits/stdc++.h>
using namespace std;
int n,k;
int counts=0;
int temp[20];
int fill(int a[],int pos,int value)
{
	a[pos-1] = value;
	if(pos==n)
	{
		for(int l=1;l<=n;l++)
			temp[l-1] = a[l-1];
		sort(temp,temp+n);
		for(int l=1;l<=n;l++)
			cout<<temp[l-1]<<" ";
		counts++;
		cout<<endl;
	}
	else
	{
	for(int next_val = value; next_val <=k ;next_val++)
		fill(a,pos+1,next_val);
	}
}
int main()
{
	cin>>n>>k;
	int a[20],i;
	for(i=1;i<=k;i++)
		a[i-1] = i;
	if(k==n)
	{
		for(int l=1;l<=n;l++)
			cout<<a[l-1]<<" ";
		counts++;
		cout<<endl;
	}
	else
	{
	for(int j = 1;j <=k;j++)
		fill(a,i,j);
	}
	cout<<counts<<endl;
}
