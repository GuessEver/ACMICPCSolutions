#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
using std::swap;

char s[200], t[200];
int lens, lent;
int scnt['z'+10], tcnt['z'+10];

bool aut()
{
	int i = 0, j = 0;
	while(i < lens && j < lent)
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
			if(j == lent) return 1;
		}
		else i++;
	}
	return 0;
}

int main()
{
	freopen("B.in", "r", stdin);
	scanf("%s", s); lens = strlen(s);
	scanf("%s", t); lent = strlen(t);
	for(int i = 0; i < lens; i++) scnt[s[i]]++;
	for(int i = 0; i < lent; i++) tcnt[t[i]]++;
	bool flag = 1, flag2 = 1;
	for(char i = 'a'; i <= 'z'; i++)
	{
		if(scnt[i] != tcnt[i]) flag = 0;
		if(scnt[i] < tcnt[i]) flag2 = 0;
	}
	if(aut()) printf("automaton\n");
	else if(lens == lent && flag) printf("array\n");
	else if(flag2) printf("both\n");
	else printf("need tree\n");
	return 0;
} 

