#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300000+10;
int n,a[N];
int f[N];
int main()
{
	//freopen("c.in","r",stdin);
	while(scanf("%d",&a[n++])==1);n--;
	for(int i=0;i<n;i++) f[i]=1;
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j]>=a[i]) f[i]=max(f[i],f[j]+1);
	printf("%d\n",f[max_element(f,f+n)-f]);
	for(int i=0;i<n;i++) f[i]=1;
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
	printf("%d\n",f[max_element(f,f+n)-f]);
	//while(1);
	return 0;
}
