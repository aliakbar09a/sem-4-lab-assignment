#include<iostream>
using namespace std;
struct pairs {
	int min;
	int max;
};
struct pairs getminmax(int a[],int l,int h)
{
	struct pairs m,left,right;
	int mid;
	if(l==h)
	{
		m.min=a[l];
		m.max=a[l];	
		return m;
	}
	if(l==h+1)
	{
		if(a[l]>a[h])
		{
			m.max=a[l];
			m.min=a[h];
		}
		else
		{
			m.max=a[h];
			m.min=a[l];
		}
		return m;
	}
	mid=(l+h)/2;
	left=getminmax(a,l,mid);
	right=getminmax(a,mid+1,h);
	if(left.max>right.max)
		m.max=left.max;
	else
		m.max=right.max;
	if(left.min<right.min)
		m.min=left.min;
	else
		m.min=right.min;
	return m;
}
int main()
{
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int a[n];
	cout<<"\nEnter the elements of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	struct pairs ans;
	ans=getminmax(a,0,n-1);
	cout<<endl;
	cout<<"The max no. is "<<ans.max<<" and the min no. is "<<ans.min<<endl;
}

