#include <cstdio>
#include <cstring>
#include <string>
using std::string;

char s[2010], t[2010];
int a[2010], n;

void COPY()
{
	int len = 0;
	memset(t, 0, sizeof(t));
	for(int i = 0; i < n; i++)
		if(!a[i]) t[len++] = s[i];
	n = len;
	strcpy(s, t);
}

bool check(int L, int R)
{
	if((L == 0 || s[L-1] == '+') && (R == n-1 || s[R+1] == '+')) return 1;
	if((L == 0 || s[L-1] == '(') && (R == n-1 || s[R+1] == '+')) return 1;
	if((L == 0 || s[L-1] == '+') && (R == n-1 || s[R+1] == ')')) return 1;
	return 0;
}

bool solve()
{
	memset(a, 0, sizeof(a));
	n = strlen(s);
	for(int i = 0; i < n; i++)
		if(!a[i] && s[i] == '(')
		{
			int cnt = 0, L = i, R;
			bool allMultiply = 1;
			for(int j = i; j < n; j++)
			{
				if(s[j] == '(') cnt++;
				else if(s[j] == ')') cnt--;
				if(cnt == 1 && s[j] == '+') allMultiply = 0;
				if(!cnt) { R = j; break; }
			}
			// [L, R]      L -> ( ... ) <- R
			//printf("[%d , %d]\n", L, R);
			if(allMultiply || check(L, R))
			{
				a[L] = a[R] = 1;
				COPY();
				return 1;
			}
		}
	return 0;
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		while(solve());
		puts(s);
	}
	return 0;
}
