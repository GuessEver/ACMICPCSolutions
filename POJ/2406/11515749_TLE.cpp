#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000000+10;
char s[N];
int rank[N],sa[N];
int c[N],tmp[N];
int height[N];
int lcp[N];

bool cmp(int *r,int a,int b,int l)
{ return r[a]==r[b] && r[a+l]==r[b+l]; }

void DA(int n,int m)
{
	int i,j,p,*x=rank,*y=tmp;
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++) c[ x[i]=s[i] ]++;
	for(i=1;i<m;i++) c[i]+=c[i-1];
	for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(j=1,p=1;p<n;j*=2,m=p)
	{
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++) c[x[y[i]]]++;
		for(i=1;i<m;i++) c[i]+=c[i-1];
		for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y); x[sa[0]]=0;
		for(p=1,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
	for(i=0;i<n;i++) rank[sa[i]]=i;
	int k=0;
	for(i=0;i<n;height[x[i++]]=k)
		for(k?k--:0,j=sa[x[i]-1];s[i+k]==s[j+k];k++);
}

void work()
{
	int n=strlen(s);s[n++]='$';
	DA(n,'z'+1);
	/*for(int i=0;i<n;i++)
	{
		printf("%d %d ",sa[i],height[i]);
		puts(s+sa[i]);
	}*/
	lcp[rank[0]]=0x3f3f3f3f;
	for(int i=rank[0]-1;i>0;i--) lcp[i]=min(lcp[i+1],height[i+1]);
	for(int i=rank[0]+1;i<n;i++) lcp[i]=min(lcp[i-1],height[i]);
	//for(int i=0;i<n;i++) printf("%d ",lcp[i]);puts("");
	for(int len=1;len<n;len++)
		if((n-1)%len==0)
		{
			if(lcp[rank[len]]==(n-1)-len)
			{
				printf("%d\n",(n-1)/len);
				break;
			}
		}
}

int main()
{
	while(1)
	{
		memset(sa,0,sizeof(sa));
		memset(rank,0,sizeof(rank));
		memset(c,0,sizeof(c));
		memset(tmp,0,sizeof(tmp));
		memset(s,0,sizeof(s));
		scanf("%s",s);
		if(!strcmp(s,".")) break;
		work();
	}
	return 0;
}