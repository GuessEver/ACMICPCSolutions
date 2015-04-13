#include <cstdio>
#include <algorithm>

const int N = 2 * 100000 + 10;

int n, d[N];
long long S, A;

int main()
{
	scanf("%d%I64d", &n, &A);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		S += d[i];
	}
	for(int i = 1; i <= n; i++)
	{
		long long canL = n - 1, canR = S - d[i];
		long long L = A - canR, R = A - canL;
		if(L <= 1 && R >= d[i]) printf("0 ");
		else if(R < 1 || L > d[i]) printf("%d ", d[i]);
		else if(L >= 1 && R <= d[i]) printf("%d ", d[i] - (R - L + 1));
		else {
			long long nL = std::max(L, 1ll);
			long long nR = std::min(R, d[i] * 1ll);
			printf("%I64d ", d[i] - (nR - nL + 1));
		}
	}
	return 0;
}
