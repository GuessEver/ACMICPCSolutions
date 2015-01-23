#include<cstdio>
#include<string>
#include<iostream>

double a,b,c,d;
double ans[10];

double jue(double x)
{
    if(x>=0)return x;
    else return -x;
}

double f(double x)
{
    double y;
    y=a*x*x*x+b*x*x+c*x+d;
    return y;
}

double findans(double l,double r)
{
    double i;
    for(i=l;i<=r;i+=0.01)
    {
        if(f(i)==0)return i;
    }
}

int main()
{
    //freopen("p1.in","r",stdin);
    //freopen("p1.out","w",stdout);
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    double i;
    int num=0;
    for(i=-100.0;i<=100.0;i+=0.01)
        if(jue(f(i))<=0.000001) {num++;ans[num]=i;}
    for(int j=1;j<num;j++)printf("%.2lf ",ans[j]);
    printf("%.2lf",ans[num]);
    return 0;
}

