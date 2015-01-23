#include<cstdio>
#include<algorithm>
using namespace std;
const int N=25+10;
const int M=30000+10;
int n,m;
int v[N],p[N];
int f[M];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&v[i],&p[i]);
		p[i]*=v[i];
	}
	for(int i=1;i<=n;i++)
	for(int j=m;j>=v[i];j--)
	f[j]=max(f[j],f[j-v[i]]+p[i]);
	int t=max_element(f+1,f+1+m)-f;
	printf("%d\n",f[t]);
	//while(1);
	return 0;
}
