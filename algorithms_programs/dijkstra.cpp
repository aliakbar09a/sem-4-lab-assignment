#include<bits/stdc++.h>
using namespace std;
int n,dist[10],sptset[10];
int printSolution()
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
    {
    	if(dist[i]==INFINITY)
      		printf("%d \t %d\n", i, dist[i]);
      	else
      		printf("%d \t Not possible",i);
      
}
int mindistance()
{
	int k,min=INFINITY,minind;
	for(k=0;k<n;k++)
	{
		if(dist[k]<=min&&sptset[k]==0)
		{
			min=dist[k];
			minind=k;
		}
	}
	return minind;
}	
void dijkstra(int v[][10],int s)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		dist[i]=INFINITY;
		sptset[i]=0;
		cout<<sptset[i]<<" ";
	}
	cout<<endl;
	dist[s]=0;
	for(j=0;j<n-1;j++)
	{
		int u=mindistance();
		sptset[u]=1;
		/*for(i=0;i<n;i++)
		{
			cout<<sptset[i]<<" ";
		}	
		cout<<endl;*/
		//printSolution();
		for(int i=0;i<n;i++)
		{
			if((!sptset[i])&&(v[u][i])&&(dist[u]!=INFINITY)&&(dist[u]+v[u][i]<dist[i]))
				dist[i]=dist[u]+v[u][i];
		}
		//printSolution();		
	}
	printSolution();
}
int main()
{
	int i,j,V[10][10],a,b,w,m;
	cout<<"Enter no. of nodes";
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			V[i][j]=0;
	}
	cout<<"Enter no. of edges";
	cin>>m;
	cout<<"Enter the node that has edge and the weight";
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		V[a][b]=w;
	}
	dijkstra(V,0);
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<V[i][j]<<" ";
		cout<<endl;
	}*/
	
}
