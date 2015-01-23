#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::min;
using std::max;

int h, m, ansh, ansm, greatest, minerr;
int T;

int error(int T9)
{
	return abs(T - T9);
}

void renew(int t9)
{
	int hh = t9 / 60;
	int mm = t9 % 60;
	do{
		int cnt = (hh % 10 == 9) + (hh / 10 == 9) + (mm % 10 == 9) + (mm / 10 == 9);
		if(cnt >= greatest)
		{
			if(ansh == -1)
			{
				greatest = cnt;
				minerr = error(t9);
				ansh = hh; ansm = mm;
			}
			else if(cnt > greatest)
			{
				greatest = cnt;
				minerr = error(t9);
				ansh = hh; ansm = mm;
			}
			else if(error(t9) < minerr)
			{
				greatest = cnt;
				minerr = error(t9);
				ansh = hh; ansm = mm;
			}
			else if(error(t9) == minerr && (hh < ansh || (hh == ansh && mm < ansm)))
			{
				greatest = cnt;
				minerr = error(t9);
				ansh = hh; ansm = mm;
			}
		}
		hh--; mm += 60;
	}while(hh >= 0 && mm < 100);
}

int main()
{
	//freopen("text.txt", "w", stdout);
	while(scanf("%d:%d", &h, &m) == 2 && (h || m))
	//for(h = 0; h < 100; h++)
	//{
	//for(m = 0; m < 100; m++)
	{
		T = h * 60 + m;
		ansh = ansm = -1; greatest = 0; minerr = 0x3f3f3f3f;
		int start = min(T, (int)(1.0 * T / 10 * 8 - 1));
		while(10 * error(start) >= T) start++;
		int end = max(T, (int)(1.0 * T / 10 * 12 + 1));
		start = max(start, 0);
		end = min(end, 99 * 60 + 99);
		while(10 * error(end) >= T) end--;
		for(int T9 = start; T9 <= end; T9++)
			if(10 * error(T9) < T) renew(T9);
		renew(end);
		//printf("%c%02d:%02d%c,", '"', ansh, ansm, '"');
		printf("%02d:%02d\n", ansh, ansm);
	}//puts("");}
	return 0;
}
