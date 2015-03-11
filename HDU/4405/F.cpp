// By UESTC_QuantalIris
#include <cstdio>
#include <cstring>
#define MAXN 100000
using namespace std;
double dp[MAXN+5];
int to[MAXN+5];
int main() {
	int n, m, a, b; double tmp;
	while (scanf("%d%d", &n, &m) == 2) {
		if (n == 0 && m == 0) {
			break;
		}
		memset(to, 0, sizeof(to));
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			to[a] = b;
		}
		dp[n] = 0;
		for (int i = n-1; i >= 0; i--) {
			if (to[i] != 0) {
				dp[i] = dp[to[i]];
			} else {
				tmp = 0;
				for (int j = 1; j <= 6 && n-j >= i; j++) {
					tmp += dp[i+j]/6.0;
				}
				dp[i] = tmp+1.0;
			}
		}
		printf("%.4f\n", dp[0]);
	}
	return 0;
}

