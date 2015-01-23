#include<cstdio>
#include<cstring>
#include<map>
using std::map;
int n;
map<int,int> h;

int main()
{
	freopen("3038.in","r",stdin);
	freopen("3038.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--)
	{
		h.clear();
		scanf("%d",&n);
		int res=0;
		while(1)
		{
			if(n==1) break;
			if(n&1) n=3*n+1;
			else n=n/2;
			if(h[n])
			{
				res=-1;
				break;
			}
			h[n]=1;
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
