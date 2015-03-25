#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <cstring>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef long long LL;
const double eps = 1e-10;
const int MAXN = 25;


int n;

struct Point {
    double x,y;
    Point(){}
    Point(double x, double y):x(x),y(y){}
    double dist(Point p){
        return sqrt( (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y) );
    }
};
Point p[MAXN];
Point mag[3];
double add(double x, double y){
    if (abs(x+y) <  eps*(abs(x)+abs(y)))
        return 0;
    return x+y;
}

int judge(Point l,Point r, Point ml, Point mr, double ra){
    Point mid;
    while(abs(l.dist(r))>eps){
        mid.x= (l.x+r.x)*0.5;
        mid.y= (l.y+r.y)*0.5;
        double d1=(ml.dist(mid)-ra);
        double d2=(mr.dist(mid)-ra);
        if (d1<=0 && d2<=0)
            return 1;
        if (d1 <= 0)
            l=mid;
        else
            r=mid;
    }
    return 0;
}
int _judge(double r){
    int i,j;
    for(i=0; i<n-1; i++){
        for(j=i+1;j<n; j++){
            double r1,r2,r3,r4;
            r1=(p[i].dist(mag[1]) - r);
            r2=(p[j].dist(mag[1]) - r);
            r3=(p[i].dist(mag[2]) - r);
            r4=(p[j].dist(mag[2]) - r);
            if((r1<= 0 && r2<= 0) || (r3<=0 && r4<=0))
                continue;
            if(r1 <=0 && r4<=0){
                if(judge(p[i] ,p[j],mag[1],mag[2], r))
                    continue;
            }
            if(r2<=0 && r3<=0){
                if(judge(p[i],p[j],mag[2],mag[1],r))
                    continue;
            }
            return 0;
        }
    }
    return 1;
}

int main(){
    while(~scanf("%d" ,&n)){
        for(int i=0; i<n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        for(int i=1; i<=2; i++)
            scanf("%lf%lf", &mag[i].x, &mag[i].y);
        double ll=0.0, lr=4000.0;
        double md;
        while(ll+eps < lr){
            md=(ll+lr)*0.5;
            if(_judge(md))
                lr=md;
            else
                ll=md;
        }
        printf("%.3lf\n",md);
    }
}

