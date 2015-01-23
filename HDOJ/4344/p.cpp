#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=2.0*asin(1.0),eps=1e-12;
const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
#define ull long long
//miller rabin
//判断自然数n是否为素数,并且可以分解质因子
ull  gcd(ull a,ull b){ 			//最大公约数
	return b?gcd(b,a%b):a;
}
ull product_mod(ull A, ull B, ull C){
	ull R=0, D=A;
	while (B > 0){
        if ( B&1 ) R = (R + D) % C;
		D = (D + D) % C;
		B >>=1;
	}
	return R;
}
ull power_mod(ull A, ull B, ull C)
{
	ull R = 1, D = A;
	while (B){
		if (B&1) R = product_mod(R, D, C);
		D = product_mod(D, D, C);
		B >>=1;
	}
	return R;
}
int pri[]={2,3,5,7,11,13,17,19,23,29};
bool miller_rabin(ull n)
{
	if(n<2)
		return false;
	if(n==2)
		return true;
	if(!(n&1))
		return false;
	ull k = 0, i, j, m, a;
	m = n - 1;
	while(m % 2 == 0)
		m = (m >> 1), k++;
	for(i = 0; i < 10; i ++){
		if(pri[i]>=n)return 1;
		a = power_mod( pri[i], m, n );
		if(a==1)continue;
		for(j = 0; j < k; j ++){
			if(a==n-1)break;
			a = product_mod(a,a,n);
		}
		if(j < k)continue;
		return false ;
	}
	return true;
}
ull pollard_rho(ull C, ull N){
	ull I, X, Y, K, D;
	I = 1;
	X = rand() % N;
	Y = X;
	K = 2;
	do{
		I++;
		D = gcd(N + Y - X, N);
		if (D > 1 && D < N) return D;
		if (I == K) Y = X, K *= 2;
		X = (product_mod(X, X, N) + N - C) % N;
	}while (Y != X);
	return N;
}
map<ull,int>M;
void rho(ull N){
    if(N<=1)return ;
	if (miller_rabin(N)){
	    M[N]=1;
	    return ;
	}
	do{
		ull T = pollard_rho(rand() % (N - 1) + 1, N);
		if (T < N&&T>0){
			ull A, B;
			rho(T);
			rho(N/T);
			return ;
		}
	}while (true);
}
pair<ull,int>s[20];
int num;
void prime_factor(ull n){
    M.clear(),num=0;
    rho(n);
    map<ull,int>::iterator r;
    ull temp=n;
    for(r=M.begin();r!=M.end();r++){
        r->second=0;
        while(temp%r->first==0){
            r->second++;
            temp=temp/r->first;
        }
        s[num++]=(*r);
    }
}
int main()
{
	int i,j,k,CASE;
	scanf("%d",&CASE);
	while(CASE--)
	{
	    ull x,ans=0,temp;
		scanf("%llu",&x);
		prime_factor(x);
		for (int i=0;i<num;i++)
		{
		    temp = 1;
		    for (j=1;j<=s[i].second;j++)
                temp *= s[i].first;
		    //printf("%I64u:%d:%I64u\n",s[i].first,s[i].second,temp);

		    ans += temp;
		}
        if (num==1)
            ans = ans/s[0].first;
        printf("%d %llu\n",num,ans);

	}
	return 0;
}

