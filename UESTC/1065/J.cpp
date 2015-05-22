#include <cstdio>
#include <cstring>

const int N = 3 * 1000000 + 10;

char s[N];
int fail[N], n;

void getFail()
{
	memset(fail, 0, sizeof(fail)); fail[0] = -1;
	for(int j = 0, k = -1; j < n; )
	{
		if(k == -1 || s[j] == s[k]) fail[++j] = ++k;
		else k = fail[k];
	}
}

int main()
{
	scanf("%s", s); n = strlen(s);
	getFail();
	//for(int i = 0; i < n; i++) printf("%3c ", s[i]); puts("");
	//for(int i = 1; i <= n; i++) printf("%3d ", fail[i]); puts("");
	int cycle = -1;
	for(int i = 1; i <= n; i++)
	{
		int mid = 2 * fail[i] - i, res = i;
		if((i - mid) % 2) continue;
		cycle = (i - mid) / 2;
		if(i % cycle == 0 && mid % cycle == 0) res = cycle;
		printf("%d%s", res, i == n ? "\n" : " ");
	}
	for(int i = 0; i < cycle; i++) putchar(s[i]); puts("");
	return 0;
}
