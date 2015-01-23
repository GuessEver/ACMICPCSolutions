#include<cstdio>
const int N=20000+10;

int n;
int a[N],num[N];
int ans[N];

void read()
{
	//freopen("cow.in","r",stdin);
	//freopen("cow.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) num[i]=i+1;
}

void work()
{
	for(int i=n-1;i>=0;i--)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(num[j]!=-1) cnt++;
			if(cnt-1==a[i])
			{
				ans[i]=num[j];
				num[j]=-1;
				break;
			}
		}
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]);
}

int main()
{
	read();
	work();
	return 0;
}
