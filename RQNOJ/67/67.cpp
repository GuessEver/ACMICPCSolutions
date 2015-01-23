#include<cstdio>

int n,k,a[50],num=0;

bool su(int sum)
{
    for(int i=2;i<sum;i++)
        if(sum%i==0)return false;
    return true;
}

void dfs(int t,int x,int sum)
{
    if(t>k) {if(su(sum))num++;return;}
    for(int i=x+1;i<=n;i++)
        dfs(t+1,i,sum+a[i]);
}

int main()
{
    //freopen("rqn67.in","r",stdin);
    //freopen("rqn67.out","w",stdout);
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    dfs(1,0,0);
    printf("%d",num);
}

