#include<bits/stdc++.h>
using namespace std;

class Mutalisk {
public:
	int minimalAttacks(vector <int>);
};

int n, f[22][140][140];
vector<int> v;

bool check(int mid)
{
	memset(f, -1, sizeof(f));
	for(int j = 0; j <= mid; j++)
		for(int k = 0; k <= mid; k++)
		{
			int q = max(0, v[0] - 9 * j - 3 * k);
			if(j + k + q > mid) continue;
			f[0][j][k] = q;
		}
	for(int i = 1; i < n; i++)
		for(int j = 0; j <= mid; j++)
			for(int k = 0; k <= mid; k++)
				for(int t = 0; t <= j; t++)
					for(int p = 0; p <= k; p++)
					{
						int one = v[i] - 9 * t - 3 * p;
						int q = max(0, one);
						if(t + p + q > mid) continue;
						if(f[i-1][j-t][k-p] != -1 && (f[i][j][k] == -1 || f[i-1][j-t][k-p] + q < f[i][j][k]))
							f[i][j][k] = f[i-1][j-t][k-p] + q;
						if(one < 0) break;
					}
	/*for(int j = 0; j <= mid; j++)
	{
		for(int k = 0; k <= mid; k++) printf("%d ", f[n-1][j][k]);
		puts("");
	}*/
	for(int j = 0; j <= mid; j++)
		for(int k = 0; k <= mid; k++)
			if(f[n-1][j][k] != -1 && f[n-1][j][k] <= mid) return 1;
	return 0;
}

int Mutalisk::minimalAttacks(vector <int> x) {
	v = x; n = x.size();
	int low = 1, high = 135;
	while(low < high)
	{
		int mid = low + (high - low) / 2;
		if(check(mid)) high = mid;
		else low = mid + 1;
	}
	return high;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

