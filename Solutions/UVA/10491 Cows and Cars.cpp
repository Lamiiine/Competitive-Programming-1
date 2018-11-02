#include<stdio.h>
using namespace std;
int n_cows, n_cars, n_show;
double p1(void) {	// probability of choosing a cow first then switching to a car
	int n_total = n_cows + n_cars;
	double q = (double)n_cows / n_total;				// choose a cow first
	int n_after_open = n_total - 1 - n_show;
	double r = (double)n_cars/n_after_open;	// choose a car second
	return r*q;
}
double p2(void) {	// probability of choosing a car first then switching to a car again
	int n_total = n_cows + n_cars;
	double q = (double)n_cars / n_total;
	int n_after_open = n_total - 1 - n_show;
	int c_after_open = n_cars - 1;
	double r = (double) c_after_open/n_after_open;
	return r*q;
}
int main(void) {
	while (~scanf("%d%d%d", &n_cows, &n_cars, &n_show))
		printf("%1.5lf\n", p1() + p2());
	return 0;
}