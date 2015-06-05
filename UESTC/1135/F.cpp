#include <cstdio>

int W, B;
double f[1010][1010];

int main()
{
	scanf("%d%d", &W, &B);
	for(int b = 0; b <= B; b++) f[0][b] = 0;
	for(int w = 1; w <= W; w++) f[w][0] = 1;
	for(int w = 1; w <= W; w++)
		for(int b = 1; b <= B; b++)
		{
			f[w][b] = 1.0 * w / (w + b);
			if(b >= 3) f[w][b] += (1.0 * b / (w+b)) * (1.0 * (b-1) / (w+b-1)) * (1.0 * (b-2) / (w+b-2)) * f[w][b-3];
			if(w >= 1 && b >= 2) f[w][b] += (1.0 * b / (w+b)) * (1.0 * (b-1) / (w+b-1)) * (1.0 * w / (w+b-2)) * f[w-1][b-2];
		}
	printf("%.9f\n", f[W][B]);
	return 0;
}
