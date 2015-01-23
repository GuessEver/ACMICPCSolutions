#include<cstdio>

int n,a[6000],c[6000];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int len=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=len,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[i]>c[mid]) l=mid+1;
			else r=mid-1;
		}
		c[l]=a[i];
		if(l>len) len=l;
	}
	printf("%d\n",len);
	while(1);
	return 0;
}
