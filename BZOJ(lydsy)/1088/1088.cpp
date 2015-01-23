/**************************************************************
    Problem: 1088
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:1156 kb
****************************************************************/
 
#include<cstdio>
const int N=10000+10;
#define fori(i,a,b) for(int i=a;i<=b;i++)
 
int n,a[N];
int f[N][2][2][2];
int all;
 
void read()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
 
inline int count(int s)
{
	int res=0;
	while(s)
	{
		res+=(s&1);
		s>>=1;
	}
	return res;
}
 
int work()
{
	fori(j,0,0)fori(k,0,1)fori(t,0,1)
	if(j+k+t==a[1]) f[1][j][k][t]++;

	for(int i=2;i<=n;i++)
	fori(j,0,1)fori(k,0,1)fori(t,0,1)//第i行相邻状态为j,k,t
	fori(h,0,1)//i-1行相邻状态为h,j,k
	if(j+k+t==a[i] && h+j+k==a[i-1]) f[i][j][k][t]+=f[i-1][h][j][k];
	 
	int res=0;
	fori(j,0,1)fori(k,0,1)fori(t,0,0)
		res+=f[n][j][k][t];
	return res;
}
 
int main()
{
	read();
	printf("%d\n",work());
	return 0;
}
