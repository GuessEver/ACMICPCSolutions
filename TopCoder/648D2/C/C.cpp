#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ABC {
public:
	string createString(int, int);
};

char f[40][40][40][1000];
   //f[i] [a] [b] [value]   // c = i - a - b

string ABC::createString(int N, int K) {
	f[1][1][0][0] = 'A';
	f[1][0][1][0] = 'B';
	f[1][0][0][0] = 'C';
	for(int i = 1; i < N; i++)
		for(int a = 0; a <= i; a++)
			for(int b = 0; b <= i; b++) if(a + b <= i)
				for(int p = 0; p <= i*i/2+10; p++)
				{
					if(!f[i][a][b][p]) continue;
					f[i+1][a+1][b][p] = 'A';
					f[i+1][a][b+1][p+a] = 'B';
					f[i+1][a][b][p+a+b] = 'C';
				}
	for(int a = 0; a <= N; a++)
		for(int b = 0; b <= N; b++)
			if(f[N][a][b][K])
			{
				string ans(N, ' ');
				for(int i = 0; i < N; i++)
				{
					ans[N-i-1] = f[N-i][a][b][K];
					if(ans[N-i-1] == 'A') a--;
					if(ans[N-i-1] == 'B')
					{
						b--;
						K -= a;
					}
					if(ans[N-i-1] == 'C') K -= a + b;
				}
				return ans;
			}
	return "";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
