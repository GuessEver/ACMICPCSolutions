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
const int NUM = 100010;
int s, g, n, t;
int wS[NUM], wG[NUM], cnt;
string w[NUM];
bool bad[NUM];
map<string, int> mp;
int vis[NUM];
char c;
bool readw()
{
    while(!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) c = getchar();
    w[cnt] = "";
    while(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
    {
    	if('A' <= c && c <= 'Z') c += 'a' - 'A';
        w[cnt] += c;
        c = getchar();
    }
    while(!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')))
    {
        if(c == '\n' || c == EOF)
        {
            return false;
        }
        c = getchar();
    }
    return true;
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("spam.in", "r", stdin);
    freopen("spam.out", "w", stdout);
#endif
    IN(s), IN(g), IN(n), IN(t);
    for(int i = 1; i <= s; ++i)
    {
        bool f = true;
        while(f)
        {
            f = readw();
            if(mp.find(w[cnt]) == mp.end())
            {
                mp[w[cnt]] = cnt;
                ++wS[cnt];
                vis[cnt++] = i;
            }
            else
            {
                int no = mp[w[cnt]];
                if(vis[no] != i)
                {
                    vis[no] = i;
                    ++wS[no];
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= g; ++i)
    {
        bool f = true;
        while(f)
        {
            f = readw();
            if(mp.find(w[cnt]) == mp.end())
            {
                mp[w[cnt]] = cnt;
                ++wG[cnt];
                vis[cnt++] = i;
            }
            else
            {
                int no = mp[w[cnt]];
                if(vis[no] != i)
                {
                    vis[no] = i;
                    ++wG[no];
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < cnt; ++i)
    {
//        cout << w[i] << ' '<< wS[i] << ' ' << wG[i] << endl;
        if(wS[i] >= wG[i]) bad[i] = true;
    }
    for(int i = 1; i <= n; ++i)
    {
        int tot = 0, spam = 0;
        bool f = true;
        while(f)
        {
            f = readw();
//            cout << w[cnt] << endl;
            if(mp.find(w[cnt]) == mp.end()) tot++;
            else
            {
                int no = mp[w[cnt]];
                if(vis[no] != i)
                {
                    ++tot;
                    vis[no] = i;
                    if(bad[no]) spam++;
                }
            }
        }
//        cout << spam << ' ' << tot << endl;
        if(100 * spam >= t * tot)
            puts("spam");
        else
            puts("good");
    }
    return 0;
}
