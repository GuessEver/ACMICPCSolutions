#include <cstdio>
#include <algorithm>

const int N = 2 * 1000000 + 10;

char t[N], s[2*N];
int n, p[2*N];

void pre(char *origin, char *str, int &_len)
{
	_len = 0;
	str[_len++] = '$';
	for(int i = 0; origin[i]; i++)
	{
		str[_len++] = '#';
		str[_len++] = origin[i];
	}
	str[_len++] = '#';
	str[_len] = 0;
	//puts(str);
}

void getPi(char *str, int _len, int *_P)
{
	int mx = 0, id;
	for(int i = 1; i < _len; i++)
	{
		if(mx > i) _P[i] = std::min(_P[2*id-i], mx-i);
		else _P[i] = 1;
		for(; str[i+_P[i]] == str[i-_P[i]]; _P[i]++) ;
		if(_P[i] + i > mx)
		{
			mx = _P[i] + i;
			id = i;
		}
	}
}

int calc(int l, int r)
{
	if(r == l) return 0;
	int cycle = p[(r+1)/2] - 1, res = 0, newr;
	if((r - 1) % 4 == 0) newr = (r + 1) / 2;
	else newr = r / 2;
	if(cycle == r / 2) res += calc(l, newr) + 1;
	else res = 0;
	return res;
}

int main()
{
	scanf("%s", t);
	pre(t, s, n);
	getPi(s, n, p);
	//for(int i = 1; i < n; i++) printf("%c ", s[i]); puts("");
	//for(int i = 1; i < n; i++) printf("%d ", p[i] - 1); puts("");
	int res = 0;
	for(int i = 1; i < n; i++)
	{
		//printf("%d ", calc(1, i));
		res += calc(1, i);
	}
	printf("%d\n", res);
	return 0;
}
