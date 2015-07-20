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
int prim[NUM];
int prim_num;
void pre_prim()
{
    prim[0] = 1;
    prim_num = 1;
    for(int i = 2; i < NUM; i++)
        if(!prim[i])
        {
            prim[prim_num++] = i;
            for(int j = i + i; j < NUM; j += i)
                prim[j] = 1;
        }
}
LL ans[33][33];
int n;
set<LL> st;
bool right()
{
    LL sum = 1, tmp;
    int i, j;
    for(i = 0; i < n; i++)
        sum *= ans[0][i];
    for(i = 1; i < n; i++)
    {
        tmp = 1;
        for(j = 0; j < n; j++)
            tmp *= ans[i][j];
        if(tmp != sum)
            return false;
    }
    st.clear();
    for(j = 0; j < n; j++)
    {
        tmp = 1;
        for(i = 0; i < n; i++)
        {
            if(st.find(ans[i][j]) != st.end())
                return false;
            st.insert(ans[i][j]);
            tmp *= ans[i][j];
        }
        if(tmp != sum)
            return false;
    }
    return true;
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("elegant.in", "r", stdin);
    freopen("elegant.out", "w", stdout);
#endif
    int i, j, k;
    pre_prim();
    while(~scanf("%d", &n))
//    for(n = 3; n <= 30; n += 1)
    {
        if(n & 1)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    ans[i][j] = prim[(i + j) % n];
                }
            }
            for(i = 0; i < n; i++)
            {
                for(j = 0, k = n + i; j < n; j++, k--)
                {
                    if(k < n)
                        k += n;
                    ans[i][j] *= prim[k];
                }
            }
        }
        else
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    ans[i][j] = prim[(i - j + n) % n];
                }
            }
            for(i = 0; i < n; i++)
            {
                k = i & 1 ? i / 2 + n / 2 : i / 2;
                for(j = 0; j < n; j++)
                {
                    ans[i][j] *= prim[(j + k) % n + n];
                }
            }
            for(i = 0, k = 0; i < n; i++, k += 2)
            {
                if(k == n)
                    k = 1;
                for(j = 0; j < n; j++)
                {
                    ans[i][j] *= prim[(j - k + n) % n + n + n];
                }
            }
        }
//        if(!right())
//        {
//            cout << "Error" << n << endl;
//            return 0;
//        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("%I64d%c", ans[i][j], j == n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
