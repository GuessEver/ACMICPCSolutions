#include<cstdio>
#include<cstring>
const int N=150;
int n;
int a[N][N];
int dist[N];
bool h[N];
int res;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	memset(dist,0x3f,sizeof(dist));dist[1]=0;
	for(int i=1;i<=n;i++)
	{
		int k=-1;
		for(int j=1;j<=n;j++)
		if(!h[j]&&(k==-1||dist[j]<dist[k])) k=j;
		h[k]=true;
		res+=dist[k];
		for(int j=1;j<=n;j++)
		if(!h[j] && dist[j]>a[k][j]) dist[j]=a[k][j];
	}
	printf("%d\n",res);
	return 0;
}
