#include <cstdio>
#include <cstring>
#define MAXN 100

using namespace std;

const long long mod = 1000000007;

long long pow_mod(long long a, long long b, long long c) {
    long long ans = 1;
    a = a%c;
    while (b > 0) {
        if (b&1) {
            ans = (ans*a)%c;
        }
        b = (b >> 1);
        a = (a*a)%c;
    }
    return ans;
}

long long fac[MAXN+5];
bool used[MAXN+5];

long long factor(int n) {
    if (n < 1) {
        return 1;
    }
    if (fac[n]) {
        return fac[n];
    } else {
        return fac[n] = (n*factor(n-1))%mod;
    }
}

int ans(int n, int k) {
    return (int)((pow_mod(factor(n), k-1, mod))%mod);
}

int f[MAXN+3][MAXN+3];
int now[MAXN+5];

bool legal(int n, int m, int k) {
    if (k == 0) {
        for (int i = 1; i <= n; i++) {
            now[i] = i;
        }
        for (int j = m; j >= 1; j--) {
            for (int i = 1; i <= n; i++) {
                now[i] = f[j][now[i]];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i != now[i]) {
                return false;
            }
        }
        return true;
    } else {
        for (int j = 1; j <= m; j++) {
            if (f[j][1] == -1) continue;
            memset(used, false, sizeof(used));
            for (int i = 1; i <= n; i++) {
                if (!used[f[j][i]]) {
                    used[f[j][i]] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}

int main() {
    int n, m;
    int tmp;
    while (scanf("%d%d", &n, &m) == 2) {
        int k = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &f[i][1]);
            if (f[i][1] == -1) {
                k++;
                continue;
            }
            for (int j = 2; j <= n; j++) {
                scanf("%d", &f[i][j]);
            }
        }
        if (!legal(n, m, k)) {
            printf("0\n");
        } else {
            printf("%d\n", ans(n, k));
        }
    }
}
