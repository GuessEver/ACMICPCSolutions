#include <cstdio>
#include <set>
using std::set;

int mul(int x, int y)
{
	int res = 1;
	while(y)
	{
		if(y & 1) res *= x;
		x *= x; y >>= 1;
	}
	return res;
}

int n;
set<int> st;

void solve(int x)
{
	for(int i = 2; i <= x; i++) if(x % i == 0)
	{
		int tmp = 0;
		while(x % i == 0) { x /= i; tmp++; }
		tmp = mul(i, tmp);
		st.insert(tmp);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) solve(i);
	printf("%d\n", (int)st.size());
	for(set<int>::iterator it = st.begin(); it != st.end(); it++)
		printf("%d ", *it);
	return 0;
}
