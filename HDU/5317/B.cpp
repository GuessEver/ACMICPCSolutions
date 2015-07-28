#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

int maxp = 1000000;
int pri[1000000+10], Cnt;
bool hash[1000000+10];

void make_prime_list()
{
	for(int i = 2; i <= maxp; i++)
	{
		if(!hash[i]) pri[Cnt++] = i;
		for(int j = 0; j < Cnt && pri[j] <= maxp / i; j++)
		{
			hash[i * pri[j]] = true;
			if(i % pri[j] == 0) break;
		}
	}
}
int f[1000000+10];
int factor(int x)
{
	int cnt = 0;
	for(int j = 0; j < Cnt && pri[j]*pri[j] <= x; j++)
	{
		if(x % pri[j] == 0)
		{
			//printf("%d ", pri[j]);
			cnt++;
			while(x % pri[j] == 0) x /= pri[j];
		}
	}
	if(x!=1)
	{
		cnt++;
		//printf("%d",x);
	}
	return cnt;
}

vector<int> v[10];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
	make_prime_list();
	for(int i = 1; i <= 1000000; i++)
	{
		f[i] = factor(i);
		v[f[i]].push_back(i);
		if(f[i] == 6)
		{
			v[3].push_back(i);
			v[2].push_back(i);
		}
		else if(f[i] == 4)
		{
			v[2].push_back(i);
		}
	}
	//for(int i = 1; i <= 100; i++) printf("%d: %d\n", i, f[i]);
	int T; scanf("%d", &T);
	while(T--)
	{
		int l, r, g = 1; scanf("%d%d", &l, &r);
		for(int i = 7; i > 1; i--)
		{
			vector<int>::iterator it = std::lower_bound(v[i].begin(), v[i].end(), l);
			if(it == v[i].end()) continue;
			vector<int>::iterator jt = it + 1;
			if(jt == v[i].end()) continue;
			if(*it <= r && *jt <= r)
			{
				g = i;
				break;
			}
		}
		printf("%d\n", g);
	}
	return 0;
}
