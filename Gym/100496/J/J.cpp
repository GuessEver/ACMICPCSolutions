/**************************************************
  >FileName: Jj.cpp
  >Author: dnvtmf
  >Created Time: Fri 24 Jul 2015 10:42:27 PM CST
 **************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#define INF 1000000007
using namespace std;
typedef long long LL;
const int NUM=100010;
int m,n;
char s[33][33];
struct Point{
	int x, y;
	Point(){}
	Point(int xx, int yy){x = xx, y = yy;}
	Point operator - (const Point &b)const {return Point(x - b.x, y - b.y);}
	int operator * (const Point &b)const {return x * b.y - y * b.x;}
};
int shoot[33][33][33][33];
vector<Point> emy;
vector<Point>::iterator it, jt;
bool seg_seg(Point &a, Point &b, Point &c, Point &d)
{
	return max(a.x, b.x) >= min(c.x, d.x) &&
		max(c.x, d.x) >= min(a.x, b.x) &&
		max(a.y, b.y) >= min(c.y, d.y) &&
		max(c.y, d.y) >= min(a.y, d.y) &&
		((c - b)*(a - b)) * ((d - b)*(a-b)) <= 0 &&
		((a - d)*(c - d)) * ((b - d)*(c - d)) <= 0;
}
void deal(int x, int y)
{
	Point a, b, c, d, e, f;
	for(it = emy.begin(); it != emy.end(); it++)
		for(jt = it; jt != emy.end(); jt++)
		{
			a = Point(it->x * 2 + 1, it->y * 2 + 1);
			b = Point(jt->x * 2 + 1, jt->y * 2 + 1);
			c = Point(x + x, y + y);
			d = Point(x + x + 2, y + y);
			e = Point(x + x, y + y + 2);
			f = Point(x + x + 2, y + y + 2);
			if(shoot[it->x][it->y][jt->x][jt->y] || seg_seg(a, b, c, d) || seg_seg(a, b, d, f)
					|| seg_seg(a, b, f, e) || seg_seg(a, b, c, e))
				shoot[it->x][it->y][jt->x][jt->y] = shoot[jt->x][jt->y][it->x][it->y] = 1;
		}
}
bool solve(Point a, Point b)
{
	int x, y;
	for(x = a.x, y = a.y; x >= 0 && s[x][y] == '.'; x--)
		if(shoot[x][y][b.x][b.y])
			return true;
	for(x = a.x, y = a.y; y >= 0 && s[x][y] == '.'; y--)
		if(shoot[x][y][b.x][b.y])
			return true;
	for(x = a.x, y = a.y; x < n && s[x][y] == '.'; x++)
		if(shoot[x][y][b.x][b.y])
			return true;
	for(x = a.x, y = a.y; y < m && s[x][y] == '.'; y++)
		if(shoot[x][y][b.x][b.y])
			return true;
	return false;
}
int main(){
	freopen("jealous.in", "r", stdin);
	freopen("jealous.out", "w", stdout);
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%s", s[i]);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(s[i][j] == '.')
				emy.push_back(Point(i, j));
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(s[i][j] == '#')
				deal(i, j);
	/*for(i = 0; i < n; i++)
	  for(j = 0; j < m;j++)
	  for(int x = 0; x < n; x++)
	  for(int y = 0; y < m; y++)
	  if(shoot[i][j][x][y])
	  printf("(%d,%d), (%d,%d)\n", i, j, x, y);*/
	bool f;
	vector<Point> ans;
	for(it = emy.begin(); it != emy.end(); it++)
	{
		f = true;
		for(jt = emy.begin();f && jt != emy.end(); jt++)
			if(it != jt)
			{
				f = solve(*it, *jt);
				//			if(!f && it->x == 1 && it->y == 1)
				//				cout << jt->x << ' '<< jt->y << endl;
			}
		if(f)
			ans.push_back(*it);
	}
	printf("%d\n", (int)ans.size());
	for(i = 0; i < (int)ans.size(); i++)
		printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
	return 0;
}
