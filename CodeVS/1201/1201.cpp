#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[1000];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int minx=min_element(a,a+n)-a;
	int maxx=max_element(a,a+n)-a;
	printf("%d %d",a[minx],a[maxx]);
	return 0;
}
