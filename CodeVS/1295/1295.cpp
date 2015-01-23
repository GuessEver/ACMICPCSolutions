#include<cstdio>
#include<cstring>

const int MAXN=110;

int n;
int a[MAXN];
int ans=0;
bool l[MAXN],z[3*MAXN],y[MAXN];

void dfs(int x)
{
	if(x>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	    if(!l[i] && !z[MAXN+i-x] && !y[i+x])
	    {
			l[i]=z[MAXN+i-x]=y[i+x]=true;
			a[x]=i;
			dfs(x+1);
			l[i]=z[MAXN+i-x]=y[i+x]=false;
		}
}

int main()
{
	scanf("%d",&n);
	memset(l,0,sizeof(l));
	memset(z,0,sizeof(z));
	memset(y,0,sizeof(y));
	ans=0;	dfs(1);
	printf("%d\n",ans);
	return 0;
}

