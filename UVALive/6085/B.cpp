#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
using std::map;
using std::string;
using std::stack;

char s[200];
int len;
string all[200];
int Cnt;
map<string, int> number;
struct Node{string s; int x;}nde;
stack<Node> st, ttt;

int main()
{
	while(scanf("%s", s) == 1)
	{
		len = strlen(s);
		Cnt = 0; number.clear();
		while(!st.empty()) st.pop();
		while(!ttt.empty()) ttt.pop();
		for(int i = 0; i < len; i++)
		{
			if(s[i] == '(')
			{
				nde = (Node){"(", 0};
				st.push(nde);
			}
			else if(isalpha(s[i]) && isupper(s[i]))
			{
				string tmps = ""; tmps += s[i];
				while(isalpha(s[i+1]) && islower(s[i+1]))
					tmps += s[++i];
				int num = 1;
				if(isdigit(s[i+1])) num = s[++i] - '0';
				nde = (Node){tmps, num};
				st.push(nde);
			}
			else if(s[i] == ')')
			{
				int num = 1;
				if(isdigit(s[i+1])) num = s[++i] - '0';
				while(st.top().s != "(")
				{
					nde = st.top(); st.pop();
					nde.x *= num;
					ttt.push(nde);
				}
				if(st.top().s == "(") st.pop();
				while(!ttt.empty())
				{
					nde = ttt.top(); ttt.pop();
					st.push(nde);
				}
			}
		}
		while(!st.empty())
		{
			nde = st.top(); st.pop();
			//printf("%s %d\n", nde.s.c_str(), nde.x);
			if(!number[nde.s]) all[Cnt++] = nde.s;
			number[nde.s] += nde.x;
		}
		std::sort(all, all+Cnt);
		for(int i = 0; i < Cnt; i++)
		{
			if(i) printf("+");
			if(number[all[i]] > 1) printf("%d", number[all[i]]);
			printf("%s", all[i].c_str());
		}
		puts("");
	}
	return 0;
}
