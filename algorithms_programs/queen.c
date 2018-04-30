#include <stdio.h>
#include <stdlib.h>
void nqueen(int,int);
int place(int,int);
void print(int);
int x[10];



void nqueen(int k,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(place(k,i)==1)
        {
            x[k]=i;
            if(k==n)
            print(n);
            else
            nqueen(k+1,n);
        }
    }
}

int place(int k,int i)
{
    int j;
    for(j=1;j<k;j++)
      {
          if(x[j]==i || abs(x[j]-i)==abs(j-k))
          return 0;
      }
      return 1;
}

 void print(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
            printf("1\t");
            else
            printf("0\t");
        }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    int n;
    printf("Enter no. of queen");
    scanf("%d",&n);
    nqueen(1,n);

}
