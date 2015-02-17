#include <cstdio>
#include <cstring>

int candle[10], cnt[10];

bool combine(int x)
{
	do{
		cnt[x % 10] ++;
		if(cnt[x % 10] > candle[x % 10]) return 0;
		x /= 10;
	}while(x);
	return 1;
}

bool check(int age, int S)
{
	for(int i = 0; i < 10; i++)
	{
		candle[i] = S & 1;
		S >>= 1;
	}
	memset(cnt, 0, sizeof(cnt));
	bool flag = combine(age);
	for(int i = 1; i < age; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		flag |= (combine(i) && combine(age - i));
		if(flag) break;
	}
	return flag;
}

int n, a[20];
bool cc[200][2000];

long long solve(int S)
{
	for(int i = 0; i < n; i++)
		if(!cc[a[i]][S]) return -1;
	long long res = 0, k = 1;
	for(int i = 0; i < 10; i++)
	{
		if(S & 1)
		{
			res = res + i * k;
			k *= 10;
		}
		S >>= 1;
	}
	return res;
}

int main()
{
	int cas = 0;
	int tot = (1 << 10);
	for(int i = 1; i <= 100; i++)
		for(int S = 0; S < tot; S++)
			cc[i][S] = check(i, S);
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		long long res = -1;
		for(int S = 0; S < tot; S++)
		{
			long long tmp = solve(S);
			if(tmp == -1) continue;
			if(res == -1 || tmp < res) res = tmp;
		}
		printf("Case %d: %lld\n", ++cas, res);
	}
	return 0;
}
