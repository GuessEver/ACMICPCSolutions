#include <cstdio>

int n, m, k;

int solve(int totalPeople, int nextNumber, int startIndex)
{
	int now = 0;
	for(int i = 2; i < totalPeople; i++)
		now = (now + nextNumber) % i;
	now = (now + startIndex) % n;
	return now + 1; // 1_Index
}

int main()
{
	while(scanf("%d%d%d", &n, &k, &m) == 3 && (n || m || k))
		printf("%d\n", solve(n, k, m));
	return 0;
}
