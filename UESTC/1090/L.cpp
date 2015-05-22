#include <cstdio>
#include <cstring>
#include <utility>
#include <set>
using std::pair;
using std::set;

const int P = 102929;
const int mod1 = 1000000000 + 7;
const int mod2 = 1000000000 + 9;
const int N = 2 * 2 * 100000 + 10;

int n, k;
char s[N];
typedef pair<int, int> pir;
set<pir> l;
int smaller = 0, equal = 0, bigger = 0;
pir hash[N];
int fac1[N], fac2[N];

/*
int mul(int x, int y, int mod)
{
	if(y == 0) return 1;
	if(y & 1) return 1ll * mul(1ll * x * x % mod, y / 2, mod) * x % mod;
	return mul(1ll * x * x % mod, y / 2, mod) % mod;
}
*/

pir getHash(int l, int r)
{
	int hash1 = ((hash[r].first - (l == 0 ? 0 : hash[l-1].first)) % mod1 + mod1) % mod1;
	int hash2 = ((hash[r].second - (l == 0 ? 0 : hash[l-1].second)) % mod2 + mod2) % mod2;
	hash1 = 1ll * hash1 * fac1[l] % mod1;
	hash2 = 1ll * hash2 * fac2[l] % mod2;
	return std::make_pair(hash1, hash2);
}

void solve(int l1, int l2)
{
	pir now = getHash(l1, l1 + n - 1);
	if(l.find(now) != l.end()) return; // caculated before
	l.insert(now);
	int low = 0, high = n, ans = 0;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		pir hash1 = getHash(l1, l1 + mid - 1);
		pir hash2 = getHash(l2, l2 + mid - 1);
		if(hash1 == hash2) { low = mid + 1; ans = mid; }
		else high = mid - 1;
	}
	if(ans == n) equal++;
	else if(s[l1+ans] < s[l2+ans]) smaller++;
	else if(s[l1+ans] > s[l2+ans]) bigger++;
	//for(int i = l1; i < l1 + n; i++) putchar(s[i]); puts("");
}

int main()
{
	fac1[0] = fac2[0] = 1;
	scanf("%s%d", s, &k); n = strlen(s);
	for(int i = 1; i <= 2 * n; i++)
	{
		fac1[i] = 1ll * fac1[i-1] * P % mod1;
		fac2[i] = 1ll * fac2[i-1] * P % mod2;
	}
	for(int i = 0; i < n; i++) s[i+n] = s[i];
	s[2 * n] = 0; // [t, t + n) for t second(s) later
	//puts(s);
	for(int i = 0; i < 2 * n; i++)
	{
		hash[i].first  = (1ll * (s[i] - 'a' + 1) * fac1[2 * n - i - 1]) % mod1;
		hash[i].second = (1ll * (s[i] - 'a' + 1) * fac2[2 * n - i - 1]) % mod2;
		if(i)
		{
			hash[i].first  = (1ll * hash[i-1].first  + hash[i].first ) % mod1;
			hash[i].second = (1ll * hash[i-1].second + hash[i].second) % mod2;
		}
	}
	for(int i = 0; i < n; i++) solve(i, k);
	printf("%d %d %d\n", smaller, equal, bigger);
	return 0;
}
