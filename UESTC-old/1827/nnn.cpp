#include<cstdio>
#include<algorithm>

int n;
int a[100000];

int main()
{
	freopen("1827.in","r",stdin);
	freopen("nnn.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int q; scanf("%d",&q);
	while(q--)
	{
		int op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(x>y) std::swap(x,y);
		if(op)
		{
			int res=0;
			for(int i=x;i<=y;i++)
				res=std::max(res,a[i]);
			printf("%d\n",res);
		}
		else{
			scanf("%d",&z);
			for(int i=x;i<=y;i++) a[i]+=z;
		}
	}
	return 0;
}
