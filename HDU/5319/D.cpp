#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <climits>
#include <bitset>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
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
//------------------------   code   ---------------------------------//
const int NUM = 100010;
int T, n, m;
char grid[55][55];

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    int i;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%s", grid[i]);
        m = strlen(grid[0]);
        int ans = 0;
        for(i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 'R' || grid[i][j] == 'G')
                {
                    ans++;
                    for(int k = 0; i + k < n && j + k < m; k++)
                        if(grid[i + k][j + k] == 'R')
                            grid[i + k][j + k] = '.';
                        else if(grid[i + k][j + k] == 'G')
                            grid[i + k][j + k] = 'B';
                        else
                            break;
                }
        for(i = 0; i < n; i++)
            for(int j = m - 1; j >= 0; j--)
                if(grid[i][j] == 'B')
                {
                    ans++;
                    for(int k = 0; i + k < n && j - k >= 0; k++)
                        if(grid[i + k][j - k] == 'B')
                            grid[i + k][j - k] = '.';
                        else
                            break;
                }
        printf("%d\n", ans);
    }
    return 0;
}
