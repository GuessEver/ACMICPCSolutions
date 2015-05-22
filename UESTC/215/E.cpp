#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 64 + 10;

int n, a[N];
bool used[N];

bool dfs(int x, int single, int now, int sum, int st)
{
	if(now == single) return dfs(x, single, 0, sum, 1); // a new stick
	if(x > n) return now == 0 && sum == 0;
	if(now + sum < single) return 0; // cannot forever
	int left = sum - (single - (now == 0 ? single : now));
	if(left % single != 0) return 0; // cannot make it since now
	for(int i = st; i <= n; i++) // search from st
	{

		if(now + a[i] > single) continue;
		if(!used[i])
		{
			used[i] = 1;
			if(dfs(x + 1, single, now + a[i], sum - a[i], i + 1)) return 1; // find a right way
			used[i] = 0;
			// using a[i] right now is not correct
			while(a[i] == a[i+1]) i++; // so which equals to a[i] cannot make sense of course
			if(now + a[i] == single || now == 0) return 0; // if cannot make it when finishing a new stick, it cannot make it forever
		}
	}
	return 0;
}

bool cmp(int a, int b) { return a > b; }

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		std::sort(a+1, a+1+n, cmp);
		for(int single = a[1]; single <= sum; single++) if(sum % single == 0)
		{
			memset(used, 0, sizeof(used));
			if(dfs(1, single, 0, sum, 1))
			{
				printf("%d\n", single);
				break;
			}
		}
	}
	return 0;
}
