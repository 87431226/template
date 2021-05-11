#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val, d;
	int ch[2];
}a[100005];
int fa[100005];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int& rs(int x) {return a[x].ch[a[a[x].ch[1]].d < a[a[x].ch[0]].d];}

int merge(int x, int y)
{
	if (!x || !y) return x | y;
	if (a[x].val < a[y].val) swap(x, y);
	rs(x) = merge(rs(x), y);
	a[x].d = a[rs(x)].d + 1;
	fa[a[x].ch[0]] = fa[a[x].ch[1]] = x;
	return x;
}
int del(int x)
{
	int ls = a[x].ch[0], rs = a[x].ch[1];
	fa[ls] = ls, fa[rs] = rs;
	a[x].ch[0] = a[x].ch[1] = 0;
	return merge(ls, rs);
}
int main()
{
	int n, m;
	while (cin >> n)
	{ 
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].val;
			fa[i] = i;
			a[i].d = a[i].ch[0] = a[i].ch[1] = 0;
		}
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			cin >> x >> y;
			int xx = find(x), yy = find(y);
			if (xx == yy)
			{
				cout << -1 << endl;
				continue;
			}
			a[xx].val /= 2, a[yy].val /= 2;
			int newx = del(xx), newy = del(yy);
			newx = merge(xx, newx);
			newy = merge(yy, newy);
			int root = merge(newx, newy);
			cout << a[root].val << endl;
		}
	}
}