#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string mus[1001];
int n, m;
bool visited[1001][1001];
int visit(int xxx, int yyy){
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) visited[i][j] = false;
	stack<pair<int, int>> Q;
	Q.push(pair<int, int> (xxx, yyy));
	int count = 0;
	int x, y;
	while (!Q.empty()){
		x = Q.top().first;
		y = Q.top().second;
		Q.pop();
		if (x <= 0 || y <= 0 || x > n || y > m) continue;
		if (mus[x][y-1] == '*') { count++; continue; }
		if (visited[x][y]) continue;
		visited[x][y] = true;
		int xx[] = { x, x-1, x, x+1 };
		int yy[] = { y+1, y, y-1, y };
		Q.push(make_pair(xx[0], yy[0]));
		Q.push(make_pair(xx[1], yy[1]));
		Q.push(make_pair(xx[2], yy[2]));
		Q.push(make_pair(xx[3], yy[3]));
	}
	return count;
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		cin >> mus[i];
	}
	int x, y, num;
	k--;
	while (k--){
		scanf("%d %d\n", &x, &y);
		num = visit(x, y);
		printf("%d\n", num);
	}
	scanf("%d %d\n", &x, &y);
	num = visit(x, y);
	printf("%d\n", num);
	return 0;
}