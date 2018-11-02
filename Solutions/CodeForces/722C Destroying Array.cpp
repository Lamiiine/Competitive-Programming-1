#include<bits/stdc++.h>
#define MAX 100100
#define OO 50000000000000LL
#define left(s) ((s) << 1)
#define right(s) (left(s) + 1)
#define avg(a, b) (((a) + (b)) >> 1)
using namespace std;
typedef long long int ll;
int n;
ll arr[MAX];
ll sum[MAX * 4], m_sum[MAX * 4], l_sum[MAX * 4], r_sum[MAX * 4];
inline void read(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
}
inline void build(const int p, const int l, const int r)
{
	if (l == r)
		sum[p] = arr[l];
	else
	{
		build(left(p), l, avg(l, r));
		build(right(p), avg(l, r) + 1, r);
		sum[p] = sum[left(p)] + sum[right(p)];
	}
}
int i;
inline void update(const int p, const int l, const int r)
{
	if (l > i || r < i) return;
	// it's inside!
	if (l == r)
	{
		sum[p] = -OO;
		m_sum[p] = l_sum[p] = r_sum[p] = 0LL;
		return;
	}
	update(left(p), l, avg(l, r));
	update(right(p), avg(l, r) + 1, r);
	const int L = left(p), R = right(p);
	sum[p] = sum[L] + sum[R];
	l_sum[p] = max(l_sum[L], sum[L] + l_sum[R]);
	r_sum[p] = max(r_sum[R], sum[R] + r_sum[L]);
	m_sum[p] = max(max(m_sum[L], m_sum[R]), l_sum[R] + r_sum[L]);
}
int order[MAX];
int main(void)
{
	read();
	build(1, 0, n - 1);
	memcpy(m_sum, sum, sizeof sum);
	memcpy(l_sum, sum, sizeof sum);
	memcpy(r_sum, sum, sizeof sum);
	for (int j = 0; j < n; ++j)
	{
		scanf("%d", &i);
		--i;
		update(1, 0, n - 1);
		cout << m_sum[1] << '\n';
	}
	return 0;
}

