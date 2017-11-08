#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 30
using namespace std;
int main(){
	int d, sumTime;
	int minTotal = 0, maxTotal = 0;
	int minTime[MAX];
	int maxTime[MAX];
	scanf("%d%d", &d, &sumTime);
	for (int i = 0; i < d; ++i){
		scanf("%d%d", &minTime[i], &maxTime[i]);
		minTotal += minTime[i];
		maxTotal += maxTime[i];
	}
	if (sumTime < minTotal || sumTime > maxTotal){
		printf("NO");
		return 0;
	}
	sumTime -= minTotal;
	printf("YES\n");
	for (int i = 0; i < d && sumTime; ++i){
		int x = min(sumTime, maxTime[i] - minTime[i]);
		minTime[i] += x;
		sumTime -= x;
	}
	for (int i = 0; i < d; ++i) printf("%d ", minTime[i]);
	return 0;
}