#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#define MAX 52
using namespace std;
int dist[MAX][MAX];
int main(){
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	int INF;
	memset(&INF, 0x3F, sizeof INF);
	int p, r;
	string a, b;
	map<string, int> m;
	map<int, string>M;
	int counter;
	int tc = 0;
	while (scanf("%d%d", &p, &r), p || r){
		++tc;
		memset(dist, 0x3F, sizeof dist);
		counter = 0;
		for (int i = 0; i < r; ++i){
			cin >> a >> b;
			if (m.find(a) == m.end()) m[a] = counter, M[counter] = a, ++counter;
			if (m.find(b) == m.end()) m[b] = counter, M[counter] = b, ++counter;
			dist[m[a]][m[b]] = dist[m[b]][m[a]] = 1;
		}
		for (int k = 0; k < p; ++k) dist[k][k] = 0;

		for (int k = 0; k < p; ++k)
		for (int i = 0; i < p; ++i)
		for (int j = 0; j < p; ++j)
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int ans = 0;
		for (int i = 0; i < p; ++i)
		for (int j = i+1; j < p; ++j)
			ans = max(ans, dist[i][j]);
		printf("Network %d: ", tc);
		if (ans == INF) printf("DISCONNECTED\n\n");
		else printf("%d\n\n", ans);
		m.clear();
		M.clear();
	}
	return 0;
}