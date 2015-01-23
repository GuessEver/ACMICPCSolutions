#include<stdio.h>
#include<string.h>
long map[410][410],n,k;
void print(long a,long b)
{
    long si,sj,i,j;
    si=b;
    sj=a;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if((i-1)*n+j>k)return ;
            else
            {
                map[(si+i-1)%n+(a-1)*n+1][(sj+j-1)%n+(b-1)*n+1]=1;
            }

}
int main()
{
    long i,j;
    scanf("%ld%ld",&n,&k);
    for(i=1;i<=n*n;i++)
        for(j=1;j<=n*n;j++)
            map[i][j]=0;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            print(i,j);

    for(i=1;i<=n*n;i++)
        {
            for(j=1;j<=n*n;j++)
                if(map[i][j]==0)printf(".");
                else         printf("*");
            printf("\n");
        }
    return 0;
}
