#include <bits/stdc++.h>
#define OO ((long long) 1e18)
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef complex<ll> Point;
struct Tree {
	ll x, y, v, l;
};


ll sqr_len(const Point & a, const Point & b)
{
	const Point c = vec(a, b);
	return c.X * c.X + c.Y * c.Y;
}

struct cmp {
	Point pivot;
	cmp(const Point & a) : pivot(a){}
	const bool operator() (const Point & a, const Point & b)
	{
		const ll cr = cross(vec(pivot, a), vec(pivot, b));
		if (cr) return cr > 0;
		return make_pair(a.Y, a.X) < make_pair(b.Y, b.X);
	}
};

vector<Point> p;

inline void find_pivot()
{
	int ans_idx = 0;
	for (int i = 1; i < p.size(); ++i)
	{
		const Point & ans = p[ans_idx];
		const Point & cur = p[i];
		if (make_pair(cur.Y, cur.X) < make_pair(ans.Y, ans.X))
			ans_idx = i;
	}
	swap(p[0], p[ans_idx]);
}
inline ld convex_hull() {
	vector<Point> ans;
	p.push_back(p[0]);
	ans.push_back(p[0]);
	ans.push_back(p[1]);
	// for (const Point & pp : p) printf("%lld, %lld\n", pp.X, pp.Y);
	for (int i = 2; i <= p.size(); ++i)
	{
		const Point & c = p[i % p.size()];
		while (ans.size() > 1)
		{
			const Point & b = ans.back();
			const Point & a = ans[ans.size() - 2];
			// print(a);
			// print(b);
			// print(c);
			// print(vec(a, b));
			// print(vec(b, c));
			if (cross(vec(a, b), vec(b, c)) > 0)
				break;
			ans.pop_back();
		}
		ans.push_back(c);
	}
	// printf("%d\n", ans.size());
	ld required_len = 0.0;
	for (int i = 0; i < ans.size() - 1; ++i)
		required_len += sqrt(sqr_len(ans[i], ans[i + 1]));
	return required_len;
}

int main()
{
	for (int n, tc = 1; scanf("%d", &n), n; ++tc)
	{
		if (tc != 1) printf("\n");
		vector<Tree> trees;
		for (ll i = 0, x, y, v, l; i < n; ++i)
		{
			scanf("%lld%lld%lld%lld", &x, &y, &v, &l);
			trees.push_back(Tree{x, y, v, l});
		}
		ll opt_val = OO;
		ll opt_num = OO;
		vector<int> opt_ids;
		ld opt_extra_wood;
		for (int mask = 0; mask < (1 << n); ++mask)
		{
			p.clear();
			ll cur_val = 0;
			ll cur_len = 0;
			ll cur_num = 0;
			vector<int> cur_ids;
			for (int i = 0; i < n; ++i)
				if (mask & (1 << i))
					p.push_back(Point(trees[i].x, trees[i].y));
				else cur_val += trees[i].v,
						cur_len += trees[i].l,
						++cur_num,
						cur_ids.push_back(i + 1);
			ld required_len;
			if (p.size() == 0)
				required_len = OO;
			else if (p.size() == 1)
				required_len = 0;
			else if (p.size() == 2)
				required_len = 2LL * sqrt(sqr_len(p[0], p[1]));
			else if (p.size() >= 2)
			{
				find_pivot();
				sort(p.begin(), p.end(), cmp(p[0]));
				required_len = convex_hull();
			}
			const ld cur_extra_wood = cur_len - required_len;
			if (
					cur_extra_wood >= -1e-9 &&
					make_pair(cur_val, cur_num) < make_pair(opt_val, opt_num))
				opt_val = cur_val,
				opt_num = cur_num,
				opt_ids = cur_ids,
				opt_extra_wood = cur_extra_wood;
		}
		printf("Forest %d\n", tc);
		printf("Cut these trees:");
		for (const auto i : opt_ids)
			printf(" %d", i);
		printf("\n");
		printf("Extra wood: %.2llf\n", opt_extra_wood);
	}
	return 0;
}

