#include <stdio.h>
#include <string>
#include <algorithm>
#define eps 1e-9
using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n;
	double l, w;
	double p, r;	// position and radius
	pair<double, double> spr[10000];
	int counter;
	int num;
	double start;
	int i;
	while (scanf("%d%lf%lf", &n, &l, &w) != EOF){
		w /= 2.0;
		counter = 0;
		for (int i = 0; i < n; i++){
			scanf("%lf%lf", &p, &r);
			if (r < w) continue;
			r = sqrt(r*r - w * w);
			spr[counter++] = pair<double, double>(p-r, p+r);
		}
		sort(spr, spr + counter);
		start = 0.0, num = 0;
		double max_right = 0.0;
		i = 0;
		bool flag = i < counter;
		while (flag && (l - start >= eps)){
			while (spr[i].first - start <= eps && i < counter) {
				if (spr[i].second >= max_right) 
					max_right = spr[i].second;
				i++;
			}
			if (max_right - start <= eps) break;
			start = max_right;
			num++;
		}
		if (l - start <= eps) printf("%d\n", num);
		else printf("-1\n");
	}
	return 0;
}