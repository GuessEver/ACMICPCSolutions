#include <cstdio>
#include <cctype>

int cnt['z'+10];
int n;

int main()
{
	scanf("%d", &n);
	int res = 0;
	for(int i = 1; i < n; i++)
	{
		char room, key;
		scanf(" %c%c", &room, &key);
		key = tolower(key);
		cnt[room]++;
		if(cnt[key]) cnt[key]--;
		else res++;
	}
	printf("%d\n", res);
	return 0;
}
