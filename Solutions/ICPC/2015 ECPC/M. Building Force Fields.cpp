#include<bits/stdc++.h>
#define MAX 1010
#define X real()
#define Y imag()
#define cross(a, b) ((a).X*(b).Y - (a).Y*(b).X)
#define vec(a, b) ((b) - (a))
using namespace std;
typedef long long int ll;
int n;
typedef complex<ll> point;
point p[MAX];
double memo[MAX];
inline double dist(const point & a, const point & b){
	return hypot(a.X - b.X, a.Y - b.Y);
}
inline void init(void){
	for (int i = 0; i < n; ++i)
		memo[i] = -1.0;
	memo[n] = 0.0;
	memo[n-1] = 1e9;
	memo[n-2] = dist(p[n-1], p[n-2]);
}
inline void read(void){
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; ++i)
		scanf("%d%d", &x, &y), p[i] = point(x, y);
}
inline double dp(const int i)
{
	double & ret = memo[i];
	if (ret != -1.0) return ret;
	vector<point>v;
	v.push_back(p[i]);
	v.push_back(p[i + 1]);
	double cur_cost = dist(p[i], p[i + 1]);
	double ans = cur_cost + dp(i + 2);
	for (int j = i + 2; j < n; ++j)
	{
		const point & a = p[j];
		while(v.size() > 1)
		{
			const point & b = v[v.size() - 2];
			const point & c = v.back();
			if (cross(vec(b, c), vec(b, a)) >= 0LL){
				cur_cost -= dist(b, c);
				v.pop_back();
			}
			else break;
		}
		cur_cost += dist(a, v.back());
		v.push_back(a);
		ans = min(ans, cur_cost + dp(j + 1));
	}
	return ret = ans;
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		init();
		printf("%.6lf\n", dp(0));
	}
	return 0;
}


