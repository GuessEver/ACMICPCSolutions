#include<cstdio>
#include<algorithm>
using std::max;
#define MAXN 100
#define MAXP 33000

int n,m,p[MAXN][5],v[MAXN][5],count[MAXN],f[MAXP];

void read()
{
    scanf("%d%d",&n,&m);
    int i,j,x,y,z;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        y*=x;
        if(z==0)
        {
            p[i][0]=x;
            v[i][0]=y;
        }
        else{
            ++count[z];
            p[z][count[z]]=p[z][0]+x;
            v[z][count[z]]=v[z][0]+y;
        }
    }
    for(i=1;i<=m;i++)
    {
        if(p[i][0]==0)continue;
        p[i][3]=p[i][1]+p[i][2];
        v[i][3]=v[i][1]+v[i][2];
        if(p[i][2]!=0)
        {
            p[i][3]-=p[i][0];
            v[i][3]-=v[i][0];
        }
    }
    /*for(i=1;i<=m;i++)
    {
        for(j=0;j<=3;j++)
            printf("price=%3d  val=%3d\n",p[i][j],v[i][j]);
        printf("\n");
    } */
}

int main()
{
    //freopen("budget.in","r",stdin);
    //freopen("budget.out","w",stdout);
    read();
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=0;j--)
        {
            if(j>=p[i][0])f[j]=max(f[j],f[j-p[i][0]]+v[i][0]);
            if(j>=p[i][1])f[j]=max(f[j],f[j-p[i][1]]+v[i][1]);
            if(j>=p[i][2])f[j]=max(f[j],f[j-p[i][2]]+v[i][2]);
            if(j>=p[i][3])f[j]=max(f[j],f[j-p[i][3]]+v[i][3]);
        }
    }
    printf("%d",f[n]);
    return 0;
}
