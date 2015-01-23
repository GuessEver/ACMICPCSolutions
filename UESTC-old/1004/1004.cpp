#include<cstdio>
#include<cstring>

int n;
char s[10000];
int red,yel;

void solve()
{
	memset(s,0,sizeof(s));
	scanf("%s",s);
	int len=strlen(s);
	red=yel=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='R') red++;
		else if(s[i]=='Y') yel++;
		else if(s[i]=='B')
		{
			if(red==7) printf("Red\n");
			else printf("Yellow\n");
		}
		else if(s[i]=='L')
		{
			if(yel==7) printf("Yellow\n");
			else printf("Red\n");
		}
	}
}

int main()
{
	freopen("1004.in","r",stdin);
	freopen("1004.out","w",stdout);
	while(scanf("%d",&n)==1 && n)
		solve();
	return 0;
}
