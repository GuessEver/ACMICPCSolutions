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
#include <climits>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
char s[100];
int len;
void solve()
{
    int n = len + 1;
    int i, k;
    for(i = 1; i < len; i++)
        if(s[i] == s[0])
            n--;
        else
            break;
    printf("%d\n%d\n%d\n", n, 1, n - 1);
    for(k = 1; k <= n; i++, k++)
    {
        if(k == 1)
        {
            for(char j = 'a'; j <= 'z'; j++)
            {
                if(j == s[0])
                    printf("1");
                else if(j == s[i])
                    printf("%d", k + 1);
                else
                    printf("%d", n);
                putchar(j == 'z' ? '\n' : ' ');
            }
        }
        else if(k == n || k == n - 1)
        {
            for(int j = 1; j <= 26; j++)
                printf("%d%c", n, j == 26 ? '\n' : ' ');
        }
        else
        {
            for(char j = 'a'; j <= 'z'; j++)
                printf("%d%c", j == s[i] ? k + 1: n, j == 'z' ? '\n' : ' ');
        }
    }
    n = len + 1;
    printf("%d\n%d\n%d\n", n, 1, len);
    for(int i = 1; i <= n; i++)
    {
        if(i == n - 1)
        {
            for(char j = 'a'; j <= 'z'; j++)
            {
                if(j == s[len - 1])
                    printf("%d", n - 1);
                else
                    printf("%d", n);
                putchar(j == 'z' ? '\n' : ' ');
            }
        }
        else if(i == n)
        {
            for(int j = 1; j <= 26; j++)
                printf("%d%c", n, j == 26 ? '\n' : ' ');
        }
        else
        {
            for(char j = 'a'; j <= 'z'; j++)
                printf("%d%c", j == s[i - 1] ? i + 1 : n, j == 'z' ? '\n' : ' ');
        }
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("decomposable.in", "r", stdin);
    freopen("decomposable.out", "w", stdout);
#endif
    int i;
    while(~scanf("%s", s))
    {
        len = strlen(s);
        if(len == 1)
            puts("NO");
        else
        {
            bool flag = true;
            for(i = 1; i < len; i++)
                if(s[i] != s[0])
                {
                    flag = false;
                    break;
                }
            if(flag)
                puts("NO");
            else
            {
                puts("YES");
                solve();
            }
        }
    }
    return 0;
}
