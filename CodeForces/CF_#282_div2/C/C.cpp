#include <cstdio>
#include <cstring>
#include <stack>
using std::stack;

int len;
char s[100000+10];
stack<char> st, all;
int Ans[100000+10], L;

bool solve()
{
	int len = strlen(s);
	for(int i = 0; i < len; i++)
	{
		bool flag = 0;
		if(s[i] == '#') 
		{
			s[i] = ')';
			Ans[L++] = 1; 
			flag = 1;
		}
		if(s[i] == '(') st.push('(');
		if(s[i] == ')')
		{
			if(st.empty() && all.empty()) return 0;
			if(!st.empty()) st.pop();
			else all.pop();
		}
		if(flag)
		{
			while(!st.empty())
			{
				all.push(st.top());
				st.pop();
			}
		}
	}
	if(!st.empty()) return 0;
	while(!all.empty())
	{
		Ans[L-1]++;
		all.pop();
	}
	return 1;
}

int main()
{
	scanf("%s", s);
	if(!solve()) puts("-1");
	else for(int i = 0; i < L; i++) printf("%d\n", Ans[i]);
	return 0;
}
