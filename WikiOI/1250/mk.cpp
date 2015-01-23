#include<cstdio>
#include<cstdlib>
#include<ctime>
int main()
{
	freopen("1250.in","w",stdout);
	srand(time(0));
	int T=rand()%3+3;printf("%d\n",T);
	while(T--)
	{
		int n=rand()%100+1;
		int q=rand()%100+1;
		printf("%d %d\n",n,q);
	}
	return 0;
}
