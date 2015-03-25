#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define MAXK 1000000
using namespace std;
bool ischen[MAXK+5], vis[27];
int first[MAXK+5];
string status;
const string chen = "Captain_Chen";
int main() {
	ios_base::sync_with_stdio(false); memset(vis, false, sizeof(vis));
	int n, m, k, id, pos; string name;
	cin >> n >> m >> k;
	vector<int> num; int ans = 0;
	for (int i = 0; i < k; i++) {
		cin >> name;
		//cout << "###" << name << endl;
		if (name == chen) {
			ischen[i] = true;
		} else {
			ischen[i] = false;
		}
		if (i == k-1) {
			continue;
		}
		cin >> status;
		//cout << "&&&" << status << endl;
		if (status[2] == 'W') {
			continue;
		}
		id = status[0]-'A';
		if (!vis[id]) {
            		num.push_back(id);
			vis[id] = true;
			first[id] = i;
			if (ischen[i]) {
				ans++;
			}
		}
		//if (ischen[i]) {
		//	ans++;
		//}
	}
	int size = num.size(); int tmp_ans;
	for (int i = 0; i < size; i++) {
		tmp_ans = 0;
		for (int j = 0; j < i; j++) {
			id = num[j];
			pos = first[id];
			if (ischen[pos]) {
				tmp_ans++;
			}
		}
		for (int j = i; j < size; j++) {
			id = num[j];
			pos = first[id];
			if (ischen[pos+1]) {
				tmp_ans++;
			}
		}
		ans = max(ans, tmp_ans);
	}
	cout << ans << endl;
}

