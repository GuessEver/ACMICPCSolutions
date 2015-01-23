#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

int A,B;
int L[20],R[20],len;
int f[15][2][2][15];

void predoing(int a,int *num)
{
    int le=0;
    while(a)
    {
        num[++le]=a%10;
        a/=10;
    }
    len=max(len,le);
}

int dfs(int pos,bool d,bool u,int last)
{
    if(pos==0) return 1;
    int &res=f[pos][d][u][last];
    if(res!=-1) return res;
    int st=d?L[pos]:0;
    int ed=u?R[pos]:9;
    res=0;
    for(int i=st;i<=ed;i++)
    {
        if(i==4) continue;
        if(i==2&&last==6) continue;
        res+=dfs(pos-1,d&&i==L[pos],u&&i==R[pos],i);
    }
    return res;
}

int main()
{
    while(scanf("%d%d",&A,&B)==2&&A&&B)
    {
        memset(f,-1,sizeof(f));len=0;
        memset(L,0,sizeof(L)); predoing(A,L);
        memset(R,0,sizeof(R)); predoing(B,R);
        printf("%d\n",dfs(len,1,1,0));
    }
    return 0;
}
