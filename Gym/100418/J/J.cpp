#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned long long l, r;
int L[70], R[70];
unsigned long long f[70][2][2][70][70];
int vis[70][2][2][70][70];

int predo(unsigned long long a, int *num)
{
	int len = 0;
	do num[++len] = (a & 1); while(a >>= 1);
	return len;
}

unsigned long long calc(int pos, bool d, bool u, int cnt, int sum, int mod)
{
	if(pos == 0) return sum == 0 && cnt == mod;
	unsigned long long &res = f[pos][d][u][cnt][sum];
	if(vis[pos][d][u][cnt][sum] == mod) return res;
	res = 0; vis[pos][d][u][cnt][sum] = mod;
	int st = d ? L[pos] : 0;
	int ed = u ? R[pos] : 1;
	for(int i = st; i <= ed; i++)
	{
		if(cnt + i > mod) continue;
		int x = (sum + ((1ull * i) << (pos - 1))) % mod;
		res += calc(pos-1, d && i == L[pos], u && i == R[pos], cnt + i, x, mod);
	}
	return res;
}

int main()
{
	l = 1;
	while(cin >> r)
	{
		unsigned long long res = 0;
		for(int i = 1; i <= 63; i++)
		{
			int len = std::max(predo(l, L), predo(r, R));
			res += calc(len, 1, 1, 0, 0ull, i);
		}
		cout << res << endl;
	}
	return 0;
}
