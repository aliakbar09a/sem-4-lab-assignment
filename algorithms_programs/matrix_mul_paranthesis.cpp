#include<iostream>
#include<limits>
#include<math.h>
using namespace std;
int s[20][20];
void matrix_chain_order(int p[],int n)
{
	n--;
	int i,j,l,k,m[20][20],q;
	for(i=1;i<=n;i++)
	{
		m[i-1][i-1]=0;
	}
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i-1][j-1]=2147483647;
			for(k=i;k<=j-1;k++)
			{
				q=m[i-1][k-1]+m[k][j-1]+(p[i-1]*p[j]*p[k]);
				if(q<m[i-1][j-1])
				{
					m[i-1][j-1]=q;
					s[i-1][j-1]=k;
					//cout<<s[i-1][j-1]<<" ";		
				}
			}
		}
	}
	cout<<m[0][n-1]<<endl;
	
}
void print_optimal(int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		print_optimal(i,s[i-1][j-1]);
		print_optimal(s[i-1][j-1]+1,j);
		cout<<")";
	
	}
}
int main()
{
	int n,p[21];
	cout<<"enter the size of p"<<endl;
	cin>>n;
	cout<<"enter the dimensions"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	matrix_chain_order(p,n);
	cout<<endl;
	/*for(int i=0;i<n-2;i++)
	{
		for (int j=i+1;j<n-1;j++)
		{
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}*/
	print_optimal(1,n-1);
}

