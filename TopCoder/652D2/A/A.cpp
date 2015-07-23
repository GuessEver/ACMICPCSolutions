#include<bits/stdc++.h>
using namespace std;

class ValueOfString {
public:
	int findValue(string);
};

int ValueOfString::findValue(string s) {
	int len = s.length();
	int k[100], res = 0;
	for(int i = 0; i < len; i++)
	{
		k[i] = 0;
		for(int j = 0; j < len; j++) k[i] += (s[j] <= s[i]);
		res += k[i] * (s[i] - 'a' + 1);
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
