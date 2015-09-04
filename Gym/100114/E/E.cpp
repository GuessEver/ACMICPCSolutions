#include <cstdio>
#define DIV(x) (x / 10)
#define MOD(x) (x > 10 ? x - 10 : x)
#define TYPE int
int num[20], cnt[20];
TYPE a[10][10];
int ans[10];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int sum = 0;
	for(TYPE i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}
	if(sum == 31)
	for(TYPE x1 = 0; x1 < 10; ++x1)
		for(TYPE x5 = 0; x5 < 10 && x5 * x1 < 10; ++x5)
			for(TYPE x8 = 0; x8 < 10 && x8 * x1 < 10; ++x8)
				for(TYPE x7 = 0; x7 < 10 && x7 * x1 < 10; ++x7)
					for(TYPE x6 = 0; x6 < 10 && x6 * x1 < 10; ++x6)
						for(TYPE x2 = 0; x2 < 10; ++x2)
							for(TYPE x3 = 0; x3 < 10; ++x3)
								for(TYPE x4 = 0; x4 < 10; ++x4)
								{
									a[1][1] = x8 * x4;
									a[1][2] = x8 * x3 + DIV(a[1][1]);
									a[1][1] = MOD(a[1][1]);
									a[1][3] = x8 * x2 + DIV(a[1][2]);
									a[1][2] = MOD(a[1][2]);
									a[1][4] = x8 * x1 + DIV(a[1][3]);
									a[1][3] = MOD(a[1][3]);
									if(a[1][4] >= 10) continue;
									a[2][1] = x7 * x4;
									a[2][2] = x7 * x3 + DIV(a[2][1]);
									a[2][1] = MOD(a[2][1]);
									a[2][3] = x7 * x2 + DIV(a[2][2]);
									a[2][2] = MOD(a[2][2]);
									a[2][4] = x7 * x1 + DIV(a[2][3]);
									a[2][3] = MOD(a[2][3]);
									if(a[2][4] >= 10) continue;
									a[3][1] = x6 * x4;
									a[3][2] = x6 * x3 + DIV(a[3][1]);
									a[3][1] = MOD(a[3][1]);
									a[3][3] = x6 * x2 + DIV(a[3][2]);
									a[3][2] = MOD(a[3][2]);
									a[3][4] = x6 * x1 + DIV(a[3][3]);
									a[3][3] = MOD(a[3][3]);
									if(a[3][4] >= 10) continue;
									a[4][1] = x5 * x4;
									a[4][2] = x5 * x3 + DIV(a[4][1]);
									a[4][1] = MOD(a[4][1]);
									a[4][3] = x5 * x2 + DIV(a[4][2]);
									a[4][2] = MOD(a[4][2]);
									a[4][4] = x5 * x1 + DIV(a[4][3]);
									a[4][3] = MOD(a[4][3]);
									if(a[4][4] >= 10) continue;
									ans[1] = a[1][1];
									ans[2] = a[1][2] + a[2][1];
									ans[3] = a[1][3] + a[2][2] + a[3][1] + DIV(ans[2]);
									ans[2] = MOD(ans[2]);
									ans[4] = a[1][4] + a[2][3] + a[3][2] + a[4][1] + DIV(ans[3]);
									ans[3] = MOD(ans[3]);
									ans[5] = a[2][4] + a[3][3] + a[4][2] + DIV(ans[4]);
									ans[4] = MOD(ans[4]);
									ans[6] = a[3][4] + a[4][3] + DIV(ans[5]);
									ans[5] = MOD(ans[5]);
									ans[7] = a[4][4] + DIV(ans[6]);
									ans[6] = MOD(ans[6]);
									if(ans[7] >= 10) continue;
									for(TYPE i = 0; i < 10; ++i) cnt[i] = 0;
									for(TYPE i = 1; i <= 7; ++i) ++cnt[ans[i]];
									for(TYPE i = 1; i <= 4; ++i)
										for(TYPE j = 1; j <= 4; ++j)
											++cnt[a[i][j]];
									++cnt[x1]; ++cnt[x2]; ++cnt[x3]; ++cnt[x4];
									++cnt[x5]; ++cnt[x6]; ++cnt[x7]; ++cnt[x8];
									bool flag = 0;
									for(TYPE i = 0; i < 10; ++i)
										if(cnt[i] != num[i]) {flag = 1; break;}
									if(flag) continue;
									printf("%d\n", x1 * 1000 + x2 * 100 + x3 * 10 + x4);
									printf("%d\n", x5 * 1000 + x6 * 100 + x7 * 10 + x8);
									return 0;
								}
	puts("-1\n-1");
	return 0;
}
