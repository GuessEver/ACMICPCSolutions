#include<stdio.h>
double work(long a)
{
    long length,num;
    double score;
    if(a==0)  return 0.000;
    if(a==1)  return 1.000;
    if(a==2)  return 5.000;
    length=2;
    num=2;
    score=5;
    while(a>2)
    {
        if(length>num)
        {
            num++;
            score+=num*length;
        }
        else
        {
            length++;
            score+=num*length;
        }
        a--;
    }
    return score;

}
int main()
{
    long length,num,n;
    length=2;
    num=2;
    scanf("%ld",&n);
    printf("%.3lf",work(n));
    return 0;


}

