#include <bits/stdc++.h>

using namespace std;
#define INF (1<<29)

typedef long long int lld;

int v[110];
int memo[110][110];
int sum[110];



int sum_call(int a, int b){
    return sum[b] - sum[a-1];
}

int dp(int beg, int end){

    if(beg>=end) return 0;

    int res = memo[beg][end];
    if(res!=-1) return res;
    int temp, a, b, ret;
    res = INF ;
    for(int i=beg ; i<end ; i++ ){
        temp = ( dp(beg,i) + dp(i+1,end) );
        a = sum_call(beg, i)% 100;
        b = sum_call(i+1, end) % 100;
        temp+= (a*b);
        res = min(res, temp);
    }

    memo[beg][end] = res;
    return res;
}


int main(){

    int i, j, k, test, kase = 0;

    int n;
    sum[0] = 0;
    while(scanf ("%d", &n)!=EOF){
        for( i=1 ; i<=n ; i++ ){
            scanf ("%d", &v[i]);
            sum[i]= v[i] + sum[i-1];
        }


        memset (memo, -1, sizeof memo);
        printf ("%d\n", dp(1,n));
    }

    return 0;
}

