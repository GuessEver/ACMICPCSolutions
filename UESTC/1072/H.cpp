#include <cstdio>
#include <cstring>

int calc[19683+10]; // -1: not calculated; 0: tie; 1: win; 2: lose
bool ans[19683+10];

int getHash(int x, int y, int val, int a[][3])
{
	int res = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			if(i == x && j == y) res = res * 3 + val;
			else res = res * 3 + a[i][j];
		}
	return res;
}

int check(int S, int &win1, int &win2)
{
	int status = S;
	int a[3][3];
	for(int i = 2; i >= 0; i--)
		for(int j = 2; j >= 0; j--)
		{
			a[i][j] = status % 3;
			status /= 3;
		}
	// row
	for(int i = 0; i < 3; i++)
		if(a[i][0] != 0 && a[i][0] == a[i][1] && a[i][1] == a[i][2])
			if(a[i][0] == 1) win1++; else win2++;
	// column
	for(int j = 0; j < 3; j++)
		if(a[0][j] != 0 && a[0][j] == a[1][j] && a[1][j] == a[2][j])
			if(a[0][j] == 1) win1++; else win2++;
	// diag
	if(a[0][0] != 0 && a[0][0] == a[1][1] && a[1][1] == a[2][2])
		if(a[0][0] == 1) win1++; else win2++;
	if(a[0][2] != 0 && a[0][2] == a[1][1] && a[1][1] == a[2][0])
		if(a[0][2] == 1) win1++; else win2++;
	if(win1 > 0) return 1;
	if(win2 > 0) return 2;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(a[i][j] == 0) return -1;
	return 0;
}

int dfs(int S, bool one)
{
	int status = S;
	int a[3][3];
	for(int i = 2; i >= 0; i--)
		for(int j = 2; j >= 0; j--)
		{
			a[i][j] = status % 3;
			status /= 3;
		}
	int w1 = 0, w2 = 0, cc = check(S, w1, w2);
	if(cc != -1) return calc[S] = (cc == 0 ? 0 : 1);
	int cnt = 0, win = 0, tie = 0, lose = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) if(a[i][j] == 0)
		{
			int val = one ? 1 : 2;
			int tmp = dfs(getHash(i, j, val, a), !one);
			cnt++;
			win += (tmp == 1);
			lose += (tmp == 2);
			tie += (tmp == 0);
		}
	if(win > 0) return calc[S] = 2;
	if(tie > 0) return calc[S] = 0;
	if(lose == cnt) return calc[S] = 1;
}

void getAns(int S, bool one)
{
	ans[S] = 1;
	int status = S;
	int a[3][3];
	for(int i = 2; i >= 0; i--)
		for(int j = 2; j >= 0; j--)
		{
			a[i][j] = status % 3;
			status /= 3;
		}
	int val = one ? 1 : 2;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) if(a[i][j] == 0)
		{
			int hash = getHash(i, j, val, a);
			if(calc[hash] == 0) getAns(hash, !one);
		}
}

int main()
{
	memset(calc, -1, sizeof(calc));
	dfs(0, 1);
	getAns(0, 1);
	int T; scanf("%d", &T);
	while(T--)
	{
		int S = 0;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				char tmp; scanf(" %c", &tmp);
				if(tmp == '.') S = S * 3 + 0;
				else if(tmp == 'O') S = S * 3 + 1;
				else if(tmp == 'X') S = S * 3 + 2;
			}
		if(calc[S] == -1) puts("INVALID");
		else if(ans[S]) puts("REACHABLE");
		else puts("UNREACHABLE");
		//printf("Status = %d\n", calc[S]);
	}
	return 0;
}
