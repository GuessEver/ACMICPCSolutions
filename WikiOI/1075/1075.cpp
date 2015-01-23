#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[1000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int m=unique(a,a+n)-a;
	printf("%d\n",m);
	for(int i=0;i<m;i++) printf("%d ",a[i]);
	//while(1);
	return 0;
}
