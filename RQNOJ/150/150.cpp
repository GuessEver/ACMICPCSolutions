#include<cstdio>
#define MAXN 710

typedef struct{int a,b,c;}tnode;

int x[MAXN],y[MAXN],n;

void read()
{
     //freopen("rqn150.in","r",stdin);
     //freopen("rqn150.out","w",stdout);
     scanf("%d",&n);
     for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
}

void work()
{
     int i,j,k,sum,max=0;
     int a,b,c;
     for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            sum=0;
            a=y[j]-y[i];
            b=x[i]-x[j];
            c=b*y[i]+a*x[i];
            for(k=1;k<=n;k++)
                if(a*x[k]+b*y[k]==c)sum++;
            max>?=sum;
        }
     printf("%d",max);
}

int main()
{
     read();
     work();
     return 0;
}

