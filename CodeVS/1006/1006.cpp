#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[200],maxp;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    maxp=a[n]-a[1];
    int res=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int d=a[j]-a[i];
            int x=j,tmp=2;
            for(int k=j+1;k<=n;k++)
            {
                if(a[k]-a[x]==d)
                {
                    tmp++;x=k;
                }
            }
	        res=max(res,tmp);
        }
    }
    printf("%d\n",res);
    return 0;
}
