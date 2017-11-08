#include<stdio.h>
#include<queue>
#include<string.h>
#define H 42
#define W 12
using namespace std;
char s[H][W];
int h, w;
struct node{
	int x;
	int y;
};
inline bool operator == (const node & u, const node & v){
	return u.x == v.x && u.y == v.y;
}
node p[H][W];
node match[H][W];
void aug(node v){
	node u;
	for(;v.x != -1;v = p[u.x][u.y]){
		u = p[v.x][v.y];
		match[u.x][u.y] = v;
		match[v.x][v.y] = u;
	}
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &h, &w);
		for (int i = 0; i < h; ++i)
			scanf("%s", s[i]);
		bool flag = true;
		memset(match, 0xFF, sizeof match);
		memset(p, 0xFF, sizeof p);
		while(flag){
			flag = false;
			for (int i = 0; i < h; ++i)
				for (int j = 0; j < w; ++j){
					if (s[i][j] != '*' || match[i][j].x != -1) continue;
					// try to match it
					queue<node>q;
					q.push(node{i, j});
					while(!q.empty()){
						node v = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k){
							int i = v.x + dx[k];
							int j = v.y + dy[k];
							if (i < 0 || i >= h || j < 0 || j >= w || s[i][j] != '*') continue;
							// your neighbor is u
							node u = node{i, j};
							node w = match[u.x][u.y];
							if (w == v) continue;
							if (w.x == -1){
								// found a free neighbor
								flag = true;
								p[u.x][u.y] = v;
								aug(u);
								while(!q.empty()) q.pop();
								memset(p, 0xFF, sizeof p);
								break;
							}
							// YOU WROTE '!=' INSTEAD OF '=='
							else if (p[u.x][u.y].x == -1){
								p[u.x][u.y] = v;
								p[w.x][w.y] = u;
								q.push(w);
							}
						}
					}
				}
		}
		int counter = 0, m_size = 0;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (s[i][j] == '*') ++counter, m_size += (match[i][j].x != -1);
		printf("%d\n", counter - (m_size >> 1));
	}
	return 0;
}

