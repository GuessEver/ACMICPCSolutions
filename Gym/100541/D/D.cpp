#include <cstdio>
#include <cstring>

long long n, k;
int pos[110], num[1000010];
long long f[1000010];

int find(int x)
{
	int l = 1, r = 7;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(x * (1 << mid) < 100) l = mid + 1;
		else r = mid;
	}
	return l;
}

long long solve()
{
	memset(num, 0, sizeof(num));
	memset(pos, 0, sizeof(pos));
	memset(f, 0, sizeof(f));
	int cnt = 0;
	bool flag = 0;
	while(1)
	{
		f[++cnt] = n;
		int x = n % 100;
		if(pos[x]) break;
		pos[x] = cnt;
		//printf("x = %d n = %lld ", x, n);
		if(x == 0) return n;
		int tmp = find(x);
		if(tmp > k) tmp = k;
		n -= x; k -= tmp; x *= (1 << tmp); n += x;
		num[cnt] = tmp; //printf("num = %d\n", num[cnt]);
		if(k == 0) break;
	}
	long long res = f[cnt] - f[pos[f[cnt] % 100]];
	//printf("res = %lld\n", res);
	int nn = 0;
	for(int i = pos[f[cnt]%100]; i <= cnt; i++) nn += num[i];
	//printf("%d\n", nn);
	n += res * (k / nn);
	k %= nn;
	while(k)
	{
		int x = n % 100;
		int tmp = find(x);
		if(tmp > k) tmp = k;
		n -= x; k -= tmp; x *= (1 << tmp); n += x;
	}
	return n;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &n, &k);
		printf("%lld\n", solve());
	}
	return 0;
}
