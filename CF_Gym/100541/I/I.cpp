#include <cstdio>
#include <algorithm>
#define MAXN 1000
using namespace std;
const int dx[] = {1, -1, -1, 1};
const int dy[] = {1, 1, -1, -1};
const int dxx[] = {0, -1, 0, 1};
const int dyy[] = {1, 0, -1, 0};
/*const int next[][2] = {
	{3, 1},
	{0, 2},
	{1, 3},
	{2, 0}
};*/
int mem[MAXN+3][MAXN+3][4][2];
bool can[MAXN+3][MAXN+3];
int ans[MAXN+3][MAXN+3];
int m, n;
bool can_vis(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m && can[x][y];
}

int dfs(int x, int y, int d, bool xp) {
	if (!can_vis(x, y)) {
		return 0;
	}
	if (mem[x][y][d][xp]) {
		return mem[x][y][d][xp];
	}
	int new_x = x, new_y = y;
	if (xp) {
		new_x = x+dx[d];
	} else {
		new_y = y+dy[d];
	}
	return mem[x][y][d][xp] = 1+dfs(new_x, new_y, d, !xp);
}

char str[MAXN+5];
int main() {
	int i, j, k, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			scanf("%s", str+1);
			for (j = 1; j <= m; j++) {
				if (str[j] == '1') {
					can[i][j] = true;
				} else {
					can[i][j] = false;
				}
				for (k = 0; k < 4; k++) {
					mem[i][j][k][true] = 0;
					mem[i][j][k][false] = 0;
				}
			}
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				ans[i][j] = 0;
				if (!can_vis(i, j)) {
					continue;
				}
				for (k = 0; k < 4; k++) {
					ans[i][j] += dfs(i+dxx[k], j+dyy[k], k, !(k%2));
				}
			}
		}
		int ans_final = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				ans_final = max(ans_final, ans[i][j]+can_vis(i, j));
			}
		}
		printf("%d\n", ans_final);
	}
}
