// By UESTC_QuantalIris
#include <cstdio>
#include <cstring>
#define MAXN 15
using namespace std;
char in[MAXN+5];
const char end[] = "END";
int combine[MAXN+3][MAXN+3];
int ans_num;
void dfs_r(int l, int r, int pos, int len) {
	if (pos > len) {
		if (l == r) {
			ans_num++;
		}
		return ;
	}
	for (int i = pos; i <= len; i++) {
		dfs_r(l, r+combine[pos][i], i+1, len);
	}
}
void dfs_l(int l, int pos, int eq_pos, int len) {
	if (pos > eq_pos) {
		dfs_r(l, 0, eq_pos+1, len);
	}
	for (int i = pos; i <= eq_pos; i++) {
		dfs_l(l+combine[pos][i], i+1, eq_pos, len);
	}
}
int main() {
	while (scanf("%s", in+1) == 1) {
		if (strcmp(in+1, end) == 0) {
			break;
		}
		int len = strlen(in+1); ans_num = 0;
		memset(combine, 0, sizeof(combine));
		for (int i = 1; i <= len; i++) {
			for (int j = i; j <= len; j++) {
				for (int k = i; k <= j; k++) {
					combine[i][j] = combine[i][j]*10+in[k]-'0';
				}
			}
		}
		for (int i = 1; i <= len-1; i++) {
			dfs_l(0, 1, i, len);
		}
		printf("%d\n", ans_num);
	}
}

