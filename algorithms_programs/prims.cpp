#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int p[4],n,key[4];
bool b[4];
int minnode()
{
	int min=INT_MAX,ind;
	for(int i=0;i<n-1;i++)
	{
		if(b[i]==false&&key[i]<min)
		{
			min=key[i];
			b[i]=true;
			ind=i;
		}
	}
	return ind;
}
int prim(int g[][4])
{
	int u;
	for(int i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		b[i]=false;
	}
	key[0]=0;
	p[0]=-1;
	for(int i=0;i<n;i++)
	{
		u=minnode();
		b[u]=true;
		for(int v=0;v<n;v++)
		{
			if(g[u][v]&&b[v]==false&&g[v][u]+key[u]<key[v])
			{
				p[v]=u;
				key[v]=g[u][v]+key[u];
				cout<<u<<"to"<<v<<endl;
			}
		}
	}
	
}
int main()
{
	int g[4][4] = {{0,5,1,2},
                      {5,1,3,0},
                      {1,3,0,2},
                      {2,0,2,6}
                     };
        n=4;
 	prim(g);
}
