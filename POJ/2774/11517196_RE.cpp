#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100000+10;

int n;
char s[N],a[N];
int rank[N],sa[N];
int c[N],tmp[N];
int height[N];

void read()
{
	scanf("%s%s",s,a);
	s[strlen(s)]='$';
	strcat(s,a);
	//puts(s);
	n=strlen(s);
	s[n++]='$';
}

bool cmp(int *r,int a,int b,int l)
{ return r[a]==r[b] && r[a+l]==r[b+l]; }
void DA(int n,int m)
{
	int i,j,p,*x=rank,*y=tmp;
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++) c[ x[i]=s[i] ] ++;
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
	DA(n,'z'+1);
	/*for(int i=0;i<n;i++)
	{
		printf("%d %d ",sa[i],height[i]);
		puts(s+sa[i]);
	}*/
	int std=sa[1];
	int res=0;
	for(int i=2;i<n;i++)
		if((sa[i]>std&&sa[i-1]<std)||(sa[i]<std&&sa[i-1]>std))
			res=max(res,height[i]);
	printf("%d\n",res);
}

int main()
{
	read();
	work();
	return 0;
}