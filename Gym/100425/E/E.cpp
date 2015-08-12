#include <iostream>
#include <iomanip>
using namespace std;
//------------------------   code   ---------------------------------//
const int NUM = 100010;
struct Matrix
{
    long double a[2][2];
    void init(long double p)
    {
        a[0][0] = a[1][1] = 1.0 - p;
        a[0][1] = a[1][0] = p;
    }
    Matrix operator * (const Matrix &b) const
    {
        Matrix c;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            {
                c.a[i][j] = 0.0;
                for(int k = 0; k < 2; k++)
                    c.a[i][j] += a[i][k] * b.a[k][j];
            }
        return c;
    }
    Matrix operator ^ (int k)
    {
        Matrix res, x = *this;
        res.a[0][0] = res.a[1][1] = 1.0;
        res.a[0][1] = res.a[1][0] = 0.0;
        while(k)
        {
            if(k & 1) res = res * x;
            x = x * x;
            k >>= 1;
        }
        return res;
    }

};
void solve(int d, int t, long double p, long double &L, long double &R)
{
    //L: d == 0, R: d == 1
    Matrix a;
    a.init(p);
    a = a ^ t;
    L = a.a[d][0], R = a.a[d][1];
}
int n;
char dir[2];
int t;
long double p;
long double dp[NUM][2], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    long double L, R;
    dp[0][0] = 1.0, dp[0][1] = 0.0;
    ans = 0.0;
    for(int i = 1; i <= n; i++)
    {
        cin >> t >> dir >> p;
        solve(dir[0] == 'R', t, p, L, R);
        dp[i][0] = dp[i - 1][0] * R + dp[i - 1][1] * R;
        dp[i][1] = dp[i - 1][0] * L + dp[i - 1][1] * L;
        ans += dp[i - 1][0] * L + dp[i - 1][1] * R;
    }
    cout << setiosflags(ios::fixed) << setprecision(9) << ans << endl;
    return 0;
}
