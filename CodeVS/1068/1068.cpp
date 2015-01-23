

#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
const int N=350+10;
const int V=40+10;
int n,m;
int val[N],card[10];
int f[V][V][V][V];

int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		card[x]++;
	}
	f[0][0][0][0]=val[1];
	for(int a=0;a<=card[1];a++)
	for(int b=0;b<=card[2];b++)
	for(int c=0;c<=card[3];c++)
	for(int d=0;d<=card[4];d++)
	{
		if(a>0) f[a][b][c][d]=max(f[a][b][c][d],f[a-1][b][c][d]+val[1+a*1+b*2+c*3+d*4]);
		if(b>0) f[a][b][c][d]=max(f[a][b][c][d],f[a][b-1][c][d]+val[1+a*1+b*2+c*3+d*4]);
		if(c>0) f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c-1][d]+val[1+a*1+b*2+c*3+d*4]);
		if(d>0) f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c][d-1]+val[1+a*1+b*2+c*3+d*4]);
	}
	printf("%d\n",f[card[1]][card[2]][card[3]][card[4]]);
	//while(1);
	return 0;
}

			


