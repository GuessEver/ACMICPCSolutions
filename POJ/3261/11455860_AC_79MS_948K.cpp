#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N=100000+10;
int n,K;
int s[N];//原串
map<int,int> hash;//离散化
int sa[N],rank[N];//Suffix_Array数组、rank数组
int c[N],tmp[N];//基数排序数组、辅助数组
int height[N];//著名的height数组

bool cmp(int *r,int a,int b,int l,int len)
{
	if (a+l>=len || b+l>=len) return 0;
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void DA(int n,int m)
{
	int i,j,p,*x=rank,*y=tmp;
	for(i=0;i<m;i++) c[i]=0;
	for(i=0;i<n;i++) c[x[i]=s[i]]++;
	for(i=1;i<m;i++) c[i]+=c[i-1];
	for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(j=1,p=0;p<n;j*=2,m=p+1)
	{
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<m;i++) c[i]=0;
		for(i=0;i<n;i++) c[x[i]]++;
		for(i=1;i<m;i++) c[i]+=c[i-1];
		for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j,n)?p-1:p++;
	}
	for(i=0;i<n;i++) rank[sa[i]]=i;
	
	int k=0; height[0]=0;
	for(i=0;i<n;height[rank[i++]]=k)
	if(!rank[i]) continue;
	else for(k?k--:0,j=sa[rank[i]-1];s[j+k]==s[i+k];k++);
}

bool check(int m)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(height[i]>=m) cnt++;
		else cnt=0;
		if(cnt>=K-1) return 1;//说明已经找到连续K个有长达m的子序列
	}
	return 0;
}

int solve()
{
	int L=0,R=n-1,M;
	while(L<R)
	{
		M=(L+R+1)>>1;// +1 避免死循环
		if(check(M)) L=M; else R=M-1;
	}
	return L;
}

void work()
{
	scanf("%d%d",&n,&K);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		tmp[i]=s[i];//这里借用一下tmp数组来离散化
	}
	sort(tmp,tmp+n);
	int cnt=1;//不会离散化  只能用stl的map了
	for(int i=0;i<n;i++)
		if(i==0||tmp[i]!=tmp[i-1]) hash[tmp[i]]=cnt++;
	for(int i=0;i<n;i++) s[i]=hash[s[i]];
	memset(tmp,0,sizeof(tmp));
	DA(n,cnt+1);//求出后缀数组
	//for(int i=0;i<n;i++) printf("height[%d]=%d\n",i,height[i]);
	printf("%d\n",solve());//二分答案
}

int main()
{
	work();
	return 0;
}
