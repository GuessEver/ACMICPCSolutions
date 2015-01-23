#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int N=40000+10;
int n,m,K;
string name[N];
string tmp[N];

void work()
{
	int cnt=n;
	for(int i=1;i<=n;i++) cin>>name[cnt--];
	while(m--)
	{
		char s[50]; memset(s,0,sizeof(s));
		scanf("%s",s); int len=strlen(s);
		if(s[0]=='A')
		{
			int j=0,k=0;
			while(j<len && s[j]!='(') j++;
			j++; name[++n]="";
			while(s[j]!=')') name[n]+=s[j++];
		}
		else{
			int cnt=0;
			for(int i=max(1,n-K+1);i<=n;i++) tmp[cnt++]=name[i];
			for(int i=max(1,n-K+1);i<=n;i++) name[i]=tmp[--cnt];
		}
	}
	for(int i=n;i>=1;i--) cout<<name[i]<<endl;
}

int main()
{
	freopen("1831.in","r",stdin);
	freopen("pp.out","w",stdout);
	while(scanf("%d%d%d",&n,&m,&K)==3)
	{
		work();
		printf("\n");
	}
	return 0;
}
