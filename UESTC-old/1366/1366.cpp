#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=1000+10;
int n,m;
int add[N],sub[N];

int getint(char *s)
{
	int res=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
		res=res*10+s[i]-'0';
	return res;
}

void query(int a,int b)
{
	int l=a,r=b;
	if(a>b) std::swap(a,b);
	int dis=std::min(b-a,a+n-b);
	a=l;b=r;
	dis+=add[b]-sub[a];
	if(dis<=1) printf("Yes!\n");
	else printf("I'm sorry.\n");
}

void work()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		char s[100];
		scanf("%s",s);
		if(s[0]=='K')
		{
			int x,y; scanf("%d%d",&x,&y);
			query(x,y);
		}
		else{
			int x=getint(s);
			int num; scanf("%s%d",s,&num);
			if(s[0]=='-') sub[x]=num;
			else add[x]=num;
		}
	}
}

int main()
{
	freopen("1366.in","r",stdin);
	freopen("1366.out","w",stdout);
	int t; scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		printf("Case #%d:\n",cas);
		memset(sub,0,sizeof(sub));
		memset(add,0,sizeof(add));
		work();
		printf("\n");
	}
	return 0;
}
