#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

int n;
int L[30],R[30],len;
int f[30][2][2][15][2][20];

int predoing(int a,int *num)
{
    int le=0;
    while(a)
    {
        num[++le]=a%10;
        a/=10;
    }
    return le;
}

int calc(int pos,int d,int u,int last,int flag,int mod)
{
    if(pos==0) return flag&&mod==0;
    int &res=f[pos][d][u][last][flag][mod];
    if(res!=-1) return res;
    res=0;
    int st=d?L[pos]:0;
    int ed=u?R[pos]:9;
    for(int i=st;i<=ed;i++)
    {
        bool tmp=(i==3&&last==1);
        res+=calc(pos-1,d&&i==L[pos],u&&i==R[pos],i,flag||tmp,(mod*10+i)%13);
    }
    return res;
}

void work()
{
    memset(f,-1,sizeof(f));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    len=predoing(1,L);
    len=max(len,predoing(n,R));
    printf("%d\n",calc(len,1,1,0,0,0));
}

int main()
{
    while(scanf("%d",&n)==1) work();
    return 0;
}
