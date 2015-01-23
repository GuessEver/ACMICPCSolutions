#include<cstdio>

int f(int x)
{
    if(x==1||x==2) return 1;
    return f(x-1)+f(x-2);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}
