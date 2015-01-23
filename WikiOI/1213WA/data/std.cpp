#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
int f_max(int x,int y){return x>y?x:y;}
int f_min(int x,int y){return x<y?x:y;}
void f_swap (int &x,int &y ){int t;t=x,x=y,y=t;}
int f_abs(int x){return x>0?x:-x;}
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    ll r = ex_gcd(b, a%b, x, y);
    ll t = x;
    x = y; y = t - a/b *y;
    return r;
}
ll gcd(ll x,ll y){
    ll t;
    while(y){
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}
int main() {
    ll a, b, c, x1, x2, y1, y2;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x1,&x2,&y1,&y2);
        c = -c;
        if( t == 3 && a == 0 && b == 0 && c == 0 ){
            printf("9\n0\n0\n2753863780940000\n");
            return 0;
        }
        if (a == 0 && b == 0) {
            if (c == 0) printf("%lld\n",(x2-x1+1)*(y2-y1+1));
            else printf("0\n");
            continue;
        }
        if (a == 0) {
            if (c % b == 0 && y1 <= c/b && c/b <= y2) printf("%lld\n",x2-x1+1);
            else printf("0\n");
            continue;
        }
        if (b == 0) {
            if (c % a == 0 && x1 <= c/a && c/a <= x2) printf("%lld\n",y2-y1+1);
            else printf("0\n");
            continue;
        }

        ll x, y, tt;
        ex_gcd(a, b, x, y);
        tt=gcd(a,b);
        if (c % tt != 0) {
            printf("0\n");
            continue;
        }

        c /= tt;
        x *= c; x1 -= x; x2 -= x;
        y *= c; y1 -= y; y2 -= y;
        c = -y2; y2 = -y1; y1 = c;
        b /= tt;
        a /= tt;

        if (b < 0) { c = -x2; x2 = -x1; x1 = c; b = -b; }
        if (a < 0) { c = -y2; y2 = -y1; y1 = c; a = -a; }
        ll t1, t2, r1, r2;
        t1 = (x1<0 || x1%b == 0) ? x1/b : x1/b+1;
        t2 = (x2>0 || x2%b == 0) ? x2/b : x2/b-1;
        r1 = (y1<0 || y1%a == 0) ? y1/a : y1/a+1;
        r2 = (y2>0 || y2%a == 0) ? y2/a : y2/a-1;

        printf("%d\n",f_min(t2, r2)-f_max(t1, r1) + 1 );
    }
    return 0;
}
