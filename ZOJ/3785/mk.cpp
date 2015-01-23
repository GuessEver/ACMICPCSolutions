#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 4; printf("%d\n", T);
	while(T--) printf("%d\n", rand()%100+2);
	return 0;
}
