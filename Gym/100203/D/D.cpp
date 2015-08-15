#include <cstdio>
#include <set>
#include <utility>
using std::set;
using std::pair;

int MinimumRepresentation(int *s, int l)
{
	int i = 0, j = 1, k = 0, t;
	while(i < l && j < l && k < l) {
		t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
		if(!t) k++;
		else{
			if(t > 0) i = i + k + 1;
			else j = j + k + 1;
			if(i == j) ++ j;
			k = 0;
		}
	}
	return (i < j ? i : j);
}

const int N = 10000 + 10;
const int P = 102929;
const int mod1 = 1000000000 + 7;
const int mod2 = 1000000000 + 9;
int n, m, a[200+10], b[200+10];
set<pair<int, int> > l;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		l.clear();
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &a[j]);
				a[j + m] = a[j]; 
			}
			for(int j = 0; j < m; j++)
				for(int k = j + 1; k < 2 * m; k++)
					if(a[j] == a[k])
					{
						b[j] = k - j;
						break;
					}
			for(int j = 0; j < m; j++) b[j + m] = b[j];
			int st = MinimumRepresentation(b, m);
			int hash1 = 0, hash2 = 0;
			for(int j = st; j < st + m; j++)
			{
				hash1 = (1ll * hash1 * P % mod1 + b[j]) % mod1;
				hash2 = (1ll * hash2 * P % mod2 + b[j]) % mod2;
			}
			l.insert(std::make_pair(hash1, hash2));
		}
		printf("%d\n", (int)l.size());
	}
	return 0;
}
