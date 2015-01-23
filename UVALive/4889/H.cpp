#include <cstdio>
#include <cmath>
#include <algorithm>

const double eps = 1e-7;
double a[5];

int dcmp(double x)
{
	if(fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}

bool letter(double x, double y, double z)
{
	return (dcmp(x - 125) >= 0 && dcmp(x - 290) <= 0
			&& dcmp(y - 90) >= 0 && dcmp(y - 155) <= 0
			&& dcmp(z - 0.25) >= 0 && dcmp(z - 7) <= 0);
}
bool packet(double x, double y, double z)
{
	if(dcmp(x-125) < 0 || dcmp(y-90) < 0 || dcmp(z-0.25) < 0) return 0;
	int cnt = (dcmp(x-290) > 0) + (dcmp(y-155) > 0) + (dcmp(z-7) > 0);
	if(cnt == 0) return 0;
	if(dcmp(x-380) > 0 || dcmp(y-300) > 0 || dcmp(z-50) > 0) return 0;
	return 1;
}
bool parcel(double x, double y, double z)
{
	if(dcmp(x-125) < 0 || dcmp(y-90) < 0 || dcmp(z-0.25) < 0) return 0;
	int cnt = (dcmp(x-380) > 0) + (dcmp(y-300) > 0) + (dcmp(z-50) > 0);
	if(cnt == 0) return 0;
	if(dcmp(x+y+y+z+z - 2100) > 0) return 0;
	return 1;
}

int main()
{
	while(scanf("%lf%lf%lf", &a[1], &a[2], &a[3]) == 3)
	{
		if(!dcmp(a[1]) && !dcmp(a[2]) && !dcmp(a[3])) break;
		std::sort(a+1, a+4);
		int ans = 0;
		if(letter(a[3], a[2], a[1])) ans = 1;
		else if(packet(a[3], a[2], a[1])) ans = 2;
		else if(parcel(a[3], a[2], a[1])) ans = 3;
		if(!ans) puts("not mailable");
		else if(ans == 1) puts("letter");
		else if(ans == 2) puts("packet");
		else if(ans == 3) puts("parcel");
	}
	return 0;
}
