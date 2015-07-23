#include <cstdio>
#include <vector>
using std::vector;

int N;
vector<int> d;
int f[1010];

int main()
{
	int ans = 0;
	int n = d.size();
	for(int i = 0; i < n; i++)
	{
		f[i] = 1;
		for(int j = 0; j < i; j++)
			if(d[i] <= d[j] && f[i] < f[j] + 1)
				f[i] = f[j] + 1;
		if(ans < f[i]) ans = f[i];
	}
	printf("%d\n", ans);
	return 0;
}
