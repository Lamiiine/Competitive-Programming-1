#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int x;
	string s;
	int space[12];
	int sum;
	while (scanf("%d", &x), x){
		sum = 0;
		for (int i = 0; i < x; i++){
			cin >> s;
			if (space[i] = 25 - s.length()) { cin >> s; space[i] -= s.length(); };
			sum += space[i];
		}
		sort(space, space + x);
		sum -= (x*space[0]);
		printf("%d\n", sum);
	}
	return 0;
}