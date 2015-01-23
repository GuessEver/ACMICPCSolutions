#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int n;
char s[100][1000];
int len[100];
int hash[100];
int ans=0;

int check(int x,int y)
{
	int lenx=strlen(s[x]);
	int leny=strlen(s[y]);
	int res=9999;
	for(int k=1;k<=min(lenx,leny);k++)
	{
		if(!strncmp(&s[x][lenx-k],&s[y][0],k))
			res=min(res,k);
	}
	if(res==lenx||res==leny||res==9999) res=0;
	return res;
}

void dfs(int last,int sum)
{
	ans=max(ans,sum);
	for(int i=1;i<=n;i++)
	{
		int t=check(last,i);
		if(t>0&&hash[i]<2)
		{
			hash[i]++;
			dfs(i,sum+len[i]-t);
			hash[i]--;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
	}
	scanf("\n");
	s[0][0]=getchar();
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]==s[0][0])
		{
			memset(hash,0,sizeof(hash));
			++hash[i];
			dfs(i,len[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
