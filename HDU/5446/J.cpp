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
//------------------------   code   ---------------------------------//
const int NUM = 100010;
LL n, m, k, p[20], M;
#define ADD(x, y, mod) {if((x += y) >= mod) x -= mod;}
LL qmult(LL a, LL b, LL mod)
{
    LL res = 0;
    while(b)
    {
        if(b & 1) ADD(res, a, mod);
        ADD(a, a, mod);
        b >>= 1;
    }
    return res;
}
LL qpow(LL x, LL k, LL mod)
{
    LL res = 1;
    while(k)
    {
        if(k & 1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}
LL fact[NUM];
void Lucas_init(LL mod)
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i < NUM; ++i) fact[i] = fact[i - 1] * i % mod;
}
LL getInv(LL x, LL mod)
{
    LL res = 1;
    while(x > 1)
    {
        res = qmult(res, (mod - mod / x), mod);
        x = mod % x;
    }
    return res;
}
LL Lucas(LL n, LL m, LL mod) //mod是质数
{
    LL a, b, res = 1LL;
    while(n && m)
    {
        a = n % mod, b = m % mod;
        if(a < b) return 0LL;
        res = res * fact[a] % mod * qpow(fact[b] * fact[a - b] % mod, mod - 2, mod) % mod;
        n /= mod, m /= mod;
    }
    return res;
}
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
        IN(n), IN(m), IN(k);
        M = 1;
        for(int i = 0; i < k; ++i) M *= IN(p[i]);
        LL ans = 0;
        for(int i = 0; i < k; ++i)
        {
            Lucas_init(p[i]);
            LL x = Lucas(n, m, p[i]);
            LL Mi = M / p[i];
//            cout << x << ' ' << p[i] << ' ' << Mi << endl;
            ADD(ans, qmult(Mi, qmult(x, getInv(Mi % p[i], p[i]), M), M), M);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
