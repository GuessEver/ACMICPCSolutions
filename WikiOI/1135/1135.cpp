#include<cstdio>
#define MAXN 200010

int n,colors,minp,c[MAXN],p[MAXN];
int pre[MAXN],count[MAXN],sum[MAXN];

int main()
{
    scanf("%d%d%d",&n,&colors,&minp);
    int i,j;
    for(i=1;i<=n;i++)
        scanf("%d%d",&c[i],&p[i]);
    for(i=1;i<=n;i++)
        for(j=i-1;j>=1;j--)
            if(c[i]==c[j]) {pre[i]=j;break;}//处理前向星
    for(i=1;i<=n;i++)
        count[i]=count[pre[i]]+1;//1~i 中（包括i）跟i色调相同的个数
    for(i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        if(p[i]<=minp)sum[i]++;//处理1~i中（包括i）满足最低消费的个数
    }
    int ans=0;
    for(i=2;i<=n;i++)
    {
        j=pre[i];
        while(j)
        {
            if(sum[i]-sum[j-1]>0){ans+=count[j];break;}
            j=pre[j];
        }
    }
    printf("%d",ans);
    return 0;
}
