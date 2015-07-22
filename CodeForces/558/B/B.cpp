#include <cstdio>
#include <cstring>

const int N = 100000 + 10;
const int A = 1000000;

int n, a[N];
int cnt[A+10], L[A+10], R[A+10];

int main()
{
	memset(L, -1, sizeof(L));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(L[a[i]] == -1) L[a[i]] = i;
		R[a[i]] = i;
		cnt[a[i]]++;
	}
	int max = 0;
	for(int i = 1; i <= A; i++)
		if(cnt[i] > max) max = cnt[i];
	int len = -1, l = -1, r = -1;
	for(int i = 1; i <= A; i++)
		if(cnt[i] == max)
			if(len == -1 || R[i] - L[i] + 1 < len)
			{
				len = R[i] - L[i] + 1;
				l = L[i];
				r = R[i];
			}
	printf("%d %d\n", l, r);
	return 0;
}
