#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
template<class T>
inline T IN(T &num)
{
    num = 0;
    char c = getchar(), f = 0;
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-') f = 1, c = getchar();
    while('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
    if(f) num = -num;
    return num;
}
template<class T>
inline void U(T num) {if(num < 0)putchar('-'), num = -num; if(num > 9)U(num / 10); putchar(num % 10 + '0');}
//------------------------   code   ---------------------------------//
const int NUM = 200010;
int fail[NUM], nxt[NUM][26], cnt[NUM], num;
int newnode()
{
    for(int i = 0; i < 26; i++)
        nxt[num][i] = -1;
    cnt[num] = 0;
    return num++;
}
void init()
{
    num = 0;
    newnode();
}
void insert(char *s)
{
    int i = 0, p = 0;
    while(s[i])
    {
        if(nxt[p][s[i] - 'a'] == -1)nxt[p][s[i] - 'a'] = newnode();
        p = nxt[p][s[i++] - 'a'];
    }
    cnt[p]++;
}
void build()
{
    int p = 0, i;
    fail[0] = 0;
    queue<int> que;
    for(i = 0; i < 26; i++)
        if(nxt[0][i] == -1)
            nxt[0][i] = 0;
        else
        {
            fail[nxt[0][i]] = 0;
            que.push(nxt[0][i]);
        }
    while(!que.empty())
    {
        p = que.front();
        que.pop();
        for(i = 0; i < 26; i++)
            if(nxt[p][i] == -1)
                nxt[p][i] = nxt[fail[p]][i];
            else
            {
                fail[nxt[p][i]] = nxt[fail[p]][i];
                que.push(nxt[p][i]);
            }
    }
}
LL query(char *s)
{
    LL res = 0;
    int i = 0, p = 0, q;
    while(s[i])
    {
        p = nxt[p][s[i++] - 'a'];
        q = p;
        while(q)
        {
            res += cnt[q];
            q = fail[q];
        }
    }
    return res;
}
char s[NUM], ts[NUM];
int n, m, pos[NUM];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    int T;
    IN(T);
    while(T--)
    {
        IN(n), IN(m);
        init();
        pos[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", s + pos[i - 1]);
            pos[i] = strlen(s + pos[i - 1]) + pos[i - 1] + 1;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%s", ts);
            insert(ts);
        }
        build();
        for(int i = 0; i < n; i++)
        {
           U(query(s + pos[i]));
           puts("");
        }
    }
    return 0;
}
