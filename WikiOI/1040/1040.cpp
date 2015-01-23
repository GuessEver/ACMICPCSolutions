#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int p,k,num,sum[300][300],ans;
string s,a[10];

int getsum(int l,int r)
{
    string ch;
    int sum=0;
    for(int i=l;i<=r;i++)
        for(int j=1;j<=num;j++)
            if(i+a[j].size()-1<=r)
            {
                ch.assign(s,i,a[j].size());
                if(ch==a[j]){sum++;break;}
            }
    return sum;
}

void dfs(int i,int num,int su)//当前位置，划分第几次，当前总和
{
    if(num==k)
    {
        su+=sum[i+1][s.size()];
        if(su > ans) ans = su;
        return;
    }
    for(int j=i+1;j<=s.size()-k+num-1;j++)
        dfs(j,num+1,su+sum[i][j]);
}

void work()
{
    scanf("%d%d",&p,&k);
    string ch;
    s="";
    for(int i=1;i<=p;i++)
    {
        cin>>ch;
        s+=ch;
    }
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
        cin>>a[i];
    for(int i=0;i<s.size();i++)
        for(int j=i;j<s.size();j++)
            sum[i+1][j+1]=getsum(i,j);
    ans=0;
    dfs(0,1,0);
    printf("%d\n",ans);
}

int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    int groups;
    scanf("%d",&groups);
    for(int i=1;i<=groups;i++)
        work();
    return 0;
}
