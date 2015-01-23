#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;

const int N = 4000 + 10;

int n[10], a[10][N];

int solve()
{
	int i = 1, j = 1, k = 1;
	int res = 0;
	while(i <= n[1] && j <= n[2] && k <= n[3])
	{
		if(a[1][i] == a[2][j] && a[1][i] == a[3][k])
		{
			res++;
			i++; j++; k++;
			continue;
		}
		if(a[1][i] <= a[2][j] && a[1][i] <= a[3][k]) i++;
		else if(a[2][j] <= a[1][i] && a[2][j] <= a[3][k]) j++;
		else if(a[3][k] <= a[1][i] && a[3][k] <= a[2][j]) k++;
	}
	return res;
}

int main()
{
	for(int i = 1; i <= 3; i++)
	{
		scanf("%d", &n[i]);
		for(int j  = 1; j <= n[i]; j++)
			scanf("%d", &a[i][j]);
	}
	printf("%d\n", solve());
	return 0;
}
