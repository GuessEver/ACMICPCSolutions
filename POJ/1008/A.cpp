#include <cstdio>
#include <cstring>
const char name1[][20] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
const char name2[][20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
char month[20];
int day, year;
int get(char *s)
{
	for(int i = 0; i < 19; i++) if(!strcmp(s, name1[i])) return i;
}
int getDays(char *s)
{
	return get(s) * 20;
}
int main()
{
	int T; scanf("%d", &T);
	printf("%d\n", T);
	while(T--)
	{
		scanf("%d.%s%d", &day, month, &year);
		int total = 365 * year + getDays(month) + day;
		int answer_year = total / 260;
		int answer_day = total % 13 + 1;
		int answer_month = (total % 260) % 20;
		printf("%d %s %d\n", answer_day, name2[answer_month], answer_year);
	}
	return 0;
}
