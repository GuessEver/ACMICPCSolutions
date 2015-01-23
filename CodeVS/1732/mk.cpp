#include<cstdio>
#include<cstdlib>
#include<ctime>

long long random(long long n)
{
	double ra=(double)rand()/RAND_MAX;
	return (long long)(ra*(n-1)+0.5);
}

int main()
{
	freopen("1732.in","w",stdout);
	srand(time(0));
	int T=rand()%10+3;
	while(T--)
	{
		int n=random(10000000)+1;
		printf("%d\n",n);
	}
	return 0;
}
