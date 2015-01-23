#include<cstdio>

int n,h[10010];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        int x;scanf("%d",&x);
        h[x]=1;
    }
    for(int i=0;i<10000;i++)
        if(!h[i]) printf("%d\n",i);
    return 0;
}
