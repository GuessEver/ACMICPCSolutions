#include <cstdio>
#include <algorithm>

const int N = 110000 + 10;

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

int main()
{
	while(scanf("%s", t) == 1)
	{
		pre(t, s, n);
		getPi(s, n, p);
		int res = 1;
		for(int i = 1; i < n; i++)
			res = std::max(res, p[i]-1);
		printf("%d\n", res);
	}
	return 0;
}
