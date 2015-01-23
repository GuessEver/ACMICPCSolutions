#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50000+10;

int n,m;
int a[N],b[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		char op;int x,y,z;
		scanf("\n%c",&op);
		if(op=='Q')
		{
			scanf("%d%d%d",&x,&y,&z);
			memcpy(b,a+x,(y-x+1)*sizeof(int));
			sort(b,b+y-x+1);
			printf("%d\n",b[z-1]);
		}
		else{
			scanf("%d%d",&x,&z);
			a[x]=z;
		}
	}
	return 0;
}

