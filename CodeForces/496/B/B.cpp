#include <cstdio>
#include <cstring>

int n, a[2000];
int b[2000][2000];
int ans[20][2000];

bool check(int k, int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(b[k][j] == b[i][j]) continue;
		else if(b[k][j] > b[i][j]) return 1;
		else if(b[k][j] < b[i][j]) return 0;
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	int tmp = -1;
	for(int i = 1; i <= n; i++)scanf("%1d", &a[i]);
	for(int add = 1; add <= 10; add++)
	{
		for(int i = 1; i <= n; i++) a[i] = (a[i] + 1) % 10;
		memset(b, 0, sizeof(b));
		for(int i = 1; i <= n; i++)
		{
			int cnt = i;
			for(int j = 1; j <= n; j++)
			{
				b[i][cnt] = a[j];
				cnt++;
				if(cnt == n + 1) cnt = 1;
			}
		}
		int k = 1;
		for(int i = 1; i <= n; i++)
		{
			if(check(k, i)) k = i;
			//for(int j = 1; j <= n; j++) printf("%d", b[i][j]);
			//puts("");
		}
		for(int i = 1; i <= n; i++) ans[add][i] = b[k][i];
	}
	for(int i = 1; i <= 10; i++) 
		for(int j = 1; j <= n; j++) b[i][j] = ans[i][j];
	int k = 1;
	for(int i = 1; i <= 10; i++) if(check(k, i)) k = i;
	for(int i = 1; i <= n; i++) printf("%d", b[k][i]);
	puts("");
	return 0;
}
