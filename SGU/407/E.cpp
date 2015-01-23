#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

const int base = 10000; // 压4位

struct BigInt{
	int c[10000], len, sign;
	BigInt() { memset(c, 0, sizeof(c)); len = 1; sign = 0; }
	void Zero() 
	{
		while(len > 1 && c[len] == 0) len--; 
		if(len == 1 && c[len] == 0) sign = 0;
	}
	void writein(char *s)
	{
		int k = 1, L = strlen(s);
		for(int i = L-1; i >= 0; i--)
		{
			c[len] += (s[i]-'0') * k;
			k *= 10;
			if(k == base)
			{
				k = 1;
				len++;
			}
		}

	}
	void Read()
	{
		char s[5000] = {0};
		scanf("%s", s);
		writein(s);
	}
	void Print()
	{
		if(sign) printf("-");
		printf("%d", c[len]);
		for(int i = len-1; i >= 1; i--) printf("%04d", c[i]);
		printf("\n");
	}
	BigInt operator = (int a)
	{
		char s[100] = {0};
		sprintf(s, "%d", a);
		writein(s);
		return *this;
	}
	bool operator > (const BigInt &b)
	{
		if(len != b.len) return len > b.len;
		for(int i = len; i >= 1; i--)
		{
			if(c[i] != b.c[i]) return c[i] > b.c[i];
		}
		return 0;
	}
	bool operator < (const BigInt &b)
	{
		if(len != b.len) return len < b.len;
		for(int i = len; i >= 1; i--)
		{
			if(c[i] != b.c[i]) return c[i] < b.c[i];
		}
		return 0;
	}
	bool operator == (const BigInt &b)
	{
		if(len != b.len) return 0;
		for(int i = 1; i <= len; i++)
			if(c[i] != b.c[i]) return 0;
		return 1;
	}
	bool operator == (const int &a)
	{
		BigInt b; b = a;
		return *this == b;
	}
	BigInt operator + (const BigInt &b)
	{
		BigInt r; r.len = max(len, b.len) + 1;
		for(int i = 1; i <= r.len; i++)
		{
			r.c[i] += c[i] + b.c[i];
			r.c[i+1] += r.c[i] / base;
			r.c[i] %= base;
		}
		r.Zero();
		return r;
	}
	BigInt operator + (const int &a)
	{
		BigInt b; b = a;
		return *this + b;
	}
	BigInt operator - (const BigInt &b)
	{
		BigInt a, c;// a - c
		a = *this; c = b;
		if(a < c)
		{
			std::swap(a, c);
			a.sign = 1;
		}
		for(int i = 1; i <= len; i++)
		{
			a.c[i] -= c.c[i];
			if(a.c[i] < 0)
			{
				a.c[i] += base;
				a.c[i+1]--;
			}
		}
		a.Zero();
		return a;
	}
	BigInt operator - (const int &a)
	{
		BigInt b; b = a;
		return *this - b;
	}
	BigInt operator * (const BigInt &b)
	{
		BigInt r; r.len = len + b.len + 2;
		for(int i = 1; i <= len; i++)
		{
			for(int j = 1; j <= b.len; j++)
			{
				r.c[j+i-1] += c[i] * b.c[j];
			}
		}
		for(int i = 1; i <= r.len; i++)
		{
			r.c[i+1] += r.c[i] / base;
			r.c[i] %= base;
		}
		r.Zero();
		return r;
	}
	BigInt operator * (const int &a)
	{
		BigInt b; b = a;
		return *this * b;
	}
	BigInt operator / (BigInt b)//整除
	{
		BigInt t, r;
		if(b == 0) return r;
		r.len = len;
		for(int i = len; i >= 1; i--)
		{
			t = t * base + c[i];
			int div;
			//------try------
				int up = 10000, down = 0;
				while(up >= down)
				{
					int mid = (up + down) / 2;
					BigInt ccc ; ccc = b * mid;
					if(ccc > t) up = mid - 1;
					else {
						down = mid + 1;
						div = mid;
					}
				}
			//------end------
			r.c[i] = div;
			t = t - b * div;
		}
		//最后的t为余数，要用的自己想办法传出去
		r.Zero();
		return r;
	}
	BigInt operator / (const int &a)
	{
		BigInt b; b = a;
		return *this / b;
	}
	BigInt operator % (const BigInt &b)
	{//其实可以复制上面除法的，这里换一种写法
		return *this - *this / b * b;
	}
	BigInt operator % (const int &a)
	{
		BigInt b; b = a;
		return *this % b;
	}
};

BigInt f[2][2];
int n,m;
int main()
{

	//freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
    f[0][0]=1;
    int cnt=0;
	for(int i=1;i<=m;i++)
	{
	    cnt=1-cnt;
	    f[cnt][0]=f[1-cnt][1];
	    f[cnt][1]=f[1-cnt][1]*2+f[1-cnt][0]*n;
	}
    if(n==0)
        printf("1");
    else
	f[cnt][0].Print();

	return 0;
}

