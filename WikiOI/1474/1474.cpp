#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int n,k;
const char s[]={"0123456789ABCDEFGHIJK"};

void work()
{
	string res="";
	while(n)
	{
		res=s[n%k]+res;
		n/=k;
	}
	cout<<res<<endl;
}

int main()
{
	scanf("%d%d",&n,&k);
	work();
	return 0;
}
