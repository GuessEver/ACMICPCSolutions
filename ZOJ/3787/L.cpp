#include <cstdio>
#include <algorithm>

struct Time{
	int hour, minute, second, ord;
	void Read(int i)
	{ 
		scanf("%d:%d:%d", &hour, &minute, &second); 
		ord = i;
	}
	bool operator < (const Time &a) const
	{
		if(hour == a.hour && minute == a.minute) return second < a.second;
		if(hour == a.hour) return minute < a.minute;
		return hour < a.hour;
	}
	Time operator + (int &tmp) const
	{
		Time res = *this;
		res.second += tmp;
		res.minute += res.second / 60; res.second %= 60;
		res.hour += res.minute / 60; res.minute %= 60;
		return res;
	}
}a[20000+10];
int n, L;
int ans[20000+10];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &L);
		for(int i = 1; i <= n; i++) a[i].Read(i);
		std::sort(a+1, a+1+n);
		ans[0] = 0;
		Time tmp = a[1];
		for(int i = 1; i <= n; i++)
		{
			if(i > 1 && a[i] < tmp + L) continue;
			else{
				ans[++ans[0]] = a[i].ord;
				tmp = a[i];
			}
		}
		printf("%d\n", ans[0]);
		std::sort(ans+1, ans+1+ans[0]);
		for(int i = 1; i < ans[0]; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[ans[0]]);
	}
	
	return 0;
}
