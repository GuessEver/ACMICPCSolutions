#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 200010
int dat[N],sum[N];

int n,m,k;
///线段树 区间更新 区间最值
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define fmid int m = (l+r)>>1

int ma[N*4],cnt[N*4];

void Push_up(int rt)
{
    ma[rt] = max(ma[rt<<1],ma[rt<<1|1]);
}
void Push_down(int rt)
{
    if(cnt[rt] != 0)
    {
        ma[rt<<1]    += cnt[rt];
        ma[rt<<1|1]  += cnt[rt];
        cnt[rt<<1]   += cnt[rt];
        cnt[rt<<1|1] += cnt[rt];
        cnt[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    cnt[rt] = 0;
    if(l == r)
    {
        ma[rt] = sum[l+k-1] - sum[l-1];
        return ;
    }
    fmid;
    build(lson);
    build(rson);
    Push_up(rt);
}
void update(int L,int R,int val,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        cnt[rt] += val;
        ma[rt] += val;
        return ;
    }
    Push_down(rt);
    fmid;
    if(L <= m) update(L,R,val,lson);
    if(m < R) update(L,R,val,rson);
    Push_up(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return ma[rt];
    }
    Push_down(rt);
    fmid;
    int re = -999999999;
    //cout << re << " ";
    if(L <= m) re = max(re,query(L,R,lson));
    if(m < R) re = max(re,query(L,R,rson));
    return re;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1;i <= n;i++) scanf("%d",&dat[i]);
        sum[0] = 0;
        for(int i = 1;i <= n;i++) sum[i] = sum[i-1] + dat[i];

        build(1,n-k+1,1);

        int p,x,y;
        while(m--)
        {
            scanf("%d%d%d",&p,&x,&y);
            if(p == 0)
            {
                update(max(1,x - k + 1),min(x,n-k+1),y - dat[x],1,n-k+1,1);
                dat[x] = y;
            }else if(p == 1)
            {
                update(max(1,x - k + 1),min(x,n-k+1),dat[y] - dat[x],1,n-k+1,1);
                update(max(1,y - k + 1),min(y,n-k+1),dat[x] - dat[y],1,n-k+1,1);
                int t = dat[x];dat[x] = dat[y];dat[y] = t;
            }else
            {
                int tt = query(x,y-k+1,1,n-k+1,1);
                printf("%d\n",tt);
            }
        }
    }
    return 0;
}

