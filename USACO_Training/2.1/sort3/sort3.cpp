/*
LANG: C++
TASK: sort3
ID: jiangzh15
*/
#include<cstdio>
#include<algorithm>
const int N=1000+10;

int n,a[N],sorted[N];

int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) { scanf("%d",&a[i]); sorted[i]=a[i]; }
	std::sort(sorted+1,sorted+1+n);
	int res=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(sorted[i]==1 && sorted[j]==2 && a[i]==2 && a[j]==1)
			{
				std::swap(a[i],a[j]);
				res++;
				break;
			}
			if(sorted[i]==1 && sorted[j]==3 && a[i]==3 && a[j]==1)
			{
				std::swap(a[i],a[j]);
				res++;
				break;
			}
			if(sorted[i]==2 && sorted[j]==3 && a[i]==3 && a[j]==2)
			{
				std::swap(a[i],a[j]);
				res++;
				break;
			}
		}
	for(int i=1;i<=n;i++)
	{
		here:;
		if(sorted[i]==1)
		for(int j=i+1;j<=n;j++) if(sorted[j]==2)
			for(int k=j+1;k<=n;k++) if(sorted[k]==3)
				if(a[i]!=1 && a[j]!=2 && a[k]!=3)
				{
					a[i]=1; a[j]=2; a[k]=3;
					res+=2;
					goto here;
				}
	}
	printf("%d\n",res);
	//for(int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
	//for(int i=1;i<=n;i++) printf("%d ",sorted[i]); puts("");
	return 0;
}
