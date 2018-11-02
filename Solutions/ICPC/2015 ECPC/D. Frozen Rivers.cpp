#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#define MAX 100005

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
int head[MAX];	// isLeaf[i] is equivalent to (head[i] == -1)
int to[MAX];
int nxt[MAX];
int cost[MAX];
int n;
long long reach[MAX];		// should be long long not int
int reachCount;
void run(){	// This procedure fills the array int reach[]	// all leaves reachable and their reaching time
	reachCount = 0;
	queue<lli> q;
	q.push(lli(0, 1));	// reaching time & vertex
	int v;
	long long t;		// should use long long here as well
	int index;
	ii children[MAX];
	int childrenCount;
	while (!q.empty()){
		t = q.front().first;
		v = q.front().second;
		q.pop();
		int minCost = INT_MAX;
		if ((index = head[v]) == -1) reach[reachCount++] = t;	// The inner brackets are necessary
		else {
			childrenCount = 0;
			while (index != -1){
				minCost = min(minCost, cost[index]);
				children[childrenCount++] = ii(cost[index], to[index]);
				index = nxt[index];
			}
			for (int i = 0; i < childrenCount; ++i)
				q.push(lli(ll(ll(children[i].first - minCost) << 1) + ll(minCost) + t, children[i].second));	// and here as well
		}
	}
	sort(reach, reach + reachCount);
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int x, y;
	int q;
	while (TC--){
		memset(head, 0xFF, sizeof head);
		scanf("%d", &n);
		int en = 0;
		for (int i = 2; i <= n; ++i){
			scanf("%d%d", &x, &y);	// parent and cost
			nxt[en] = head[x];
			head[x] = en;
			to[en] = i;
			cost[en++] = y;	// don't forget to increment en
		}
		run();
		long long time;
		scanf("%d", &q);
		while (q--){
			cin >> time;
			printf("%d\n", upper_bound(reach, reach+reachCount, time)-reach);
		}
	}
	return 0;
}
