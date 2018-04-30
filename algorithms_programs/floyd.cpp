#include<iostream>
#include<bits/stdc++.h>
#define n 5
using namespace std;
int pi[5][5];
void printallpair(int i,int j)
{
	if(i==j)
		cout<<i;
	else
	{
		if(pi[i][j]==999)
			cout<<"NO path possible"<<endl;
		else
		{
			printallpair(i,pi[i][j]);
			cout<<"->"<<j;
		}
	}
}

int main()
{
	int w[5][5]={	{0,3,8,999,-4},
			{999,0,999,1,7},
			{999,9,0,999,999},
			{2,999,-5,0,999},
			{999,999,999,6,0}	
			};
	for( int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			
			if(w[i][j]==0||w[i][j]==999)
				pi[i][j] = 999;
			else
				pi[i][j] = i;
		}
	for(int k=0; k<n;k++)	
	{
		for( int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(w[i][j]!=999&&w[i][j] >  w[i][k] + w[k][j])
				{
					w[i][j] = w[i][k] + w[k][j];
					pi[i][j] = pi[k][j];
				}
			}
			
		}
	}
	cout<<"Enter i and j to print shortest path from i to j"<<endl;
	int x,y;
	cin>>x>>y;
	printallpair(x,y);
}


