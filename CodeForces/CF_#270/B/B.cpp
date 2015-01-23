#include <cstdio>
#include <algorithm>

const int N = 5000 + 10;

int n, k;
int a[N];
int Q[N], L, R, de;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	std::sort(a+1, a+1+n);
	if(n <= k) printf("%d\n", a[n]*2);
	else{
		/*
		L = 0; R = 0; de = 0;
		for(int i = 1; i < k; i++) Q[R++] = a[i] + de;
		int i = k - 1;
		int res = 0;
		while(++i <= n)
		{
			Q[R++] = a[i] + de;
			if(R - L > k) L++;
			if(i < n) res += (Q[L] - de) * 2;
			else res += (Q[R-1] - de) * 2;
			de = Q[L];
		}
		printf("%d\n", res);*/
		int ok = 0;
		int res = 0;
		while(ok < n)
		{
			int tmp = a[ok+1];
			res += tmp * 2;
			for(int i = ok + 1; i <= ok + k && i <= n; i++)
				a[i] -= tmp;
			ok++;
		}
		printf("%d\n", res);
	}
	return 0;
}
