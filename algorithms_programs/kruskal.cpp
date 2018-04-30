#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,a,b,u,v,mincost=0,parent[4];
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void kruskal(int g[][4])
{
	int tn=1;
	while(tn<n)
	{
		int min=INT_MAX;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(g[i][j]<INT_MAX)
				{
					min=g[i][j];
					a=u=i;
					b=v=j;
				}		
			}
		}
		u=find(u);
		v=find(v);	
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",tn++,a,b,min);
			mincost +=min;
		}
	}
}
int main()
{
	//cout<<"enter no. of edges"<<endl;
	n=4;
	int g[4][4] = {{0,5,1,2},
                      {5,1,3,0},
                      {1,3,0,2},
                      {2,0,2,6}
                     };
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			g[i][j]=INT_MAX;	
		}
	}
	int m,x,y,z;
	cout<<"enter no. of edges"<<endl;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		if(x!=y&&g[x][y]>z)
		{
			g[x][y]=z;
		}	
	}*/
	kruskal(g);
		
}

