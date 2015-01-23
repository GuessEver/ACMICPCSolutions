#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

typedef long long LL;
int L[30],R[30],len;
LL f[30][2][2][15];

int predoing(LL a,int *num)
{
    int le=0;
    while(a)
    {
        num[++le]=a%10;
        a/=10;
    }
    return le;
}

LL calc(int pos,int d,int u,int last)
{
    if(pos==0) return 1;
    LL &res=f[pos][d][u][last];
    if(res!=-1) return res;
    res=0;
    int st=d?L[pos]:0;
    int ed=u?R[pos]:9;
    for(int i=st;i<=ed;i++)
    {
        if(i==9&&last==4) continue; 
        res+=calc(pos-1,d&&i==L[pos],u&&i==R[pos],i);
    }
    return res;
}

void work()
{
    memset(f,-1,sizeof(f));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    LL a;
    scanf("%I64d",&a);
    len=predoing(1,L);
    len=max(len,predoing(a,R));
    printf("%I64d\n",a-calc(len,1,1,0));
}

int main()
{
    freopen("3555.in","r",stdin);
    freopen("3555.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--) work();
    return 0;
}
