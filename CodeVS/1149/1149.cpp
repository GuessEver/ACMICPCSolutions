/*==============================*\
|           C++ Code
| http://blog.csdn.net/jiangzh7
|          By jiangzh
\*==============================*/
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 0x7fffffff

int n,m,c[100][100];
char map[10000][10000];
int maxx=1500,minx=1500,maxy=1500,miny=1500;

void work(int x,int y)//带入左下角的点坐标
{
    maxx=max(maxx,x);minx=min(minx,x-5);
    maxy=max(maxy,y+6);miny=min(miny,y);
    map[x][y]=map[x][y+4]='+';map[x][y+1]=map[x][y+2]=map[x][y+3]='-';//map[x][y+5]=map[x][y+6]='.';
    x--;
    map[x][y]=map[x][y+4]='|';map[x][y+1]=map[x][y+2]=map[x][y+3]=' ';map[x][y+5]='/';//map[x][y+6]='.';
    x--;
    map[x][y]=map[x][y+4]='|';map[x][y+1]=map[x][y+2]=map[x][y+3]=' ';map[x][y+5]=' ';map[x][y+6]='+';
    x--;
    map[x][y]=map[x][y+4]='+';map[x][y+1]=map[x][y+2]=map[x][y+3]='-';map[x][y+5]=' ';map[x][y+6]='|';
    x--;
    /*map[x][y]='.';*/map[x][y+1]=map[x][y+5]='/';map[x][y+2]=map[x][y+3]=map[x][y+4]=' ';map[x][y+6]='|';
    x--;
    /*map[x][y]=map[x][y+1]='.';*/map[x][y+2]=map[x][y+6]='+';map[x][y+3]=map[x][y+4]=map[x][y+5]='-';
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&c[i][j]);
    for(int i=0;i<3000;i++)
        for(int j=0;j<3000;j++)
            map[i][j]='.';

    int xx=1500,yy=1500;
    for(int i=1;i<=n;i++)
    {
        int x=xx,y=yy;
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=c[i][j];k++)
            {
                work(xx,yy);
                xx-=3;
            }
            yy+=4;xx=x;
        }
        yy=y-2;xx=x+2;
    }
            
            
    for(int i=minx;i<=maxx;i++)
    {
        for(int j=miny;j<=maxy;j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
    return 0;
}
