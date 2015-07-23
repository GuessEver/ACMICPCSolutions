#line 2 "ABBADiv1.cpp"
#include<bits/stdc++.h>
using namespace std;
class ABBADiv1 { 
	string A, B;
	int n, m;

	bool check(int l, int r, int tar_dir) // A[0, n-1] => B[l, r]
	{
		for(int i = l, j = 0; i <= r; i++, j++)
			if(A[j] != B[i]) return 0;
		string s = A;
		int dir = 1; // -1 || 1
		while(1)
		{
			if(dir == 1)
			{
				if(r >= m) break;
				for(r += 1; r < m; r++)
				{
					s = s + B[r];
					if(B[r] == 'B')
					{
						dir = -1;
						break;
					}
				}
			}
			else {
				if(l < 0) break;
				for(l -= 1; l >= 0; l--)
				{
					s = B[l] + s;
					if(B[l] == 'B')
					{
						dir = 1;
						break;
					}
				}
			}
		}
		return s == B && dir == tar_dir;
	}

	public: 
	string canObtain(string initial, string target) { 
		A = initial; B = target;
		n = A.length(); m = target.length();
		for(int i = 0; i + n - 1 < m; i++)
			if(check(i, i+n-1, 1)) return "Possible";
		reverse(B.begin(), B.end());
		for(int i = 0; i + n - 1 < m; i++)
			if(check(i, i+n-1, -1)) return "Possible";
		return "Impossible";
	} 

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arg1 = "BABA"; string Arg2 = "Possible"; verify_case(0, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BAAAAABAA"; string Arg1 = "BAABAAAAAB"; string Arg2 = "Possible"; verify_case(1, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "A"; string Arg1 = "ABBA"; string Arg2 = "Impossible"; verify_case(2, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAABBAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Possible"; verify_case(3, Arg2, canObtain(Arg0, Arg1)); }
	//void test_case_4() { string Arg0 = "AAABAAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "BB"; string Arg1 = "ABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }

	// END CUT HERE

}; 
// BEGIN CUT HERE
int main()
{
	ABBADiv1 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
