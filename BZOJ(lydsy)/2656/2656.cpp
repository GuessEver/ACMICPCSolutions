/**************************************************************
    Problem: 2656
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:52 ms
    Memory:1944 kb
****************************************************************/

#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
 
const int number=100000;
 
struct BigInt{
    int len,c[100];
    BigInt(){len=1;memset(c,0,sizeof(c));}
    void Read()
    {
        memset(c,0,sizeof(c));len=1;
        char s[200]; memset(s,0,sizeof(s));
        scanf("%s",s);
        int lens=strlen(s);
        int k=1;
        for(int i=lens-1;i>=0;i--)
        {
            c[len]+=(s[i]-'0')*k;
            k*=10;
            if(k==number) len++,k=1;
        }
        Zero();
    }
    void Print()
    {
        printf("%d",c[len]);
        for(int i=len-1;i>=1;i--) printf("%05d",c[i]);
        puts("");
    }
    void Zero()
        { while(len>1 && c[len]==0) len--; }
    int operator & (int a)
        { return c[1]&a; }
    bool operator == (int a)
        { return len==1 && c[len]==1; }
    BigInt operator = (int a)
    {
        memset(c,0,sizeof(c));
        c[len=1]=a;
    }
    BigInt operator + (BigInt a)
    {
        BigInt res;
        res.len=max(len,a.len)+1;
        for(int i=1;i<=res.len;i++)
        {
            res.c[i]+=c[i]+a.c[i];
            res.c[i+1]+=res.c[i]/number;
            res.c[i]%=number;
        }
        res.Zero();
        return res;
    }
    BigInt operator + (int a)
    {
        BigInt tmp;tmp=a;
        BigInt res=*this;
        return res+tmp;
    }
    BigInt operator / (int a)
    {
        BigInt res;
        res.len=len;
        for(int i=res.len;i>=1;i--)
        {
            res.c[i]+=c[i];
            res.c[i]/=a;
            if(i>1) res.c[i-1]+=c[i]%a*number;
        }
        res.Zero();
        return res;
    }
};
 
 
BigInt n;
BigInt p,q;
 
void calc(BigInt x)
{
    if(x==1)
    {
        p=1;q=0;
        return;
    }
    if(x&1) calc(x/2+1);
    else calc(x/2);
    if(x&1) p=p+q;
    else q=q+p;
}
 
void work()
{
    n.Read();
    calc(n);
    p.Print();
}
 
int main()
{
    int T; scanf("%d",&T);
    while(T--) work();
    return 0;
}
