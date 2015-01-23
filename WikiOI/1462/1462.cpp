#include<cstdio>
#include<algorithm>
using std::swap;

int h[70000];

int main()
{
	freopen("1462.in","r",stdin);
	freopen("1462.out","w",stdout);
	for(int i=2;i<=66000;i++)
		if(!h[i])
			for(int j=2;j<=66000/i;j++)
				h[i*j]=1;
	int a,b;
	//for(int i=1;i<=1000;i++) if(!h[i]) printf("%d ",i);
	scanf("%d%d",&a,&b);
	if(a>b) swap(a,b);
	if(a<2) a=2;
	long long res=0;
	for(int i=a;i<=b;i++)
		if(!h[i]) res+=i;
	printf("%lld\n",res);
	return 0;
}
