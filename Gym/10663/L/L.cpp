#include <cstdio>
#include <iostream>
#define MAXN 100000
using namespace std;

int num[MAXN+5];
int a[MAXN+5];
long long ans;
void handle(int w, int i, int max_num) {
    num[a[i-w]]--;
    num[a[i-w]+1]++;
    num[a[i]]--;
    num[a[i]-1]++;
    if (a[i] == max_num) {
        if (!num[a[i]]) {
            max_num = a[i]-1;
        }
    }
    if (max_num < a[i-w]+1) {
        max_num = a[i-w]+1;
    }
    ans = min(ans, (long long)num[max_num]*max_num);
    num[a[i-w]]++;
    num[a[i-w]+1]--;
    num[a[i]]++;
    num[a[i]-1]--;
}

int main() {
    int n;
    int maxnum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        num[a[i]]++;
        maxnum = max(maxnum, a[i]);
    }
    ans = (long long)(num[maxnum])*maxnum;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            if (i == 1) {
                if (a[i]) {
                    handle(-1, i, maxnum);
                }
                //cout << ans << endl;
            } else {
                if (a[i]) {
                    handle(1, i, maxnum);
                }
                //cout << ans << endl;
            }
        } else {
            if (a[i]) {
                handle(1, i, maxnum);
                handle(-1, i, maxnum);
                //cout << ans << endl;
            }
        }
    }
    cout << ans << endl;
}
