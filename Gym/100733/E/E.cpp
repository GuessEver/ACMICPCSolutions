#include <cstdio>
#include <algorithm>
#define MAXN 1000000

using namespace std;

int a[MAXN+5];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    sort(a , a+n);
    printf("%d\n", a[k-1]);
}
