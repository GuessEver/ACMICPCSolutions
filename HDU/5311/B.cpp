#include <cstdio>
#include <cstring>

char s[200], t[] = "anniversary";
int n, m;

bool find(int &l, int r, int tl, int tr)
{
	for(int st = l; st <= r; st++)
	{
		bool flag = 1;
		for(int i = st, j = tl; j <= tr; j++, i++)
			if(s[i] != t[j])
			{
				flag = 0;
				break;
			}
		if(flag)
		{
			l = st + (tr - tl + 1);
			return 1;
		}
	}
	return 0;
}

bool solve()
{
	// t [0, i] U [i+1, j] U [j+1, m-1]
	for(int i = 0; i < m; i++)
		for(int j = i + 1; j < m; j++)
		{
			int pos = 0;
			if(!find(pos, n - 1, 0, i)) continue;
			//printf("%d\n", pos);
			if(!find(pos, n - 1, i + 1, j)) continue;
			//printf("%d\n", pos);
			if(!find(pos, n - 1, j + 1, m - 1)) continue;
			//printf("%d\n", pos);
			return 1;
		}
	return 0;
}

int main()
{
	m = strlen(t);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		n = strlen(s);
		if(solve()) puts("YES"); else puts("NO");
	}
	return 0;
}
