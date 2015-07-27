#include <cstdio>
using namespace std;
const int MAXN = 1000;
int pos[MAXN+5], ans[MAXN+5];

bool valid(int n, int &diff) {
    if (n == 1) {
        return true;
    }
    int rpos;
    for (int i = 2; i <= n-2; i++) {
        bool can = true;
        for (int j = 1; j < n; j++) {
            rpos = i*j%n;
            if (rpos == 0 || rpos == j || rpos == n-j) {
                can = false;
                break;
            }
        }
        if (can) {
            diff = i;
            return true;
        }
    }
    return false;
}

int main() {
    int n, diff;
    freopen("avangard.in", "r", stdin);
    freopen("avangard.out", "w", stdout);
    scanf("%d", &n);
    if (valid(n, diff)) {
        if (n == 1) {
            printf("Yes\n1\n");
        } else {
            printf("Yes\n");
            for (int i = 1; i <= n; i++) {
                pos[i] = i;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    ans[pos[j]] = j;
                }
                for (int j = 1; j <= n; j++) {
                    printf("%d", ans[j]);
                    if (j == n) {
                        printf("\n");
                    } else {
                        printf(" ");
                    }
                    if (pos[j]+diff > n) {
                        pos[j] = pos[j]+diff-n;
                    } else {
                        pos[j] = pos[j]+diff;
                    }
                }
            }
        }
    } else {
        printf("No\n");
    }
    return 0;
}
    
