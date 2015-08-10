#include <cstdio>
#include <cstring>

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int A, B;
int cnt[13];
int answer[13];

void get(int year, int month, int date, int day, int edyear)
{
	memset(cnt, 0, sizeof(cnt));
	int tmpcnt = 0;
	while(year < edyear)
	{
		if(check(year)) days[2] = 29; else days[2] = 28;
		if(date == 13 && day == 5) tmpcnt++;
		//if(year == 2015 && day == 5 && date == 13) printf("month = %d\n", month);
		day = (day + 1) % 7; date++;
		if(date > days[month])
		{
			date = 1;
			month++;
		}
		if(month > 12)
		{
			month = 1;
			year++;
			cnt[tmpcnt]++;
			tmpcnt = 0;
		}
	}
}

int main()
{
	scanf("%d%d", &A, &B);
	get(1900, 1, 1, 1, B + 1);
	for(int i = 0; i < 13; i++) answer[i] += cnt[i];
	get(1900, 1, 1, 1, A);
	for(int i = 0; i < 13; i++) answer[i] -= cnt[i];
	for(int i = 0; i < 13; i++) printf("%d: %d\n", i, answer[i]);
	return 0;
}
