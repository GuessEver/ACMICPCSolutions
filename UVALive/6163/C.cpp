#include <cstdio>
#include <cstring>

int n;
int a[10];
char op[10];
bool answer;
bool hash[10];
char tmp[10]; 

int calc(int x, int y, char op)
{
	if(op == '$') return x * 10 + y;
	if(op == '+') return x + y;
	if(op == '-') return x - y;
	if(op == '*') return x * y;
	if(op == '/')
	{
		if(!y) return -999999;
		return x / y;
	}
}

int three(int a, int b, int c, char o1, char o2)
{
	if(o1 == '$') return calc(calc(a, b, o1), c, o2);
	if(o2 == '$') return calc(a, calc(b, c, o2), o1);
	if(o1 == '*' || o1 == '/') return calc(calc(a, b, o1), c, o2);
	else return calc(a, calc(b, c, o2), o1);
}

bool braket0()
{
	bool flag = 0;
	if(op[1] == '$')
	{
		int ans = three(calc(a[1], a[2], op[1]), a[3], a[4], op[2], op[3]);
		if(ans == 10) flag = 1;
	}
	else if(op[2] == '$')
	{
		int ans = three(a[1], calc(a[2], a[3], op[2]), a[4], op[1], op[3]);
		if(ans == 10) flag = 1;
	}
	else if(op[3] == '$')
	{
		int ans = three(a[1], a[2], calc(a[3], a[4], op[3]), op[1], op[2]);
		if(ans == 10) flag = 1;
	}
	else if(op[1] == '*' || op[1] == '/')
	{
		int ans = three(calc(a[1], a[2], op[1]), a[3], a[4], op[2], op[3]);
		if(ans == 10) flag = 1;
	}
	else if(op[2] == '*' || op[2] == '/')
	{
		int ans = three(a[1], calc(a[2], a[3], op[2]), a[4], op[1], op[3]);
		if(ans == 10) flag = 1;
	}
	else if(op[3] == '*' || op[2] == '/')
	{
		int ans = three(a[1], a[2], calc(a[3], a[4], op[3]), op[1], op[2]);
		if(ans == 10) flag = 1;
	}
	return flag;
}

bool braket1()
{
	bool flag = 0;
	// (X . X) . X . X
	if(op[2] != '$')
	{
		int ans = three(calc(a[1], a[2], op[1]), a[3], a[4], op[2], op[3]);
		if(ans == 10) flag = 1;
	}
	//if(flag) printf(" ---------======>     1\n");
	// X . (X . X) . X
	if(op[1] != '$' && op[3] != '$')
	{
		int ans = three(a[1], calc(a[2], a[3], op[2]), a[4], op[1], op[3]);
		if(ans == 10) flag = 1;
	}
	//if(flag) printf(" ---------======>     2\n");
	// X . X . (X . X)
	if(op[2] != '$')
	{
		int ans = three(a[1], a[2], calc(a[3], a[4], op[3]), op[1], op[2]);
		if(ans == 10) flag = 1;
	}
	//if(flag) printf(" ---------======>     3\n");
	return flag;
}

bool braket2()
{
	bool flag = 0;
	int t1, t2, t3;
	// ((X . X) . X) . X
	if(op[2] != '$' && op[3] != '$')
	{
		t1 = calc(a[1], a[2], op[1]);
		t2 = calc(t1, a[3], op[2]);
		t3 = calc(t2, a[4], op[3]);
		if(t3 == 10) flag = 1;
	}
	//if(flag){
	//	printf("%d %d %d\n", t1, t2, t3);
	//	printf("xxxx ---------======>     1\n");
	//}
	// (X . (X . X)) . X
	if(op[1] != '$' && op[3] != '$')
	{
		t1 = calc(a[2], a[3], op[2]);
		t2 = calc(a[1], t1, op[1]);
		t3 = calc(t2, a[4], op[3]);
		if(t3 == 10) flag = 1;
	}
	//if(flag) printf("xxxx ---------======>     2\n");
	// X . ((X . X) . X)
	if(op[1] != '$' && op[3] != '$')
	{
		t1 = calc(a[2], a[3], op[2]);
		t2 = calc(t1, a[4], op[3]);
		t3 = calc(a[1], t2, op[1]);
		if(t3 == 10) flag = 1;
	}
	//if(flag) printf("xxxx ---------======>     3\n");
	// X . (X . (X . X))
	if(op[1] != '$' && op[2] != '$')
	{
		t1 = calc(a[3], a[4], op[3]);
		t2 = calc(a[2], t1, op[2]);
		t3 = calc(a[1], t2, op[1]);
		if(t3 == 10) flag = 1;
	}
	//if(flag) printf("xxxx ---------======>     4\n");
	// (X . X) . (X . X)
	if(op[2] != '$')
	{
		t1 = calc(a[1], a[2], op[1]);
		t2 = calc(a[3], a[4], op[3]);
		t3 = calc(t1, t2, op[2]);
		if(t3 == 10) flag = 1;
	}
	//if(flag) printf("xxxx ---------======>     5\n");
	return flag;
}

void dfs(int x)
{
	if(answer) return;
	if(x > 3)
	{
		if(braket0()) answer = 1;
		//	if(answer) printf("----->0\n");
		if(braket1()) answer = 1;
		//	if(answer) printf("----->1\n");
		if(braket2()) answer = 1;
		//	if(answer) printf("----->2\n");
		//if(answer) printf("%d%c%d%c%d%c%d\n", a[1], op[1], a[2], op[2], a[3], op[3], a[4]);
		return;
	}
	op[x] = '+';
	dfs(x+1);
	op[x] = '-';
	dfs(x+1);
	op[x] = '*';
	dfs(x+1);
	op[x] = '/';
	dfs(x+1);
	//op[x] = '$';
	//dfs(x+1);
}

void all(int x)
{
	if(x > 4)
	{
		dfs(1);
		return;
	}
	for(int i = 0; i < 4; i++)
		if(!hash[i])
		{
			hash[i] = 1;
			a[x] = tmp[i] - '0';
			all(x+1);
			hash[i] = 0;
		}
}

bool check()
{
	answer = 0;
	memset(hash, 0, sizeof(hash));
	all(1);
	return answer;
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		bool flag = 1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", tmp);
			if(!flag) continue;
			if(!check())
			{
				flag = 0;
			}
		}
		if(flag) printf("TRUE\n");
		else printf("BUSTED\n");
	}
	return 0;
}
