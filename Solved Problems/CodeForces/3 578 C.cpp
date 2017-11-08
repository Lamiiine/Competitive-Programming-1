// precision errors!!!!!
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<float.h>
#include<string.h>
#define MAX 200005
#define eps 1e-9
using namespace std;
// WHEN YOU USE THE 'typedef' TRICK, DON'T FORGET TO UPDATE IT IN 'scanf' AND 'printf' AS WELL
typedef double ld;
int n;
ld a[MAX];
ld ans;
inline bool eq(double a, double b){
	return fabs(a - b) < eps;
}
bool can(ld x){
	ld l_sum = 0.0, h_sum = 0.0;
	ld l_ans = 0.0, h_ans = 0.0;
	ld temp;
	// a linear scan!
	for (int i = 0; i < n; ++i){
		temp = a[i] - x;
		// if (eq(temp, 0.0)) temp = 0.0;
		l_sum += temp; h_sum += temp;
		l_ans = min(l_ans, l_sum);
		h_ans = max(h_ans, h_sum);
		// YOU WROTE 'ans' INSTEAD OF 'sum'
		// STUPID TYPOS!!!!!!!!
		if (l_sum > 0.0) l_sum = 0.0;
		if (h_sum < 0.0) h_sum = 0.0;
	}
	ans = max(fabs(l_ans), fabs(h_ans));
	return fabs(l_ans) < fabs(h_ans);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf", a + i);
	ld low = -10000.0, high = 10000.0;
	can(1.75);
	// while (high - low > eps)
	for (int i = 0; i < 100; ++i)
	{
		ld mid = (high + low) / 2.0;
		if (can(mid))low = mid;
		else high = mid;
	}
	printf("%lf\n", ans);
	return 0;
}