#include<bits/stdc++.h>
using namespace std;
typedef complex<int> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define polar(r, t) ((r)*exp(point(0, t)))
#define angle(v) (atan2((v).Y, (v).X))
#define lengthSqr(v) (dot(v, v))
#define dot(v, u) (v.X*u.X + v.Y*u.Y)
#define cross(v, u) (v.X*u.Y - v.Y*u.X)
#define rotate(v, t) (polar(v, t))
#define rotate_about(v, a, t) (rotate(vec(a, v), t) + a)
using namespace std;
int n;
vector<point>p;
inline void read(void){
	p.clear();
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; ++i){
		scanf("%d%d", &x, &y);
		p.push_back(point(x, y));
	}
	p.pop_back(); --n;
}
struct cmp{
	point pivot;
	cmp(point a):pivot(a){}
	inline const bool operator ()(const point & a, const point & b){
		int cr = cross(vec(pivot, a), vec(pivot, b));
		if (cr) return cr > 0;
		return make_pair(a.Y, a.X) < make_pair(b.Y, b.X);
	}
};
inline void find_pivot(void){
	point ans = p[0], tmp;
	int ans_index = 0;
	for (int i = 1; i < n; ++i){
		tmp = p[i];
		if (make_pair(tmp.Y, tmp.X) < make_pair(ans.Y, ans.X))
			ans = tmp, ans_index = i;
	}
	swap(p[0], p[ans_index]);
}
inline vector<point> convex_hull(void){
	vector<point>ans;
	ans.push_back(p[0]);
	if (p.size() == 1)
		return ans;
	ans.push_back(p[1]);
	if (p.size() == 2){
		if (ans[1] == ans[0])
			ans.pop_back();
		return ans;
	}
	for (int i = 2; i <= p.size(); ++i){
		const point c = p[i % p.size()];
		while(ans.size() > 1){
			point b = ans.back();
			point a = ans[ans.size() - 2];
			if (cross(vec(a, b), vec(b, c)) > 0)
				break;
			ans.pop_back();
		}
		ans.push_back(c);
	}
	return ans;
}
int main(void){
	int TC; scanf("%d", &TC);
	printf("%d\n", TC);
	for (int tc = 1; tc <= TC; ++tc){
		read();
		find_pivot();
		sort(p.begin(), p.end(), cmp(p[0]));
		vector<point>ch = convex_hull();
		// sort(ch.begin(), ch.end(), cmp_2);
		printf("%d\n", ch.size());
		for (int i = 0; i < ch.size(); ++i)
			printf("%d %d\n", ch[i].X, ch[i].Y);
		if (tc != TC){
			int x; scanf("%d", &x); printf("%d\n", x);
		}
	}
}

