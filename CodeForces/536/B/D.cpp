#include <cstdio>
#include <cstring>
#include <utility>
#include <map>
#include <vector>
using std::map;
using std::vector;
using std::make_pair;
using std::pair;

const int N = 1000000 + 10;
const int mod = 1000000000 + 7;
const unsigned long long MOD = mod; //1000000000000000007ll;
const int B = 31; //317; //100591;

int n, m, p;
char s[N];
unsigned long long hash_head[N], hash_tail[N];

int mul(int x, int y)
{
	if(y == 0) return 1;
	if(y & 1) return mul(1ll * x * x % mod, y / 2) % mod * 1ll * x % mod;
	return mul(1ll * x * x % mod, y / 2) % mod;
}

bool check(int same_len)
{
	//int cc = same_len < 100 ? same_len : 100;
	//for(int i = 0, j = p - same_len; i < cc; i++, j++) if(s[i] != s[j]) return 0;
	return hash_head[same_len-1] == hash_tail[same_len-1];
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s); p = strlen(s);
	unsigned long long now = 0;
	for(int i = 0; i < p; i++)
	{
		now = (now * B + s[i] - 'a' + 1) % MOD;
		hash_head[i] = now;
	}
	now = 0; unsigned long long k = 1;
	for(int i = p - 1; i >= 0; i--)
	{
		now = (now + (s[i] - 'a' + 1) * k) % MOD;
		k = (k * B) % MOD;
		hash_tail[p-i-1] = now;
	}
	int cnt = 0, last = 0;
	for(int i = 1; i <= m; i++)
	{
		int x; scanf("%d", &x);
		if(x >= last + 1) cnt += x - last - 1;
		else{
			if(!check(last - x + 1))
			{
				puts("0");
				return 0;
			}
		}
		last = x + p - 1;
		if(last > n)
		{
			puts("0"); 
			return 0;
		}
	}
	//printf("%d\n", last);
	cnt += n - last;
	printf("%d\n", mul(26, cnt));
	return 0;
}
