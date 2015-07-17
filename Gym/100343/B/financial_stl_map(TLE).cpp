#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

const int N = 100000 + 10;

int n;
long long k, a[N], ans[N];
int f[N], pre[N];
struct cmpmap{
	bool operator () (const int &a, const int &b) const
	{
		return f[a] >= f[b];
	}
};

map<int, long long, cmpmap> fuck;


typedef map<int, long long, cmpmap>::iterator ITR;
typedef map<int, long long, cmpmap> MAP;

void printans(int x)
{
	if(!pre[x])
	{
		printf("%I64d", a[x]);
		return;
	}
	printans(pre[x]);
	printf(" %I64d", a[x]);
}

class map_finder
{
	public:
		map_finder(long long now):kk(now){}
		bool operator ()(const MAP::value_type &pair)
		{
			return abs(pair.second - kk) >= k;
		}
	private:
		const long long kk;
};


int main()
{
	freopen("financial.in", "r", stdin);
	freopen("financial.out", "w", stdout);
	scanf("%d%I64d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
	f[1] = 1; fuck.insert(make_pair(1, a[1]));
	for(int i = 2; i <= n; i++)
	{
		//printf("%d:\n", i);
		f[i] = 1;
		/*for(int j = 1; j < i; j++)
			if(abs(a[i] - a[j]) >= k)
			{
				if(f[j] + 1 > f[i])
				{
					f[i] = f[j] + 1;
					pre[i] = j;
				}
			}*/
		ITR itr = find_if(fuck.begin(), fuck.end(), map_finder(a[i]));
		if(itr != fuck.end())
		{
			//printf("%d\n", itr->first);
			if(f[itr->first] + 1 > f[i])
			{
				f[i] = f[itr->first] + 1;
				pre[i] = itr->first;
			}
		}
		fuck.insert(make_pair(i, a[i]));
	}
	//for(int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
	//for(int i = 1; i <= n; i++) printf("%d ", pre[i]); puts("");
	int k = -1;
	for(int i = 1; i <= n; i++)
		if(k == -1 || f[i] > f[k]) k = i;
	printf("%d\n", f[k]);
	//printans(k);
	int Cnt = 0;
	for(int i = k; i; i = pre[i]) ans[Cnt++] = a[i];
	for(int i = Cnt-1; i > 0; i--) printf("%d ", ans[i]); printf("%d\n", ans[0]);
	return 0;
}
