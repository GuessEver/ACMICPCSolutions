#include <cstdio>

using namespace std;


long long g[100000000];
long long pos[100000000+10];
int cnt = 0;

long long golomb(int n) {
    if (g[n]) return g[n];
    cnt++;
    if (n == 1) {
        return g[n] = 1;
    } else {
        return g[n] = 1+golomb(n-golomb(golomb(n-1)));
    }
}

int main() {
    int n;
    for (int i = 1; i <= 100000000; i++) {
        pos[golomb(i)] = i;
    }
    while (true) {
    scanf("%d", &n);
        printf("%lld\n", pos[pos[n]]);
    }
}
