#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
using std::string;

int h[100000+10], pri[10000+10];
int Cnt;
string sp[10000 + 10];

void ItoA(int x, string &a)
{
	a = "";
	while(x)
	{
		char ch = (x % 10) + '0';
		a = ch + a;	
		x /= 10;
	}
	//printf("%s\n", a.c_str());
}

void make_prime_list(int maxp)
{
	Cnt = 0;
	for(int i = 2; i <= maxp; i++)
	{
		if(!h[i]) pri[Cnt++] = i;
		for(int j = 0; j < Cnt && pri[j] <= maxp / i; j++)
		{
			h[i * pri[j]] = true;
			if(i % pri[j] == 0) break;
		}
	}
	//printf("%d\n", Cnt); // 9592
	for(int i = 0; i < Cnt; i++)
		ItoA(pri[i], sp[i]);
}

char s[1000];

int main()
{
	make_prime_list(100000);
	while(scanf("%s", s) == 1)
	{
		string ss(s);
		if(ss == "0") break;
		for(int i = Cnt - 1; i >= 0; i--)
		{
			if((int)ss.find(sp[i]) != -1)
			{
				puts(sp[i].c_str());
				break;
			}
		}
	}
	return 0;
}
