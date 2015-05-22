#include <cstdio>
#include <cstring>
#include <algorithm>

int num['Z'+10];
bool used[10];
int n, len[20], maxp;
char s[20][20];
long long res = 0;

void dfs(int x, int y, int sum) // xth expression, y's position
{
	if(x == n - 1)
	{
		if(num[s[x][y]] != -1)
		{
			if(y == len[x] - 1 && len[x] > 1 && num[s[x][y]] == 0) return;
			if(num[s[x][y]] == sum % 10)
			{
				if(y == maxp - 1)
				{
					if(sum < 10)
					{
						/*for(int i = 0; i < n; i++)
						{
							for(int j = 0; j < len[i]; j++) printf("%d", num[s[i][j]]);
							puts("");
						} puts(""); */
						res++;
					}
					return;
				}
				dfs(0, y + 1, sum / 10);
			}
		}
		else{
			if(used[sum%10]) return;
			if(y == len[x] - 1 && len[x] > 1 && sum % 10 == 0) return;
			if(y == maxp - 1)
			{
				if(sum < 10)
				{
					/*for(int i = 0; i < n; i++)
					{
						for(int j = 0; j < len[i]; j++) printf("%d", num[s[i][j]]);
						puts("");
					} puts(""); */
					res++;
				}
				return;
			}
			used[sum%10] = 1;
			num[s[x][y]] = sum % 10;
			dfs(0, y + 1, sum / 10);
			num[s[x][y]] = -1;
			used[sum%10] = 0;
		}
		return;
	}
	if(!s[x][y]) dfs(x + 1, y, sum);
	else {
		if(num[s[x][y]] != -1)
		{
			if(y == len[x] - 1 && len[x] > 1 && num[s[x][y]] == 0) return;
			dfs(x + 1, y, sum + num[s[x][y]]);
		}
		else {
			for(int i = 0; i < 10; i++) if(!used[i])
			{
				if(y == len[x] - 1 && len[x] > 1 && i == 0) continue;
				used[i] = 1;
				num[s[x][y]] = i;
				dfs(x + 1, y, sum + num[s[x][y]]);
				used[i] = 0;
				num[s[x][y]] = -1;
			}
		}
	}
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		memset(s, 0, sizeof(s)); maxp = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			if(len[i] > maxp) maxp = len[i];
			for(int j = 0, k = len[i] - 1; j < k; j++, k--)
				std::swap(s[i][j], s[i][k]);
		}
		res = 0;
		memset(num, -1, sizeof(num));
		memset(used, 0, sizeof(used));
		dfs(0, 0, 0);
		printf("%lld\n", res);
	}
	return 0;
}
