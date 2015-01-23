#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>

int main()
{
	freopen("1831.in","w",stdout);
	srand(time(0));
	int n=50,m=100,K=13;
	printf("%d %d %d\n",n,m,K);
	for(int i=1;i<=n;i++) printf("%c\n",rand()%26+'A');
	while(m--)
	{
		int op=rand()%100>50?1:0;
		if(op) printf("ADD(%c)\n",rand()%26+'A');
		else printf("ROTATE\n");
	}
	return 0;
}
