#include<iostream>
using namespace std;
void fact(int n,int a)
{
	if(n==1)
		cout<<"Factorial is "<<a<<endl;
	else
	{
		fact(n-1,n*a);
	}
}
int main()
{
	int n;
	cout<<"Enter n for factorial"<<endl;
	cin>>n;
	fact(n,1);
}

