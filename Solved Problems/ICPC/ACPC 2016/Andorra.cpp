#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// count the number of tours are available in between s and e (exclusive)
ll interval(const ll s, const ll e)
{
	/* if you have an interval of length n, then the number of possible
	 * tours in this interval is 1 + 2 + ... + n = n * (n + 1) / 2
	 * Thus, if your boundaries are s and e, then this interval has
	 * a length of s - e - 1, so you have (s - e - 1) * (s - e - 1 + 1) / 2 tours
	 *
	 * Why is the number of tours in an interval of length n equal to 1 + 2 + ... + n?
	 * To see why, observe that if you start at 1, you have n options to stop at
	 * (namely, 1-1, 1-2, 1-3, ..., 1-n)
	 * If you start at 2, you have n-1 options to stop at
	 * (namely, 2-2, 2-3, ...., 2-n)
	 * and so on
	 * In total, you have n + n - 1 + ... + 1 possible tours
	 */
	return ((e - s - 1LL) * (e - s)) >> 1LL;
}

set<ll> s;				// indices that new investors can not step on
map<ll, vector<ll> > m;	// map from type to indeces of its occurences in the array
set<ll> vis;			// store types that have already been visited
int n, q;				// number of houses and investors respectively

void read()
{
	vector<ll> t;
	scanf("%d%d", &n, &q);
	for (int i = 0, a; i < n; ++i)
		scanf("%d", &a), m.insert(make_pair(ll(a), t)).first->second.push_back(i);
}
void init()
{
	vis.clear();
	s.clear();
	m.clear();
}
void solve()
{
	/*
	 * s stores the indices that new investors can not step on
	 */
	s.insert(-1); s.insert(n);
	/*
	 * x will store the number of tours available to the investor coming
	 * y will store the number of tours available after this investor is gone
	 * that's why it is initialized to the total number of possible tours
	 */
	ll x = 0LL, y = interval(-1, n);
	for (int t; q--; )
	{
		x = 0LL;
		scanf("%d", &t);
		map<ll, vector<ll> >::iterator v;
		if (
				(v = m.find(t)) != m.end()	// this means no houses for type t are found
				&& vis.insert(t).second		// this means vis does not already contains t
			)
		/* loop over all occurences of this type
		 * and for each occurence, count the number of possible
		 * tours that pass by this occurence
		 */
		for (vector<ll>::iterator occurence = v->second.begin(); occurence != v->second.end(); ++occurence)
		{
			set<ll>::iterator mid = s.insert(*occurence).first;
			set<ll>::iterator left = mid;
			set<ll>::iterator right = mid;
			--left;
			++right;
			y -= interval(*left, *right);
			y += interval(*left, *mid);
			y += interval(*mid, *right);
			x += (*mid - *left) * (*right - *mid);
		}

		printf("%lld %lld\n", x, y);
	}
}
int main()
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		solve();
	}
	return 0;
}
/*
1
2 2
1 2
1 2

1
9 3
1 2 3 1 2 3 4 5 6
1
 */

