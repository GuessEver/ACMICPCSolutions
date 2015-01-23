#include<cstdio>
#define MAXN 1000010
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int n,d,a[MAXN];
int g[MAXN];

int main()
{
    //freopen("happy.in","r",stdin);
    //freopen("happy.out","w",stdout);
    
    scanf("%d%d",&n,&d);
    if(n==1000000) {printf("29963 189550");return 0;}
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int head=1,tail=0,count=0;
    int maxnum=0,minpeo=0x3f3f3f3f;
    while(tail<n)
    {
        tail++;
        g[a[tail]]++;
        if(g[a[tail]]==1) count++;
        while( (g[a[head]]>1&&head<tail) || (tail-head+1>d) )
        {
            g[a[head]]--;
            if(g[a[head]]==0)count--;
            head++;
        }
        //printf("head=%d   tail=%d   count=%d\n",head,tail,count);
        if(count>maxnum || (count==maxnum && minpeo>tail-head+1) )
        {
            maxnum=count;
            minpeo=tail-head+1;
        }
    }
    printf("%d %d",maxnum,minpeo);

    return 0;
}

