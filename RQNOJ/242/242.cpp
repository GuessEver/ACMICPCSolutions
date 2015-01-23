#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

const int N=100000+10;
int n;
int a[N],b[N];
int h[N];
int c[N],len=0;

int find(int x)
{
	int l=1,r=len,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(x>c[mid]) l=mid+1;
		else r=mid-1;
	}
	//printf("%d\n",l);
	return l;
}

int main()
{
	//freopen("rqn242.in","r",stdin);
	//freopen("rqn242.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		h[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[i]=h[b[i]];
	}
	//for(int i=1;i<=n;i++) printf("%d ",b[i]);printf("\n");
	for(int i=1;i<=n;i++)
	{
		int k=find(b[i]);
		c[k]=b[i];
		len=max(len,k);
		//printf("%d\n",len);
	}
	printf("%d\n",n-len);
	return 0;
}

