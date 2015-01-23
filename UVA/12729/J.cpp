#include <cstdio>
#include <algorithm>

int n, m;

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case #%d: ", cas);
		scanf("%d%d", &n, &m);
		if(n > m) std::swap(n, m);
		//int A = (n / 2 * 2) * ((m + 2) / 4 * 2);
		//int B = n * m - A;
		int A = 0, B = 0;
		bool flag = 0;
		int tmp = n;
		while(tmp > 1)
		{
			if(flag) A += m / 4;
			else A += (m + 2) / 4;
			if(m % 4 != 0) flag = !flag;
			tmp -= 2;
		}
		A = A * 4;
		B = n * m - A;
		//printf("%d %d\n", A, B);
		if(A > B) printf("Ana\n");
		else if(A < B) printf("Bob\n");
		else printf("Draw\n");
	}
	return 0;
}
