#include <cstdio>

int n, m;

int Joseph(int totalPeople, int nextNumber, int startIndex, int lastIdx)
{ // All based on 0_Index , the Answer is the last `lastIdx` to leave
	int now = (nextNumber - 1) % lastIdx + (startIndex - nextNumber);
	for(int i = lastIdx + 1; i <= totalPeople; i++)
		now = (now + nextNumber) % i;
	return now;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		printf("%d %d %d\n", Joseph(n, m, m, 3)+1, Joseph(n, m, m, 2)+1, Joseph(n, m, m, 1)+1);
	}
	return 0;
}
