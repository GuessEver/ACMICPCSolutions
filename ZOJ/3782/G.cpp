#include <cstdio>

bool first(char x, char y)
{
	if(x == '*' || x == '/' || x == '%') return 1;
	if(y == '+' || y == '-') return 1;
	return 0;
}

int calc(int a, char op, int b)
{
	if(op == '+') return a + b;
	if(op == '-') return a - b;
	if(op == '*') return a * b;
	if(op == '/') return a / b;
	if(op == '%') return a % b;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n1, n2, n3;
		char op1[10], op2[10];
		scanf("%d%s%d%s%d", &n1, op1, &n2, op2, &n3);
		int ans;
		if(first(op1[0], op2[0]))
		{
			ans = calc(n1, op1[0], n2);
			ans = calc(ans, op2[0], n3);
		}
		else
		{
			ans = calc(n2, op2[0], n3);
			ans = calc(n1, op1[0], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
