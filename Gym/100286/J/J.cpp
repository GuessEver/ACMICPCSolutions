#include <cstdio>
#include <cctype>
#define MAXN 100000

using namespace std;

char v[] = "AEIOU";
char c[] = "BCDFGHJKLMNPQRSTVWXYZ";
char s[MAXN+5];
char yx[300];
bool mp[30][30];

bool dfs(int num, int s, int v, int &final_s) {
    if (num >= 26) {
        if (v == 5) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if ((1^((s>>i)&1)^((s>>j)&1))&&mp[i][j]) {
                        return false;
                    }
                }
            }
            final_s = s;
            return true;
        }
        return false;
    } else {
        if (v < 5 && dfs(num+1, (s<<1)|1, v+1, final_s)) {
            return true;
        }
        if (dfs(num+1, s<<1, v, final_s)) {
            return true;
        }
        return false;
    }
}

int main() {
freopen("javanese.in", "r", stdin);
freopen("javanese.out", "w", stdout);

    
    int cnt = 0, vcnt = 0, ccnt = 0;
    while ((s[cnt++] = getchar()) != EOF) {}
    cnt--;
    s[cnt] = '\0';
    //printf("%s", s);
    for (int i = 0; i < cnt-1; i++) {
        if (isalpha(s[i]) && isalpha(s[i+1])) {
            mp[s[i]-'A'][s[i+1]-'A'] = true;
        }
    }
    int ans_s = 0;
    if (!dfs(0, 0, 0, ans_s)) {
        printf("impossible\n");
    } else {
        for (int i = 0; i < 26; i++) {
            if (((ans_s>>i)&1)) {
                yx[i+'A'] = v[vcnt++];
            } else {
                yx[i+'A'] = c[ccnt++];
            }
        }
        for (int i = 0; i < cnt-1; i++) {
            if (isalpha(s[i])) {
                putchar(yx[s[i]]);
            } else {
                putchar(s[i]);
            }
        }
    }

}
