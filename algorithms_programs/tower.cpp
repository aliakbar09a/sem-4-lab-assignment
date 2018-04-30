#include<iostream>
using namespace std;
void tower(int n,char a,char b,char c)
{
	if(n==1)
		cout<<"move disc 1 from "<<a<<"->"<<c<<endl;
	else
	{
		tower(n-1,a,c,b);
		cout<<"move disc "<<n<<" from "<<a<<"->"<<c<<endl;
		tower(n-1,b,a,c);				
	}
}
int main()
{
	int n;
	cout<<"Enter the no. of discs"<<endl;
	cin>>n;
	cout<<"The steps are "<<endl;
	tower(n,'A','B','C');
}
