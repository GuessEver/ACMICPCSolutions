#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a[10000+10];

int main()
{
    int k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(k--) next_permutation(a+1,a+1+n);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

