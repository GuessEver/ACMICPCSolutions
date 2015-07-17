#include <cstdio>
#include <algorithm>

const int N = 3000 + 10;

int a[N];
int n;
int Cnt = 0, A[N*N], B[N*N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
	{
		int k = -1;
		for(int j = 0; j < n - i; j++)
			if(k == -1 || a[j] > a[k]) k = j;
		std::swap(a[k], a[n-i-1]);
		Cnt++;
		A[Cnt] = k;
		B[Cnt] = n-i-1;
	}
	printf("%d\n", Cnt);
	for(int i = 1; i <= Cnt; i++) printf("%d %d\n", A[i], B[i]);
	return 0;
}
