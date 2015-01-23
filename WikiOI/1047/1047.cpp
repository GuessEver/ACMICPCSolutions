#include <cstdio>
const int  M=500;
int a[20],f[M],ans[20];
int N,K,MAX,g=1<<29;
void DFS(int k,int s)
{
    int i,j,t[M];
    if (k==K)
    {
        if (s>=MAX)
            for (MAX=s,i=1;i<=K;i++) ans[i]=a[i];
        return;
    }
    for (i=0;i<M;i++) t[i]=f[i];
    for (i=a[k]+1;i<=s;i++)
    {
        for (j=0;j<M-i;j++)
            if (f[j]+1<f[j+i]) f[j+i]=f[j]+1;
        for (j=s;f[j]<=N;j++);
        a[k+1]=i;
        DFS(k+1,j);
        for (j=0;j<M;j++) f[j]=t[j];
    }
}
int main()
{
    int i;
    scanf("%d%d",&N,&K);
    a[1]=1;
    for (i=1;i<=N;i++) f[i]=i;
    for (;i<M;i++) f[i]=g;
    DFS(1,N+1);
    for (i=1;i<=K;i++) printf("%d ",ans[i]);
    printf("\nMAX=%d",MAX-1);
    return 0;
}
