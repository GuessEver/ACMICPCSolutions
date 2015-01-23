#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
#define MAXN 110
#define oo 999999999

int s,plane,a,b,x[500],y[500],car[MAXN],num;
double map[500][500],dist[500];
bool h[500];

void get_xy(int k,int i,int j)
{
    int dx,dy;
    dx=x[k]-x[i];dy=y[k]-y[i];
    x[num]=x[j]-dx;  y[num]=y[j]-dy;
}

void getxy(int pos)
{
    int i,j;
    num++;
    int b12,b23,b31;
    b12=(x[pos]-x[pos+1])*(x[pos]-x[pos+1])+(y[pos]-y[pos+1])*(y[pos]-y[pos+1]);
    b23=(x[pos+1]-x[pos+2])*(x[pos+1]-x[pos+2])+(y[pos+1]-y[pos+2])*(y[pos+1]-y[pos+2]);
    b31=(x[pos+2]-x[pos])*(x[pos+2]-x[pos])+(y[pos+2]-y[pos])*(y[pos+2]-y[pos]);
    
    if(b12+b23==b31) get_xy(pos+1,pos,pos+2);
    else if(b23+b31==b12) get_xy(pos+2,pos,pos+1);
    else if(b31+b12==b23) get_xy(pos,pos+1,pos+2);
}

double di(int i,int j)
{
    double q;
    q=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    return q;
}

void citymap(int l,int r,int ii)
{
    for(int i=l;i<=r;i++)
        for(int j=l;j<=r;j++)
            map[i][j]=di(i,j)*car[ii];
}

void planemap()
{
    int i,j;
    for(i=1;i<=num;i++)
        for(j=1;j<=num;j++)
            map[i][j]=di(i,j)*plane;
}

void read()
{
    scanf("%d%d%d%d",&s,&plane,&a,&b);
    int i,j;
    for(i=1;i<=s;i++)
    {
        for(j=1;j<=3;j++)
        {
            num++;
            scanf("%d%d",&x[num],&y[num]);
        }
        getxy(num-2);
        scanf("%d",&car[i]);
    }
    planemap();
    for(i=1;i<=s;i++)
        if(car[i]<plane)
            citymap((i-1)*4+1,i*4,i);
}

void dij()
{
    int k;
    double min;
    for(int i=1;i<=num;i++)
    {
        min=oo;k=0;
        for(int j=1;j<=num;j++)
            if(!h[j] && min>dist[j])
                { min=dist[j]; k=j; }
        h[k]=true;
        for(int j=1;j<=num;j++)
            if(!h[j] && map[k][j]!=0 && dist[j]>dist[k]+map[k][j])
                dist[j]=dist[k]+map[k][j];
    }
}

void work()
{
    double min=oo;
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<=4*s+10;j++)
        {
            h[j]=false;
            dist[j]=oo;
        }
        dist[(a-1)*4+i]=0;
        dij();
        for(int j=1;j<=4;j++)
        if(min>dist[(b-1)*4+j])
            min=dist[(b-1)*4+j];
    }
    printf("%.1lf\n",min);
}

int main()
{
    int number;
    scanf("%d",&number);
    for(int i=1;i<=number;i++)
    {
        read();
        work();
    }
    return 0;
}
