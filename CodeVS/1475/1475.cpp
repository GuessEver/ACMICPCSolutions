#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string n;
int k;
const char s[]={"0123456789ABCDEFGHIJ"};

int num(char ch)
{
	for(int i=0;i<20;i++)
	if(ch==s[i]) return i;
}

void work()
{
	int res=0;
	int kk=1;
	for(int i=n.length()-1;i>=0;i--)
	{
		res+=num(n[i])*kk;
		kk*=k;
	}
	cout<<res<<endl;
}

int main()
{
	cin>>n>>k;
	work();
	return 0;
}
