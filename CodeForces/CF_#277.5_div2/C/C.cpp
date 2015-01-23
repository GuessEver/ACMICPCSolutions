#include <cstdio>
#include <cstring>

int m, s;
int a[200], b[200];

bool solve(int sum)
{
	memset(a, 0, sizeof(a));
	for(int i = m; i >= 1; i--)
	{
		if(sum < 9)
		{
			a[i] = sum;
			sum = 0;
			break;
		}
		else{
			a[i] = 9;
			sum -= 9;
		}
	}
	for(int i = 1; i <= m; i++) b[i] = a[i];
	if(a[1] == 0)
	{
		bool flag = 0;
		a[1] = 1;
		for(int i = 2; i <= m; i++) if(a[i]) { a[i]--; flag = 1; break; }
		if(!flag) return 0;
	}
	for(int i = 1; i <= m; i++) printf("%d", a[i]);
	putchar(' ');
	//Largest
	for(int i = m; i >= 1; i--) printf("%d", b[i]);
	puts("");
	return 1;
}

int main()
{
	scanf("%d%d", &m, &s);
	if(m == 1)
	{
		if(s < 10) printf("%d %d\n", s, s);
		else puts("-1 -1");
	}
	/*else if(m == 2)
	{
		if(s > 0 && s < 10) printf("1%d %d0\n", s-1, s);
		else if(s 
		else puts("-1 -1");
	}*/
	else if(s == 0 || !solve(s)) puts("-1 -1");
	return 0;
}
