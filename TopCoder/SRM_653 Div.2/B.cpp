#include<bits/stdc++.h>
using namespace std;

class RockPaperScissorsMagicEasy {
public:
	int count(vector <int>, int);
};

int c[3000][3000];

int RockPaperScissorsMagicEasy::count(vector <int> card, int score) {
	int n = card.size();
	int mod = 1000000007;
	if(score > n) return 0;
	for(int i = 0; i <= 2000; i++) c[i][0] = 1;
	for(int i = 1; i <= 2000; i++)
		for(int j = 1; j <= 2000; j++)
			c[i][j] = (0ll + c[i-1][j-1] + c[i-1][j]) % mod;
	int res = c[n][score] % mod;
	for(int i = 1; i <= n - score; i++) res = 1ll * res * 2 % mod;
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

