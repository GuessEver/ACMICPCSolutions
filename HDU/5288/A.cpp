#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using std::map;

const int N = 100000 + 10;
const int A = 10000 + 10;
const int mod = 1000000000 + 7;

int n, a[N];
int pos[A];
int L[N], R[N];

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(pos, 0, sizeof(pos));
		for(int i = 1; i <= n; i++)
		{
			L[i] = 0;
			for(int j = 1; j * j <= a[i]; j++) if(a[i] % j == 0)
			{
				L[i] = std::max(L[i], pos[j]);
				L[i] = std::max(L[i], pos[a[i] / j]);
			}
			pos[a[i]] = i;
		}
		//for(int i = 1; i <= n; i++) printf("%d ", L[i]); puts("");
		memset(pos, 0x3f, sizeof(pos));
		for(int i = n; i >= 1; i--)
		{
			R[i] = n + 1;
			for(int j = 1; j * j <= a[i]; j++) if(a[i] % j == 0)
			{
				R[i] = std::min(R[i], pos[j]);
				R[i] = std::min(R[i], pos[a[i] / j]);
			}
			pos[a[i]] = i;
		}
		//for(int i = 1; i <= n; i++) printf("%d ", R[i]); puts("");
		int res = 0;
		for(int i = 1; i <= n; i++)
			res = (res + 1ll * (i - L[i]) * (R[i] - i)) % mod;
		printf("%d\n", res);
	}
	return 0;
}
