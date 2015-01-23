#include<cstdio>
#include<ctime>
#include<cstdlib>

int main()
{
	freopen("1827.in","w",stdout);
	srand(time(0));
	int num=100;
	int n=50; int m=60;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",rand()%num+1); puts("");
	printf("%d\n",m);
	while(m--)
	{
		int op=rand()%100>40?1:0;
		if(op) printf("%d %d %d\n",op,rand()%n+1,rand()%n+1);
		else printf("%d %d %d %d\n",op,rand()%n+1,rand()%n+1,rand()%num+1);
	}
	return 0;
}
