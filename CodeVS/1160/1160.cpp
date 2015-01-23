#include<cstdio>
#include<cstring>
const int dx[]={0,-1,0,1};
const int dy[]={1,0,-1,0};
int n;
int map[110][110];

int main()
{
	scanf("%d",&n);
	int x=n/2+1,y=x;
	int val=1;
	map[x][y]=val++;
	int t=1,k=0;
	while(x<=n&&y<=n)
	{
		//printf("%d %d\n",x,y);
		//getchar();
		for(int kk=1;kk<=2;kk++)
		{
			for(int i=1;i<=t;i++)
			{
				x+=dx[k];y+=dy[k];
				map[x][y]=val++;
			}
			k++;
			k%=4;
		}
		t++;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",map[i][j]);
			if(i+j==n+1||i-j==0) sum+=map[i][j];
		}
		printf("\n");
	}
	printf("%d\n",sum);
	//while(1);
	return 0;
}
