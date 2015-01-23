/*
LANG: C++
TASK: hamming
ID: jiangzh15
*/
#include<cstdio>

int N,B,D;
int ans[100];

bool check(int x,int last)
{
	if(x==0) return 1;
	int cnt=0;
	for(int i=1;i<=B;i++)
	{
		int a=x&1;
		int b=last&1;
		x>>=1; last>>=1;
		cnt+=(a!=b);
	}
	return cnt>=D;
}

int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d%d%d",&N,&B,&D);
	int maxval=(1<<B);
	int cnt=0;
	int last=0;
	for(int i=0;i<maxval;i++)
	{
		for(int j=1;j<=cnt;j++)
			if(!check(i,ans[j])) goto end;
		printf("%d",ans[++cnt]=i);
		if(cnt==N) break;
		if(cnt%10==0) printf("\n");
		else printf(" ");
end:;
	}
	printf("\n");
	return 0;
}
