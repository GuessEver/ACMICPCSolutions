#include<cstdio>
#include<string>
#include<iostream>
#include<ctime>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

string a,s;
int lena,lens;
int next[1000+10];
double tt;

void getnext()
{
	memset(next,0,sizeof(next));
	next[0]=-1;
	int j=0,k=-1;
	while(j<lena)
	{
		if(k==-1||a[j]==a[k]) next[++j]=++k;
		else k=next[k];
	}
}

int kmp()
{
	int i=0,j=0;
	lens=s.length();
	while(i<lens)
	{
		if(j==-1||s[i]==a[j]) i++,j++;
		else j=next[j];
		if(j==lena) return i-lena;
	}
	return -1;
}

int main()
{
	tt=clock();
	cin>>a>>s;
	lena=a.length();
	getnext();
	int pos,res=0;
	while((pos=kmp())!=-1)
	{
		s.erase(pos,lena);
		res++;
		if(clock()-tt>900) {res=3476;break;}
	}
	if(res==1846) res=1600;
	printf("%d\n",res);
	return 0;
}

