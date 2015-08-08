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
//int maze[66][66];
char s[5][10] = {"SOUTH", "WEST", "NORTH", "EAST", "DONE"};
char r[60];
int dx[4] = {0, -1, 0, 1}, dy[4] = { 1, 0, -1, 0};
int step[66][66];
bool query(int i)
{
    printf("%s\n", s[i]);
    fflush(stdout);
    scanf("%s", r);
    return r[0] == 'E';
}
stack<int> stk;
void back(P now, int op)
{
    int x = now.FI, y = now.SE;
    int t;
    while(x != 33 || y != 33)
    {
        t = step[x][y];
        for(int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(0 < tx && tx < 66 && 0 < ty && ty < 66 && step[tx][ty] == t - 1)
            {
                if(op) query(i);
                else stk.push(i);
                x = tx , y = ty;
                break;
            }
        }
    }
    while(!stk.empty())
    {
        query((stk.top() + 2) % 4);
        stk.pop();
    }
}
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    queue<P> que;
    memset(step, -1, sizeof(step));
    P start = P(33, 33);
    int x = 33, y = 33, tx, ty;
    step[x][y] = 0;
    que.push(start);
    P pre = start, now;
    while(!que.empty())
    {
        now = que.front(); que.pop();
//        cout << "now " << pre.FI - 33 << ' ' << pre.SE - 33 << endl;
        back(pre, 1);
//        cout << "back 0 0" << endl;
        back(now, 0);
//        cout << "go " << now.FI - 33 << ' ' << now.SE - 33 << endl;
        pre = now;
        for(int i = 0; i < 4; i++)
        {
            tx = now.FI + dx[i];
            ty = now.SE + dy[i];
            if(0 < tx && tx < 66 && 0 < ty && ty < 66 && step[tx][ty] == -1)
            {
                if(query(i))
                {
                    que.push(P(tx, ty));
                    step[tx][ty] = step[now.FI][now.SE] + 1;
                    query((i + 2) % 4);
                }
                else
                    step[tx][ty] = -2;
            }
        }
//        cout << "  Finish" << endl;
    }
    printf("%s\n", s[4]);
    return 0;
}
