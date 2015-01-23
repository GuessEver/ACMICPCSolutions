#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int n,k,num,sum[300][300],f[300][300],best=0;
string s,word[10];

bool is_ok(string ch)
{
    for(int i=1;i<=num;i++)
        if(word[i]==ch) return true;
    return false;
}

int getsum(int l,int r)
{
    string ch;
    int sum=0;
    for(int i=l;i<=r;i++)
        for(int j=1;j<=num;j++)
            if(i+word[j].size()-1<=r)
            {
                //ch=&insert(0,s,i,word[j].size());
                ch.assign(s,i,word[j].size());
                if(ch==word[j]) {sum++;break;}
            }
    return sum;
}

void work()
{
    scanf("%d%d",&n,&k);
    string ch;
    int i;
    s="";
    for(i=1;i<=n;i++){cin>>ch; s+=ch;}
    scanf("%d",&num);
    for(i=1;i<=num;i++) cin>>word[i];
    int j;
    for(i=0;i<s.size();i++)
        for(j=i;j<s.size();j++)
            sum[i+1][j+1]=getsum(i,j);//i+1和j+1是为了把下标调整到 1 而不是 0
    for(i=1;i<=s.size();i++)f[i][1]=sum[1][i];
    for(int t=2;t<=k;t++)//断点个数
        for(i=t;i<=s.size();i++)//枚举前i个
            for(j=t;j<i;j++)//枚举当前区间[t,i]断点位置
                f[i][t]=max(f[i][t],f[j-1][t-1]+sum[j][i]);
    printf("%d",f[s.size()][k]);
}

int main()
{
    //freopen("p3.in","r",stdin);
    //freopen("p3.out","w",stdout);
    work();
}

