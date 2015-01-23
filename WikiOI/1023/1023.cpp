#include<cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    double sum=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        sum+=a*b;
        cnt+=a;
    }
    printf("%.2lf\n",sum/cnt);
    return 0;
}
