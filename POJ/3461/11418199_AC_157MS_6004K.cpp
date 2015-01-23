#include<cstdio>
#include<cstring>
const int N=1000000+10;
char t[N],s[N];
int tlen,slen;
int next[N];

void getnext()
{
	memset(next,0,sizeof(next));
	next[0]=-1;
	int j=0,k=-1;
	while(j<tlen)
	{
		if(k==-1||t[j]==t[k]) next[++j]=++k;
		else k=next[k];
	}
}

int solve()
{
	int res=0;
	getnext();
	int i=0,j=0;
	while(i<slen)
	{
		if(j==-1||s[i]==t[j]) {i++;j++;}
		else j=next[j];
		if(j==tlen) {res++;}
	}
	return res;
}

void work()
{
	memset(t,0,sizeof(t));
	memset(s,0,sizeof(s));
	scanf("%s\n%s\n",t,s);
	tlen=strlen(t);slen=strlen(s);
	printf("%d\n",solve());
}


int main()
{
	int grp;scanf("%d\n",&grp);
	while(grp--) work();
	return 0;
}
