#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

struct BigInt{
	int c[1000], len;
	BigInt() { memset(c, 0, sizeof(c)); len = 0; }
	void Zero()
	{
		while(len > 1 && c[len] == 0) len--;
	}
	void Read()
	{
		char t[1000] = {0};
		scanf("%s", t);
		len = strlen(t);
		for(int i = len - 1, cnt = 0; i >= 0; i--)
			c[++cnt] = t[i] - '0';
		Zero();
	}
	void Print()
	{
		for(int i = len; i > 0; i--) printf("%d", c[i]);
		printf("\n");
	}
	BigInt operator + (BigInt r)
	{
		int L = len = max(len, r.len) + 1;
		for(int i = 1; i <= L; i++)
		{
			c[i] += r.c[i];
			c[i+1] += c[i] / 10;
			c[i] %= 10;
		}
		Zero();
		return *this;
	}
}A,B;

int main()
{
	A.Read();
	B.Read();
	//A.Print();
	//B.Print();
	(A+B).Print();
	return 0;
}
