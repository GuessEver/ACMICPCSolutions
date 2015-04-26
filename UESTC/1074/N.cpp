#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
using std::stack;

const int N = 1000000 + 10;

char s[N];
stack<char> op;
stack<long long> num;
int pri[300];

long long calc(long long x, char o, long long y)
{
	if(o == '+') return x + y;
	if(o == '-') return x - y;
	if(o == '*') return x * y;
	if(o == '/') return x / y;
}

void solve()
{
	while(!op.empty()) op.pop();
	while(!num.empty()) num.pop();
	s[0] = '0'; // -12  =>  0-12
	s[strlen(s)] = '$';
	op.push('#');
	long long tmp = 0;
	for(int i = 0; s[i]; i++)
	{
		if(isdigit(s[i])) tmp = tmp * 10 + s[i] - '0';
		else{ // operator
			num.push(tmp);
			tmp = 0;
			while(pri[s[i]] <= pri[op.top()])
			{
				long long y = num.top(); num.pop();
				long long x = num.top(); num.pop();
				char o = op.top(); op.pop();
				num.push(calc(x, o, y));
			}
			op.push(s[i]);
		}
	}
	printf("%lld\n", num.top());
}

int main()
{
	pri['#'] = 0;
	pri['+'] = pri['-'] = 2;
	pri['*'] = pri['/'] = 3;
	pri['$'] = 1;
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(s, 0, sizeof(s));
		scanf("%s", s+1);
		solve();
	}
	return 0;
}
