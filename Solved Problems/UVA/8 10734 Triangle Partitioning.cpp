#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
struct triangle
{
	double a, b, c;
	triangle(double _a, double _b, double _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
	triangle(){}
	// make a the largest angle
};
inline void normalize(triangle & t)
{
	double arr[3] = {t.a, t.b, t.c};
	sort(arr, arr + 3);
	t.a = arr[2];
	t.b = arr[1];
	t.c = arr[0];
}
inline bool eq(const double a, const double b)
{
	return fabs(a - b) < eps;
}
inline bool operator == (const triangle & x, const triangle & y)
{
	return eq(x.a, y.a) && eq(x.b, y.b) && eq(x.c, y.c);
}



vector<triangle> v;
inline bool check(const triangle & t)
{
	for (int i = 0; i < v.size(); ++i)
		if (t == v[i]) return false;
	return true;
}
inline double get_cos(const double a, const double b, const double c)
{
	return acos((b * b + c * c - a * a) / (2.0 * b * c));
}
inline triangle divide_1(triangle t)
{
	// sides of triangle
	const double a_s = 1.0;					// opposite to t.a
	const double b_s = sin(t.b) / sin(t.a);	// opposite to t.b
	const double c_s = sin(t.c) / sin(t.a);	// opposite to t.c

	// triangle 2 sides!
	const double b = b_s;
	const double a = a_s * 0.5;
	const double c = sqrt(a * a + b * b - 2.0 * a * b * cos(t.c));

	// triangle 2 angles
	triangle ans(get_cos(a, b, c), get_cos(b, a, c), get_cos(c, a, b));
	normalize(ans);
	return ans;
}


inline triangle divide_2(triangle t)
{
	// sides of triangle
	const double a_s = 1.0;					// opposite to t.a
	const double b_s = sin(t.b) / sin(t.a);	// opposite to t.b
	const double c_s = sin(t.c) / sin(t.a);	// opposite to t.c

	// triangle 2 sides!
	const double c = c_s;
	const double a = a_s * 0.5;
	const double b = sqrt(a * a + c * c - 2.0 * a * c * cos(t.b));

	// triangle 2 angles
	triangle ans(get_cos(a, b, c), get_cos(b, a, c), get_cos(c, a, b));
	normalize(ans);
	return ans;
}


inline void bfs(triangle s)
{
	queue<triangle> q;
	q.push(s);
	v.push_back(s);
	while(!q.empty())
	{
		const triangle i = q.front();
		q.pop();
		triangle j = divide_1(i);
		triangle k = divide_2(i);
		if (check(j))
		{
			v.push_back(j);
			q.push(j);
		}
		if (check(k))
		{
			v.push_back(k);
			q.push(k);
		}
	}
}

int main()
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		v.clear();
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		triangle s(get_cos(a, b, c), get_cos(b, a, c), get_cos(c, a, b));
		normalize(s);
		bfs(s);
		printf("Triangle %d: %d\n", tc, v.size());
	}
	return 0;
}
/*
2
3 4 5
12 84 90
 */

