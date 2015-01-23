#include<cstdio>
#include<cstring>
#include<algorithm>
using std::swap;
const int N=100000+10;
int n;
int A[N],L[N],R[N],D[N];
int f[N];

int getroot(int x){return f[x]==x ? x : f[x]=getroot(f[x]);}

int merge(int x,int y)//合并x y，其实相当于把y插入x
{
    if(!x||!y) return x|y;
    if(A[x]<A[y]) swap(x,y);//维护大根堆性质
    R[x]=merge(R[x],y);
    f[R[x]]=x;//更新并查集
    if(D[R[x]]>D[L[x]]) swap(L[x],R[x]);
    D[x]=D[R[x]]+1;
    return x;
}

int getmax(int x)//取出最大值并删除
{
    f[L[x]]=L[x];f[R[x]]=R[x];//更新并查集
    int t=merge(L[x],R[x]);
    L[x]=R[x]=D[x]=0;//删除
    return t;
}

int solve(int x,int y)
{
    A[x]/=2; A[y]/=2;
    int xx=getmax(x);//先把最大值取出
    int yy=getmax(y);
    xx=merge(xx,x);//再合并进去
    yy=merge(yy,y);
    int tmp=merge(xx,yy);//两个堆合并
    return A[tmp];
}

int work(int x,int y)
{
    int fx=getroot(x);
    int fy=getroot(y);
    if(fx==fy) return -1;
    return solve(fx,fy);
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&A[i]);
            L[i]=R[i]=D[i]=0;
            f[i]=i;
        }
        int q;scanf("%d",&q);
        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",work(a,b));
        }
    }
    return 0;
}
