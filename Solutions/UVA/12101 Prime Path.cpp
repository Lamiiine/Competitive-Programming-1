#include<bits/stdc++.h>
#define MAX 10000
#define OO 10000000
using namespace std;
bitset<MAX> bs;
int dist[MAX];
inline void sieve(void)
{
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i < MAX; ++i)
		if (bs[i])
			for (int j = i * i; j < MAX; j += i)
				bs[j] = 0;
}
int s, t;
inline int bfs(void)
{
	for (int i = 0; i < MAX; ++i)
		dist[i] = OO;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		const int i = q.front();
		q.pop();
		for (int j = 1; j <= 1000; j *= 10)
			for (int d = (j == 1000 ? 1 : 0); d < 10; ++d)
			{
				const int t = i - (i % (j * 10))  + (i % j) + d * j;
				if (bs[t] && dist[t] == OO)
				{
					dist[t] = dist[i] + 1;
					q.push(t);
				}
			}
	}

	return dist[t];
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	sieve();
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &s, &t);
		bfs();
		if (dist[t] == OO) printf("Impossible");
		else printf("%d", dist[t]);
		printf("\n");
	}
	return 0;
}

