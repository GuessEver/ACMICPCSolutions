#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#define MAXN 200
using namespace std;

char s[MAXN+5];
string ans[MAXN+5];
int cnt;

char *find(char *s) {
    char *com = strchr(s, ',');
    if (com) {
        return com;
    }
    return strchr(s, ';');
}

int main() {
	freopen("isharp.in", "r", stdin);
	freopen("isharp.out", "w", stdout);
    fgets(s, MAXN, stdin);
    char *st = strchr(s, ' ');
    string head(s, st);
    st++;
    char *i, *com;
    while ((com = find(st)) != NULL) {
        for (i = com-1; !isalpha(*i); i--) {
            if ((*i) == ']') {
                ans[cnt] += (*(i-1));
                ans[cnt] += (*(i));
                i--;
            } else {
                ans[cnt] += (*i);
            }
        }
        if (isalpha(*i)) {
            i++;
        }
        ans[cnt] += " "+string(st, i);
        st = com+2;
        cnt++;
    }
    for (int j = 0; j < cnt; j++) {
        cout << head << ans[j] << ';' << endl;
    }
    return 0;
}
