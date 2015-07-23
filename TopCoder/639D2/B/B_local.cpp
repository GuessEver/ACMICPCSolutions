#include <cstdio>
#include <cmath>
#include <algorithm>
using std::max;

long long find(long long l, long long r, long long x)
{
	long long mid, ans = l;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		if(mid <= x) { l = mid+1; ans = mid; }
		else r = mid - 1;
	}
	return ans;
}

long long solve(long long x, long long y)
{
	long long tmp = (long long)sqrt(2.0 * (x + y));
	//printf("tmp = %I64d\n", tmp);
	long long n = -1;
	for(long long i = max(0ll, tmp-2); i <= tmp+2; i++)
	{
		long long tt;
		if(i & 1) tt = (i + 1) / 2 * i;
		else tt = i / 2 * (i + 1);
		if(tt == x + y) { n = i; break; }
	}
	if(n == -1) return -1;
	//printf("n = %I64d\n", n);
	long long cnt = 0, last = n+1;
	while(x > 0)
	{
		long long sub = find(1, last-1, x);
		//printf("sub = %I64d\n", sub);
		x -= sub; cnt++; last = sub;
	}
	return cnt;
}

int main()
{
	long long x, y;
	scanf("%I64d%I64d", &x, &y);
	
	printf("answer = %I64d\n", solve(x, y));
	
	return 0;
}
