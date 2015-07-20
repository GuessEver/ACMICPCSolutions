#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
const int NUM = 300000 + 10;
int n;
int s[NUM], t[NUM];
char ans[NUM];
int sa[NUM], ww[NUM], wa[NUM], wv[NUM], wb[NUM];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(char *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ww[i]=0;
    for(i=0;i<n;i++) ww[x[i]=r[i + 1]]++;
    for(i=1;i<m;i++) ww[i]+=ww[i-1];
    for(i=n-1;i>=0;i--) sa[--ww[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ww[i]=0;
        for(i=0;i<n;i++) ww[wv[i]]++;
        for(i=1;i<m;i++) ww[i]+=ww[i-1];
        for(i=n-1;i>=0;i--) sa[--ww[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int main()
{
freopen("binary.in", "r", stdin);
freopen("binary.out", "w", stdout);
    scanf("%d", &n);
    int i, j;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        s[t[i]] = i;
    }
    for(i = n; i >= 1; i--)
    {
        if(s[i] != n - i + 1)
        {
            for(j = 1; j <= n; j++)
                ans[j] = s[j] < s[i] ? '0' : '1';
            break;
        }
    }
    if(i == 0)
    {
        for(j = 1; j <= n; j++)
            ans[j] = '0';
    }
    ans[n + 1] = 0;
    da(ans, sa, n + 1, '1' + 10);
    bool flag = 1;
    for(i = 1; flag && i <= n; i++)
    {
        if(t[i] != sa[i] + 1)
        flag = false;
    }
    if(flag)
    {
        puts(ans + 1);
    }
    else
    {
        puts("Error");
    }
}
