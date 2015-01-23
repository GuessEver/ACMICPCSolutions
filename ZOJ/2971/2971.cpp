#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
map<string, int> number;

char s[100000];
char t[100];

int main()
{
	number["ten"] = 10;
	number["one"] = 1; number["two"] = 2;
	number["three"]= 3; number["four"] = 4;
	number["five"] = 5; number["six"] = 6;
	number["seven"] = 7; number["eight"] = 8;
	number["nine"] = 9; number["zero"] = 0;
	number["eleven"] = 11; number["twelve"] = 12;
	number["thirteen"] = 13; number["fourteen"] = 14;
	number["fifteen"] = 15; number["sixteen"] = 16;
	number["seventeen"] = 17; number["eighteen"] = 18;
	number["nineteen"] = 19; number["twenty"] = 20;
	number["thirty"] = 30; number["forty"] = 40;
	number["fifty"] = 50; number["sixty"] = 60;
	number["seventy"] = 70; number["eighty"] = 80;
	number["ninety"] = 90; number["hundred"] = 100;
	number["thousand"] = 1000; number["million"] = 1000000;
	int T; scanf("%d\n", &T);
	while(T--)
	{
		memset(s, 0, sizeof(s));
		fgets(s, 50000, stdin);
		int len = 0;
		long long res = 0;
		long long ttt = 0;
		while(sscanf(s+len, "%s", t) == 1)
		{
			string tmp(t);
			len += strlen(t);
			if(tmp == "and") continue;
			if(number[tmp] > 100)
			{
				res += ttt * number[tmp];
				ttt = 0;
			}
			else if(number[tmp] == 100) ttt *= 100;
			else ttt += number[tmp];
		}
		res += ttt;
		printf("%lld\n", res);
	}
	return 0;
}
