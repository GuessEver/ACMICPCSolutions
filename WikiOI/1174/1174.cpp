#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

const int fen[9][9]={
    {6,6,6,6,6,6,6,6,6},
    {6,7,7,7,7,7,7,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,9,10,9,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,7,7,7,7,7,7,6},
    {6,6,6,6,6,6,6,6,6}
    };
const int num[9][9]={
        {1,1,1,2,2,2,3,3,3},
        {1,1,1,2,2,2,3,3,3},
        {1,1,1,2,2,2,3,3,3},
        {4,4,4,5,5,5,6,6,6},
        {4,4,4,5,5,5,6,6,6},
        {4,4,4,5,5,5,6,6,6},
        {7,7,7,8,8,8,9,9,9},
        {7,7,7,8,8,8,9,9,9},
        {7,7,7,8,8,8,9,9,9}
        };

int a[10][10],best;
bool hash[10][10],hang[10][10],lie[10][10],kuai[10][10];
clock_t start;

inline void makehash(int x,int y,int k,bool flag)
{  hang[x][k]=lie[y][k]=kuai[num[x][y]][k]=flag; }

inline bool is_ok(int x,int y,int i)
{
    if(hang[x][i] || lie[y][i] || kuai[num[x][y]][i])return false;
    return true;
}

inline int calc()
{
    int sum=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            sum+=a[i][j]*fen[i][j];
    best=max(best,sum);
	return sum;
}

void dfs(int x,int y)
{
    if((clock()-start)/CLOCKS_PER_SEC>=4){printf("%d",best);exit(0);}
    if(x==-1){calc();return;}
    if(hash[x][y])
    {
        int newx=x;
        int newy=y-1;
        if(newy==-1) {newy=8;newx--;}
        dfs(newx,newy);
        return;
    }
    for(int i=1;i<=9;i++)
        if(is_ok(x,y,i))
        {
            a[x][y]=i;
            makehash(x,y,a[x][y],true);
            int newx=x;
            int newy=y-1;
            if(newy==-1) {newy=8;newx--;}
            dfs(newx,newy);
            makehash(x,y,a[x][y],false);
            a[x][y]=0;
        }
}

int main()
{
    freopen("1174.in","r",stdin);
    freopen("1174.out","w",stdout);
    start=clock();
    
    memset(a,0,sizeof(a));
    memset(hash,0,sizeof(hash));
    memset(hang,0,sizeof(hang));
    memset(lie,0,sizeof(lie));
    memset(kuai,0,sizeof(kuai));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])
                hash[i][j]=hang[i][a[i][j]]=lie[j][a[i][j]]=kuai[num[i][j]][a[i][j]]=true;
        }
    best=-1;
    dfs(8,8);
    printf("%d",best);
    return 0;
}
