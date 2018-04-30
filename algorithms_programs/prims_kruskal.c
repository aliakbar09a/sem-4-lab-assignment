#include<stdio.h>
int cost1[10][10],cost2[10][10],visited[10]={0},mincost1=0,mincost2=0,min1,min2,parent[10];
int a,b,u,v,n,i,j,ne1=1,ne2=1,c;
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




int main()
{

printf("enter n \n");
scanf("%d",&n);

printf("enetr cost matrix \n");
for(i=1;i<=n;i++)
{
        for(j=1;j<=n;j++)
        {
        scanf("%d",&cost1[i][j]);

        if(cost1[i][j]==0)
        cost1[i][j]=999;

cost2[i][j]=cost1[i][j];
        }
}

int t=2;
while(t--)
{

//visited[10]={0};
printf("\n\n");

printf("\n1:prims \t 2: krushkals\t");
scanf("%d",&c);
printf("\n\n");
switch(c)
{
case 1:
visited[1]=1;
while(ne1<n)
{

for(i=1,min1=999;i<=n;i++)
        for(j=1;j<=n;j++)

if(cost1[i][j]<min1)
if(visited[i]!=0)
{
min1=cost1[i][j];
a=u=i;
b=v=j;

}
if(visited[u]==0 || visited[v]==0)
{
printf("%d edge:\t%d %d \tcost: %d\n",ne1++,a,b,min1);
mincost1+=min1;
visited[b]=1;
}

cost1[a][b]=cost1[b][a]=999;

}
printf("mincost: %d",mincost1);

break;



case 2:

while(ne2<n)
{

for(i=1,min2=999;i<=n;i++)
        for(j=1;j<=n;j++)
if(cost2[i][j]<min2)
{
min2=cost2[i][j];
a=u=i;
b=v=j;
}


u=find(u);
v=find(v);
if(uni(u,v))
{
printf("%d edge:(%d %d)= %d \n",ne2++,a,b,min2);
mincost2+=min2;
}

cost2[a][b]=cost2[b][a]=999;


        }
printf("minimum cost=%d \n",mincost2);

break;
default:
printf("wrong input");
}


    }

}
