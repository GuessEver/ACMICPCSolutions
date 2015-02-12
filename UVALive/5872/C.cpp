#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>

char t1[3000], t2[3000], tmp[3000];
int val[3000];
int pri[3000];
long long num[3000];
int topnum, topop;
char op[3000];

long long calc(long long x, char o, long long y)
{
	if(o == '+') return x + y;
	if(o == '-') return x - y;
	if(o == '*') return x * y;
}

long long solve(char *s)
{
	topnum = topop = 0;
	for(int i = 0; s[i]; i++)
	{
		if(s[i] == '(' || s[i] == ')') continue;
		if(s[i] == '-' || s[i] == '+') { num[topnum++] = 0; break; }
		if(isalpha(s[i]) || isdigit(s[i])) break;
	}
	for(int i = 0; s[i]; i++)
	{
		if(s[i] == '(') op[topop++] = '(';
		else if(s[i] == ')')
		{
			while(op[topop-1] != '(')
			{
				long long y = num[--topnum];
				long long x = num[--topnum];
				char f = op[--topop];
				num[topnum++] = calc(x, f, y);
			}
			topop--;
		}
		else if(isalpha(s[i])) // number
		{
			long long x = val[s[i]];
			num[topnum++] = x;
		}
		else if(isdigit(s[i]))
		{
			long long x = 0;
			while(isdigit(s[i])) 
			{
				x = x * 10 + s[i] - '0';
				i++;
			} i--;
			num[topnum++] = x;
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*')
		{
			while(topop && pri[s[i]] <= pri[op[topop-1]])
			{
				int y = num[--topnum];
				int x = num[--topnum];
				char f = op[--topop];
				num[topnum++] = calc(x, f, y);
			}
			op[topop++] = s[i];
		}
	}
	return num[topnum-1];
}

int main()
{
	pri['+'] = 1; pri['-'] = 1;
	pri['*'] = 2;
	srand(time(0));
	int T; scanf("%d", &T);
	fgets(tmp, 2900, stdin);
	while(T--)
	{
		fgets(tmp, 2900, stdin); int len = 0;
		t1[len++] = '(';
		for(int i = 0; tmp[i]; i++)
		{
			if(tmp[i] != ' ' && tmp[i] != '\t') t1[len++] = tmp[i];
			if(tmp[i] == '\n') break;
		}
		t1[len++] = ')'; t1[len] = 0;
		fgets(tmp, 2900, stdin); len = 0;
		t2[len++] = '(';
		for(int i = 0; tmp[i]; i++)
		{
			if(tmp[i] != ' ' && tmp[i] != '\t') t2[len++] = tmp[i];
			if(tmp[i] == '\n') break;
		}
		t2[len++] = ')'; t2[len] = 0;
		bool flag = 1;
		for(int o = 1; o <= 100; o++)
		{
			for(char ch = 'a'; ch <= 'z'; ch++) val[ch] = rand()%50;
			long long res1 = solve(t1), res2 = solve(t2);
	//		printf("%lld %lld\n", res1, res2);
			if(res1 != res2) { flag = 0; break; }
		}
		if(flag) puts("YES"); else puts("NO");
	}
	return 0;
}
