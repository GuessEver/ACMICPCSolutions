/*
LANG: C++
TASK: nocows
ID: jiangzh15
*/
#include<cstdio>
#include<cstring>
const int mod=9901;
int n,K;
int calc[300][300],f[300][300];

int dfs(int deep,int left)
{
	//printf("deep=%d left=%d\n",deep,left);
	if(deep>K) return 0;
	if(left==1) return 1;
	if(calc[deep][left]) return f[deep][left];
	calc[deep][left]=1; 
	f[deep][left]=0;
	for(int i=1;i<(left-1);i+=2)
	{
		int x=dfs(deep+1,i);
		int y=dfs(deep+1,(left-1)-i);
		f[deep][left]+=((x%mod)*(y%mod))%mod;
	}
	return f[deep][left];
}

int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	scanf("%d%d\n",&n,&K);
	int a=dfs(1,n);
	K--;
	memset(calc,0,sizeof(calc));
	memset(f,0,sizeof(f));
	int b=dfs(1,n); 
	printf("%d\n",((a-b)%mod+mod)%mod);
	return 0;
}
