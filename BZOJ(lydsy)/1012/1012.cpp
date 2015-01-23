/**************************************************************
    Problem: 1012
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:932 ms
    Memory:3932 kb
****************************************************************/

#include<cstdio>
#include<algorithm>
using namespace std;
 
const int MAXN=200000+10;
 
int m,D;
int cnt;
int num[MAXN*4];

void add_tree(int p,int l,int r,int a,int c)
{
    if(l==r && l==a) {num[p]=c;return;}
    int m=(l+r)>>1;
    if(a<=m) add_tree(p<<1,l,m,a,c);
    if(a>m) add_tree((p<<1)+1,m+1,r,a,c);
    num[p]=max(num[p<<1],num[(p<<1)+1]);
}
 
int query(int p,int l,int r,int a,int b)
{
    if(a<=l && b>=r) return num[p];
    int m=(l+r)>>1,x1=0,x2=0;
    if(a<=m) x1=query(p<<1,l,m,a,b);
    if(b>m) x2=query((p<<1)+1,m+1,r,a,b);
    return max(x1,x2);
}
 
void work()
{
    scanf("%d%d\n",&m,&D);
    char op;int x,t=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%c%d\n",&op,&x);
        if(op=='A')
        {
            x=(x+t)%D;
            add_tree(1,1,MAXN,++cnt,x);
        }
        else{
            t=query(1,1,MAXN,cnt-x+1,cnt);
            printf("%d\n",t);
        }
    }
}
 
int main()
{
    //freopen("maxnum.in","r",stdin);
    //freopen("maxnum.out","w",stdout);
    work();
    return 0;
}
