/*
ID: jiangzh15
TASK: ariprog
LANG: C++
*/
#include<cstdio>
#include<utility>
#include<queue>
using namespace std;

bool h[250*250*2+10];
int n,m,maxv;

bool check(int a,int b)
{
    for(int i=0;i<n;i++)
        if(!h[a+i*b]) return false;
    return true;
}

int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<=m;i++)
        for(j=0;j<=m;j++)
            h[i*i+j*j]=true;
    maxv=m*m*2;
    bool flag=false;
    for(j=1;j<=maxv;j++)//由于按照b排序  所以b放在外层
        for(i=0;i<=maxv;i++)
        {
            if(i+(n-1)*j>maxv)break;
            if(check(i,j))
            {
                printf("%d %d\n",i,j);
                flag=true;
            }
        }
    if(!flag)printf("NONE\n");
    return 0;
}
