/**************************************************************
    Problem: 1858
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:1072 ms
    Memory:2368 kb
****************************************************************/
 
#include<cstdio>
#include<algorithm>
using namespace std;
#define data_up if(val[p<<1]==val[(p<<1)+1]&&val[p]==-1)val[p]=val[p<<1]
const int N=100000+10;
  
int n,m;
int val[N*4];
int last,best;
int ans;
  
void data_down(int p)//mark downloading
{
    if(val[p]!=-1)
    {
        val[p<<1]=val[(p<<1)+1]=val[p];
        val[p]=-1;
    }
}
  
void change(int p,int l,int r,int a,int b,int c)//insert && change
{
    if(a<=l && b>=r) {val[p]=c;return;}
    data_down(p);
    int m=(l+r)>>1;
    if(a<=m) change(p<<1,l,m,a,b,c);
    if(b>m) change((p<<1)+1,m+1,r,a,b,c);
    data_up;
}
  
void modify(int p,int l,int r,int a,int b)// TURN 0 to 1 OR 1 to 0
{
    if(a<=l && b>=r)
        if(val[p]!=-1)
        {
            val[p]=1-val[p];
            return;
        }
    data_down(p);
    int m=(l+r)>>1;
    if(a<=m) modify(p<<1,l,m,a,b);
    if(b>m) modify((p<<1)+1,m+1,r,a,b);
    data_up;
}
  
int count(int p,int l,int r,int a,int b)//count the number of 1
{
    if(a<=l && b>=r)
    {
        if(val[p]==1) return r-l+1;
        else if(val[p]==0) return 0;
    }
    data_down(p);
    int m=(l+r)>>1,x1=0,x2=0;
    if(a<=m) x1=count(p<<1,l,m,a,b);
    if(b>m) x2=count((p<<1)+1,m+1,r,a,b);
    data_up;
    return x1+x2;
}
  
void find(int p,int l,int r,int a,int b)//find continuous 1
{
    if(a<=l && b>=r)
    {
        if(val[p]!=-1)
        {
            if(last==1 && val[p]==1)
            {
                ans+=r-l+1;//We must add the last calculation answer
                best=max(best,ans);
            }
            else if(last==0 && val[p]==1)
            {
                ans=r-l+1;//We only need this calculation answer
                best=max(best,ans);
            }
            else if(val[p]==0) ans=0;//renew the answer
            best=max(best,ans);
            last=val[p];
            return;
        }
        if(l==r) return;
    }
    data_down(p);
    int m=(l+r)>>1;
    if(a<=m) find(p<<1,l,m,a,b);
    if(b>m) find((p<<1)+1,m+1,r,a,b);
    data_up;
}
  
void work()
{
    scanf("%d%d",&n,&m);
    int op,a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        change(1,0,n-1,i,i,a);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&op,&a,&b);
        if(op==0||op==1) change(1,0,n-1,a,b,op);
        else if(op==2) modify(1,0,n-1,a,b);
        else if(op==3) printf("%d\n",count(1,0,n-1,a,b));
        else if(op==4)
        {
            last=1;best=ans=0;
            find(1,0,n-1,a,b);
            printf("%d\n",best);
        }
        //for(int i=1;i<=10;i++) printf("%d %d\n",i,val[i]);printf("\n\n");
    }
}
  
int main()
{
    //freopen("operation.in","r",stdin);
    //freopen("operation.out","w",stdout);
    work();
    return 0;
}
