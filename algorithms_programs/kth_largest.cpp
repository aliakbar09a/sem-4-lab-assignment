#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int p,int r)
{
	int x;
	x = a[r-1];
	int i = p-1,temp;
	for (int j =p;j<r;j++)
	{
		if(a[j-1]<=x)
		{
			i++;
			temp = a[i-1];
			a[i-1] = a[j-1];
			a[j-1] = temp;
		}
	}
	temp = a[i];
	a[i] = a[r-1];
	a[r-1] = temp;
	return i+1;
}
void select(int a[], int n,int k)
{
	int low = 1, up = n;
	while(low < up)
	{
		int j = partition(a, low, up);
		if (k==j)
		{
			cout<<a[j-1];
			break;
		}
		else if(k<j)
			up = j-1;
		else
			low = j+1;
	}
}

int main()
{
	int n,k;
	cout<<"Enter the value of n\t";
	cin>>n;
	int a[n];
	cout<<"Enter the array\t";
	for (int i = 0;i < n;i++)
		cin>>a[i];
	cout<<"Enter the value of k\t";
	cin>>k;
	select(a,n,k);
}
