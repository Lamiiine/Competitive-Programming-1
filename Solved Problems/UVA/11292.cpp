#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n, m;
	int dragon[20000], knight[20000];
	int k, d;
	long long gold;	// knights and dragons counters
	while (scanf("%d%d", &n, &m), n && m){
		for (int i = 0; i < n; i++)
			scanf("%d", &dragon[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &knight[i]);
		sort(dragon, dragon + n);
		sort(knight, knight + m);
		gold = k = d = 0;
		while (d < n){
			while (knight[k] < dragon[d] && k < m) k++;
			if (k >= m) break;
			gold += knight[k];
			d++; k++;
		}
		if (d < n) printf("Loowater is doomed!\n");
		else cout << gold << '\n';
	}
	return 0;
}