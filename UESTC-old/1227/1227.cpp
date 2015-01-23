#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N=50000+10;
const int inf=0x3f3f3f3f;
int n,m;
int val[N*4];
int z[N*4],y[N*4],s[N*4];

inline void downloading(int p,int l,int r,int m)
{
	if(val[p]!=-1)
	{
		if(val[p]==1)
		{
			z[p<<1]=y[p<<1]=s[p<<1]=0;
			z[(p<<1)+1]=y[(p<<1)+1]=s[(p<<1)+1]=0;
		}
		if(val[p]==0)
		{
			z[p<<1]=y[p<<1]=s[p<<1]=m-l+1;
			z[(p<<1)+1]=y[(p<<1)+1]=s[(p<<1)+1]=r-(m+1)+1;
		}
		val[p<<1]=val[(p<<1)+1]=val[p];
		val[p]=-1;
	}
}
inline void update(int p)
{
	if(val[p]==-1&&val[p<<1]==val[(p<<1)+1])
	    val[p]=val[p<<1];
}

void change(int p,int l,int r,int a,int b,int c)
{
	if(a<=l&&b>=r)
	{
		val[p]=c;
		z[p]=y[p]=s[p]=(1-c)*(r-l+1);//简写了，仔细看就明白了
		return;
	}
	int m=(l+r)>>1;
	downloading(p,l,r,m);
	if(a<=m) change(p<<1,l,m,a,b,c);
	if(b>m) change((p<<1)+1,m+1,r,a,b,c);
	//z[p]
	if(val[p<<1]==0) z[p]=z[p<<1]+z[(p<<1)+1];
	else z[p]=z[p<<1];
	//y[p]
	if(val[(p<<1)+1]==0) y[p]=y[(p<<1)+1]+y[p<<1];
	else y[p]=y[(p<<1)+1];
	//s[p]
	s[p]=max(y[p<<1]+z[(p<<1)+1],max(s[p<<1],s[(p<<1)+1]));
	update(p);
}

int getres(int d)//写成非递归了
{
	if(s[1]<d) return 0;
	int p=1,l=1,r=n;
	while(l<r)
	{
		int m=(l+r)>>1;
		downloading(p,l,r,m);
		if(s[p<<1]>=d){p<<=1;r=m;continue;}
		if(y[p<<1]+z[(p<<1)+1]>=d) return m-y[p<<1]+1;
		p<<=1;p++;l=m+1;
		update(p);
	}
	return l;
}

void order(int d)
{
	int res=getres(d);
	printf("%d\n",res);
	if(res) change(1,1,n,res,res+d-1,1);
}

int main()
{
    scanf("%d%d",&n,&m);
    change(1,1,n,1,n,0);//让所有人离开，相当于给z[],y[],s[]赋初值
    int temp,x,d;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&temp);
        if(temp==1)//order
        {
            scanf("%d",&d);
            order(d);
        }
        else if(temp==2)//leave
        {
            scanf("%d%d",&x,&d);
            change(1,1,n,x,x+d-1,0);
        }
    }
    return 0;
}
 				    
