#include <cstdio>
#include <cctype>
#include <cstring>
#include <stack>
using std::stack;

char s[2010], t[2010];
int n;
int a[2010];
stack<int> st;
int match[2010];
int pos[2010], L;

bool isAdd(int x)
{
	if(x < 0 || x >= n) return 1;
	return s[x] == '+';
}

bool check(int l, int r)
{
	bool allMultiply = 1;
	for(int i = l; i <= r; i++)
		if(s[i] == '+') { allMultiply = 0; break; }
	if(allMultiply) return 1;
	if(isAdd(l-1) && isAdd(r+1)) return 1;
	return 0;
}
bool check2(int l, int r)
{
	if(r+1 < n && (s[r+1] == '(' || isalpha(s[r+1]))) return 0;
	if(l-1 >=0 && (s[l-1] == ')' || isalpha(s[l-1]))) return 0;
	return 1;
}

bool solve()
{
	memset(a, 0, sizeof(a));
	memset(match, 0, sizeof(match));
	memset(pos, 0, sizeof(pos));
	while(!st.empty()) st.pop();
	L = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] != '(' && s[i] != ')') continue;
		if(s[i] == '(')
		{
			st.push(i);
			pos[++L] = i;
		}
		else{
			int u = st.top(); st.pop();
			match[u] = i;
			match[i] = u;
		}
	}
	bool goon = 0;
	for(int i = L; i >= 1; i--)
	{
		bool flag = check(pos[i], match[pos[i]]);
		a[pos[i]] = flag;
		a[match[pos[i]]] = flag;
		goon |= flag;
	}
	for(int i = L; i >= 1; i--)
	{
		if(a[pos[i]]) continue;
		bool flag = check2(pos[i], match[pos[i]]);
		a[pos[i]] = flag;
		a[match[pos[i]]] = flag;
		goon |= flag;
	}
	return goon;
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		n = strlen(s);
		while(solve())
		{
			int len = 0;
			memset(t, 0, sizeof(t));
			for(int i = 0; i < n; i++)
				if(!a[i]) t[len++] = s[i];
			memset(s, 0, sizeof(s));
			strcpy(s, t);
			n = strlen(s);
		}
		puts(s);
		memset(s, 0, sizeof(s));
	}
	return 0;
}
