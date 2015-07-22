#include <cstdio>
#include <cstring>

const int N = 200000 + 10;

int n;
char A[N], B[N];

bool check(int Al, int Ar, int Bl, int Br)
{
	if(Al == Ar) return A[Al] == B[Bl];
	int len = (Ar - Al + 1);
	if(len % 2 != 0)
	{
		for(int i = Al, j = Bl; i <= Ar; i++, j++)
			if(A[i] != B[j]) return 0;
		return 1;
	}
	else {
		len /= 2;
		// [Al, Al+len-1] U [Al+len, Ar]
		if((check(Al, Al+len-1, Bl, Bl+len-1) && check(Al+len, Ar, Bl+len, Br))
					|| (check(Al, Al+len-1, Bl+len, Br) && check(Al+len, Ar, Bl, Bl+len-1))) return 1;
		return 0;
	}
}

int main()
{
	scanf("%s", A);
	scanf("%s", B);
	n = strlen(A);
	if(check(0, n - 1, 0, n - 1)) puts("YES"); else puts("NO");
	return 0;
}
