#include<cstdio>

const int sum[10]={6,2,5,5,4,5,6,3,7,6};
int n,ans;

int getsum(int x)
{
    int s=0;
    do{
        s+=sum[x%10];
        x/=10;
    }while(x!=0);
    return s;
}

int main()
{
    scanf("%d",&n);n-=4;
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            if(getsum(i)+getsum(j)+getsum(i+j)==n)
                ans++;
    printf("%d",ans);
    return 0;
}
