#include<cstdio>
#include<cstring>

int n;
int map[5][50];

int judge(char *s)//判断最后是否为"no good"
{
	int len=strlen(s);
	int pos=len-1;
	while(s[pos]!=' ') pos--;//找到最后一个空格
	s[pos]='\0';//相当于截掉 " good" （有一个空格）
	int npos=pos-1;
	while(s[npos]!=' ') npos--;//继续找倒数第二个空格
	if(!strcmp(s+npos+1,"no")) return 0;
	return 1;
}

void solve()
{
	memset(map,-1,sizeof(map));
	int cnt=0,k=2;
	char s[200];
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s));
		fgets(s,200,stdin);
		int flag=-1;
		flag=judge(s);
		if(i&1) cnt++;
		k=3-k;
		map[k][cnt]=flag;
	}
	for(int i=1;i<=cnt;i++) printf("%d ",i);
	printf("Score\n");
	for(int i=1;i<=2;i++)
	{
		int res=0;
		for(int j=1;j<=cnt;j++)
		{
			if(map[i][j]==-1) printf("- ");
			else if(map[i][j]==0) printf("X ");
			else if(map[i][j]==1) printf("O "),res++;
		}
		printf("%d\n",res);
	}
}

int main()
{
	freopen("1005.in","r",stdin);
	freopen("1005.out","w",stdout);
	while(scanf("%d\n",&n)==1 && n) solve();
	return 0;
}
