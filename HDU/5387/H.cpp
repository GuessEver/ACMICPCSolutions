#include <cstdio>

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

int hour, minute, second;
struct ANS{
	int A, B;
	ANS() {}
	ANS(int a, int b) { A = a; B = b; }
	void get()
	{
		int g = gcd(A, B);
		A /= g; B /= g;
		if(B == 1) printf("%d ", A);
		else printf("%d/%d ", A, B);
	}
	ANS operator - (const ANS &_b) const
	{
		ANS a = *this, b = _b;
		int BB = lcm(a.B, b.B);
		int k1 = BB / a.B, k2 = BB / b.B;
		a.A *= k1; a.B *= k1;
		b.A *= k2; b.B *= k2;
		return ANS(a.A - b.A, BB);
	}
}a[3];

ANS angle(ANS a, ANS b)
{
	ANS res = a - b;
	if(res.B < 0) { res.B = -res.B; res.A = -res.A; }
	while(res.A < 0) res.A = -res.A;
	while(res.A > 360 * res.B) res = res - ANS(360, 1);
	while(res.A > 180 * res.B) res = ANS(360, 1) - res;
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d:%d:%d", &hour, &minute, &second);
		a[0].A = second * 6; a[0].B = 1;
		a[1].A = minute * 6; a[1].B = 1;
		a[1] = a[1] - ANS(-second, 10);
		a[2].A = hour * 30; a[2].B = 1;
		a[2] = (a[2] - ANS(-minute, 2)) - ANS(-second, 120);
		//a[2].get(); a[1].get(); a[0].get(); puts("");
		angle(a[2], a[1]).get();
		angle(a[2], a[0]).get();
		angle(a[1], a[0]).get();
		puts("");
	}
	return 0;
}
