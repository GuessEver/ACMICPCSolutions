#include <cstdio>
#include <cstdlib>
#include <cstring>

// Pick Theorem : S = a + b/2 - 1
// S is the Area, a is the number of points inside while b is on the line

const int dx[] = {1, 1, 0, -1, -1, -1,  0,  1};
const int dy[] = {0, 1, 1,  1,  0, -1, -1, -1};

char s[1000000+10];
int x, y;
long long S;
int len;
// S = a + b/2 - 1   --->   a+b = S + b/2 - 1
int main()
{
	while(scanf("%s", s) == 1)
	{
		S = 0;
		len = strlen(s);
		x = dx[s[0]-'0'];
		y = dy[s[0]-'0'];
		for(int i = 1; i < len; i++)
		{
			int nx = x + dx[s[i]-'0'];
			int ny = y + dy[s[i]-'0'];
			//printf("%d %d\n", nx, ny);
			S += 1ll * x * ny - 1ll * y * nx;
			x = nx; y = ny;
		}
		//printf("%lld\n", S/2 + len/2 + 1);
		printf("%lld\n", (llabs(S) + len) / 2 + 1);
	}
	return 0;
}
