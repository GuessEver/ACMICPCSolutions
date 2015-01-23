#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=50+10;
int n,m;
long long f[N];

int main()
{
	scanf("%d%d",&n,&m);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]*2;
		if(i==m) f[i]--;
		if(i>m) f[i]-=f[i-m-1];
	}
	cout<<f[n]<<endl;
	return 0;
}

