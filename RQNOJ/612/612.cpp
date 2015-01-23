#include<cstdio>
#include<string>
using namespace std;

int n,k,ways=0;
int a[300]={0};
bool h[9999999];

void fen(int i,int sum)
{
    if(i==k)//这里直接判断最后一个是否大于等于其前面一个即可  少递归一次  不然要超时！
    {
        if(a[i-1]<=n-sum)ways++;
        return;
    }

    int j;
    if(sum==n)return;
    for(j=a[i-1];j<=n-sum;j++)
    {
        if(j<1)continue;
        a[i]=j;
        fen(i+1,sum+j);
    }
}

int main()
{
    //freopen("p2.in","r",stdin);
    //freopen("p2.out","w",stdout);
    scanf("%d%d",&n,&k);
    fen(1,0);
    printf("%d",ways);
    return 0;
}

