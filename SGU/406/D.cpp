#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a[20][20],b[20],x,ans[20];
int main()
{
	//freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		for(int j=1;j<=a[i][0];j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			scanf("%d",&b[j]);
		}
		int tot=0;
		for(int j=1;j<=n;j++)
		{
			int cnt=0;
			bool flag=0;
			for(int k=1;k<=x;k++)
			{
			    if(b[k]<0)flag=1;
			    else flag=0;
				for(int p=1;p<=a[j][0];p++)
				{
					if(a[j][p]==b[k])
					{
						flag=1;
						break;
					}
					if(a[j][p]==-b[k])
					{

						flag=0;
						break;
					}
				}
				if(!flag)break;
			}

			if(flag)
			{
				ans[++tot]=j;
			}
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++)
		{
		    int cnt=a[ans[i]][0];
		    if(cnt>0)printf("%d ",cnt);
			for(int j=1;j<a[ans[i]][0];j++)
				printf("%d ",a[ans[i]][j]);
			if(cnt>=1)printf("%d\n",a[ans[i]][cnt]);
		}
	}

	return 0;
}

