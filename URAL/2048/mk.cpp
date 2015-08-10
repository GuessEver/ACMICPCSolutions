#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int A = rand()%100000;
	int B = A + rand()%100000;
	printf("%d %d\n", A, B);
	return 0;
}
