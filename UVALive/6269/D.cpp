#include <cstdio>
#include <cstring>

/*    1
    ---
 2  | |  3
    ---  4
 5  | |  6
    ---  7
   */

int A[20][20];

void predoing()
{
	memset(A, 0, sizeof(A));
	A[1][3] = A[1][6] = 1;
	A[2][1] = A[2][3] = A[2][4] = A[2][5] = A[2][7] = 1;
	A[3][1] = A[3][3] = A[3][4] = A[3][6] = A[3][7] = 1;
	A[4][2] = A[4][4] = A[4][3] = A[4][6] = 1;
	A[5][1] = A[5][2] = A[5][4] = A[5][6] = A[5][7] = 1;
	A[6][1] = A[6][2] = A[6][4] = A[6][5] = A[6][6] = A[6][7] = 1;
	A[7][1] = A[7][3] = A[7][6] = 1;
	A[8][1] = A[8][2] = A[8][3] = A[8][4] = A[8][5] = A[8][6] = A[8][7] = 1;
	A[9][1] = A[9][2] = A[9][3] = A[9][4] = A[9][6] = A[9][7] = 1;
	A[0][1] = A[0][2] = A[0][3] = A[0][5] = A[0][6] = A[0][7] = 1;
}

int n;
int hour[100], minute[100];
int broken[10][20];

bool check(int h, int m, int hh, int mm)
{
	int aa[] = {0, h/10, h%10, m/10, m%10};
	int bb[] = {0, hh/10, hh%10, mm/10, mm%10};
	bool able = 1;
	for(int i = 1; i <= 4; i++)
	{
		int now = aa[i], clock = bb[i];
		for(int j = 1; j <= 7; j++)
			if(A[clock][j] && !A[now][j])
			{
				able = 0;
				break;
			}
	}
	if(!able) return 0;
	for(int i = 1; i <= 4; i++)
	{
		int now = aa[i], clock = bb[i];
		for(int j = 1; j <= 7; j++)
		{
			if(broken[i][j] == 1 && A[clock][j]) return 0;
			if(A[clock][j])
			{
				if(broken[i][j] == 1) return 0;
				broken[i][j] = 0;
			}
			if(A[now][j] && !A[clock][j])
			{
				if(broken[i][j] == 0) return 0;
				broken[i][j] = 1;
			}
		}
	}
	return 1;
}

bool solve(int h, int m)
{
	memset(broken, -1, sizeof(broken));
	for(int i = 1; i <= n; i++)
	{
		if(!check(h, m, hour[i], minute[i])) return 0;
		m++; h = (h + m/60) % 24; m = m % 60;
	}
	return 1;
}

int main()
{
	predoing();
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d:%d", &hour[i], &minute[i]);
		int cnt = 0;
		for(int i = 0; i < 24; i++)
			for(int j = 0; j < 60; j++)
			{
				if(solve(i, j))
				{
					cnt++;
					if(cnt > 1) putchar(' ');
					printf("%02d:%02d", i, j);
				}
			}
		if(!cnt) printf("none");
		puts("");
	}
	return 0;
}
