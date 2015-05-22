#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using std::queue;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int fac[20];
struct Node{
	int a[9], steps, hash;
	bool Read()
	{
		char chtmp;
		if(scanf(" %c", &chtmp) != 1) return 0;
		a[0] = chtmp == 'x' ? 0 : chtmp - '0';
		for(int i = 1; i < 9; i++)
		{
			scanf(" %c", &chtmp);
			a[i] = chtmp == 'x' ? 0 : chtmp - '0';
		}
		//for(int i = 0; i < 9; i++) printf("%d", a[i]); puts("");
		return 1;
	}
	void getHash()
	{
		hash = 0;
		for(int i = 0; i < 9; i++)
		{
			int cnt = 0;
			for(int j = i + 1; j < 9; j++)
				if(a[j] < a[i]) cnt++;
			hash += cnt * fac[9 - i - 1];
		}
	}
}S, T;
queue<Node> Q;
bool inQ[3628800];
int calc[3628800];

bool expand(Node &newnd, Node &now, int k)
{
	newnd = now; newnd.steps++;
	int b[3][3], x, y;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			b[i][j] = newnd.a[i * 3 + j];
			if(b[i][j] == 0) { x = i; y = j; }
		}
	int nx = x + dx[k], ny = y + dy[k];
	if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) return 0;
	std::swap(b[x][y], b[nx][ny]);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			newnd.a[i*3+j] = b[i][j];
	newnd.getHash();
	return 1;
}

int BFS()
{
	while(!Q.empty()) Q.pop();
	Q.push(S); inQ[S.hash] = 1;
	while(!Q.empty())
	{
		Node newnd, now = Q.front(); Q.pop();
		if(calc[now.hash] == -1) calc[now.hash] = now.steps;
		if(now.hash == T.hash) return now.steps;
		for(int k = 0; k < 4; k++)
		{
			if(!expand(newnd, now, k)) continue;
			if(!inQ[newnd.hash])
			{
				inQ[newnd.hash] = 1;
				Q.push(newnd);
			}
		}
	}
	return -2;
}

int main()
{
	fac[0] = 1;
	for(int i = 1; i < 12; i++) fac[i] = fac[i-1] * i;
	for(int i = 0; i < 8; i++) S.a[i] = i + 1;
	S.a[8] = 0; S.getHash(); S.steps = 0;
	memset(calc, -1, sizeof(calc));
	while(T.Read())
	{
		T.getHash(); T.steps = 0;
		memset(inQ, 0, sizeof(inQ));
		if(calc[T.hash] == -1) calc[T.hash] = BFS();
		if(calc[T.hash] == -2) puts("unsolvable");
		else printf("%d\n", calc[T.hash]);
	}
	return 0;
}
