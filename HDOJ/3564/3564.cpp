#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
const int N=100000+10;
const int inf=0x3f3f3f3f;
int n,a[N],tmp[N],c[N],len;
int free[N*4];

void build_tree(int p,int l,int r)
{
    if(l==r) {free[p]=1;return;}
    int m=(l+r)>>1;
    build_tree(p<<1,l,m);
    build_tree((p<<1)+1,m+1,r);
    free[p]=free[p<<1]+free[(p<<1)+1];
}

void insert(int p,int l,int r,int cnt,int x)
{
    if(l==r) {free[p]--;a[x]=l;return;}
    free[p]--;
    int m=(l+r)>>1;
    if(free[p<<1]>=cnt) insert(p<<1,l,m,cnt,x);
    else insert((p<<1)+1,m+1,r,cnt-free[p<<1],x);
    free[p]=free[p<<1]+free[(p<<1)+1];
}

int find(int a)
{
    int l=1,r=len,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a>c[mid]) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int main()
{
    int T;scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        memset(c,0,sizeof(c));len=0;
        memset(free,0,sizeof(free));
        memset(a,0,sizeof(a));
        memset(tmp,0,sizeof(a));
        printf("Case #%d:\n",ca);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&tmp[i]);
        build_tree(1,1,n);
        for(int i=n;i>=1;i--) insert(1,1,n,tmp[i]+1,i);
        for(int i=1;i<=n;i++)
        {
            int k=find(a[i]);
            len=max(len,k);
            c[k]=a[i];
            printf("%d\n",len);
        }
        printf("\n");
    }
    return 0;
}
