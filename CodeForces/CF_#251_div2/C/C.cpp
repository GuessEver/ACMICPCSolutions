#include <cstdio>

const int N = 100000 + 10;

int n, k, p, Odd[N], O, Even[N], E;
int idxo, idxe;

bool check()
{
	if((O - (k - p)) >= 0 && (O - (k - p)) % 2 == 0);
	else return 0;
	int tmp = (O - (k - p)) / 2 + E;
	if(tmp < p) return 0;
	return 1;
}

void PrintEven()
{
	if(idxe < E) printf("1 %d\n", Even[idxe++]);
	else {
		printf("2 %d %d\n", Odd[idxo], Odd[idxo+1]);
		idxo += 2;
	}
}
void PrintOdd()
{
	printf("1 %d\n", Odd[idxo++]);
}

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		if(x & 1) Odd[O++] = x;
		else Even[E++] = x;
	}
	if(!check()) { puts("NO"); return 0; }
	puts("YES");
	for(int i = 1; i < p; i++) // p - 1   even
		PrintEven();
	for(int i = 1; i < k - p; i++)
		PrintOdd();
	if(p != 0 && k - p != 0)
		PrintEven();
	printf("%d", O - idxo + E - idxe);
	for(int i = idxo; i < O; i++) printf(" %d", Odd[i]);
	for(int i = idxe; i < E; i++) printf(" %d", Even[i]);
	return 0;
}
