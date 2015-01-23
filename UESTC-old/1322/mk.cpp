#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>

int hash[300];

void work()
{
	memset(hash,0,sizeof(hash));int cnt=0;
	int n=150,m=280;
	printf("%d %d\n",n,m);
	while(m--)
	{
		int x=rand()%n+1;
		int y=rand()%n+1;
		while(x==y) 
		{
			x=rand()%n+1;
			y=rand()%n+1;
		}
		int z=rand()%10+1;
		printf("%d %d %d\n",x,y,z);
	}
	int q=rand()%(n/2)+1;
	printf("%d\n",q);
	while(q--)
	{
		int op=rand()%100>70?0:1;
		if(cnt==n) op=0;
		if(!op)
		{
			int x=rand()%n+1;
			int y=rand()%n+1;
			while(x==y) 
			{
				x=rand()%n+1;
				y=rand()%n+1;
			}
			printf("%d %d %d\n",op,x,y);
		}
		if(op)
		{
			int x=rand()%n+1;
			while(hash[x]) x=rand()%n+1;
			hash[x]=1;
			printf("%d %d\n",op,x);
		}
	}
}

int main()
{
	freopen("1322.in","w",stdout);
	srand(time(0));
	int t=3; printf("%d\n",t);
	while(t--) {work();printf("\n");}
	return 0;
}
