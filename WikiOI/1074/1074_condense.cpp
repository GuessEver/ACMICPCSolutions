#include<cstdio>

int n,k;
int f[50000*3+10];

int getroot(int x) { return f[x]==x ? x : f[x]=getroot(f[x]); }
inline void merge(int x,int y) { f[getroot(x)]=getroot(y); }

int main()
{
	freopen("1074.in","r",stdin);
	freopen("1074.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n;i++) f[i]=i;
	int res=0;
	while(k--)
	{
		int d,x,y;
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n) res++;
		else if(d==2 && x==y) res++;
		else if(d==1)//the same
		{
			if(getroot(x)==getroot(y+n)) res++;//x eat y
			else if(getroot(x+n)==getroot(y)) res++;//y eat x
			else{
				merge(x,y);
				merge(x+n,y+n);
				merge(x+n+n,y+n+n);
			}
		}
		else{//x eat y
			if(getroot(x)==getroot(y)) res++;//x y are the same
			else if(getroot(y)==getroot(x+n)) res++;//x eat y
			else{
				merge(x,y+n);
				merge(x+n,y+n+n);
				merge(x+n+n,y);
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
