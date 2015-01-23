#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

int main()
{
	freopen("nocows.in","w",stdout);
	srand(time(0));
	printf("%d %d\n",(rand()%10+1)*2+1,rand()%20+1);
	return 0;
}
