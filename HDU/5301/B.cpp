#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m, x, y;
    int ans1, ans2, ans;
    while (scanf("%d%d%d%d", &n, &m, &x, &y) == 4) {
        ans1 = max(min(min(m-y+1, y), max(x-1, n-x)), n/2+n%2);
        ans2 = max(min(min(n-x+1, x), max(y-1, m-y)), m/2+m%2);
        ans = min(ans1, ans2);
        ans = min(ans, max(x-1, max(y-1, max(n-x, m-y))));
        printf("%d\n", ans);
    }
    return 0;
}
