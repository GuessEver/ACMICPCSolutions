#include <cstdio>
#include <cstring>

char A[10][1000];

bool check(int x)
{
	int lenx = strlen(A[x]);
	bool flag1 = 1, flag2 = 1;
	for(int i = 1; i <= 4; i++) if(i != x)
	{
		int leni = strlen(A[i]);
		if(!(2 * lenx <= leni)) flag1 = 0;
	}
	for(int i = 1; i <= 4; i++) if(i != x)
	{
		int leni = strlen(A[i]);
		if(!(lenx >= leni * 2)) flag2 = 0;
	}
	return flag1 || flag2;
}

int main()
{
	//freopen("A.in", "r", stdin);
	scanf("A.%s\n", A[1]);
	scanf("B.%s\n", A[2]);
	scanf("C.%s\n", A[3]);
	scanf("D.%s\n", A[4]);
	//puts(A[1]); puts(A[2]); puts(A[3]); puts(A[4]);
	int k = -1;
	for(int i = 1; i <= 4; i++)
		if(check(i))
		{
			if(k == -1) k = i;
			else{
				puts("C");
				return 0;
			}
		}
	if(k == -1) puts("C");
	else printf("%c\n", 'A' + k - 1);
	return 0;
}
