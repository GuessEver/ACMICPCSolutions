#include<cstdio>
#include<cstring>
#define MAXN 300
//#include<iostream>
//using namespace std;
bool color[MAXN];
int main() {
	int count = 0, v_sum = 0, sum = 0, c_sum = 0;
	char tmp, last = '\0';
	memset(color, false, sizeof(color));
	while (scanf("%c", &tmp) != EOF) {
		if (tmp == '?') {
			sum++;
		}
		else {
			color[tmp] = true;
			if (tmp != last) { count += sum; sum = 0; } else { v_sum += sum; sum = 0; }
			last = tmp;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) {
		if (color[i]) c_sum++;
	}
	count += sum;
	//printf("%d %d\n", count, v_sum);
	bool win = false;
	if (count == 0) { if (c_sum%2 == 0) printf("No"); else printf("Yes"); return 0;}
	if (count == 1) { printf("Yes");return 0;}
	if (count%2 != 0) win = true; //printf("No"); else printf("Yes");
	if (v_sum%2 == 1) win = !win;
	if (win) printf("Yes"); else printf("No");
	//printf("%d %d\n", count, v_sum);
	return 0;
}
