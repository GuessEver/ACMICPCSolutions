#include<cstdio>
const int N=200+10;

int n,k;
int map[N][N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int x;
		while(scanf("%d",&x)==1&&x)
			map[x][i]=map[i][x]=1;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=n;j++)
		if(map[i][j]) tmp++;
		if(tmp>=k) res++;
	}
	printf("%d",res);
	//while(1);
	return 0;
}
