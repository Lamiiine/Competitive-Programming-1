#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct data{
	int base;
	int num;
	int c[11];
};
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int n, r;
	scanf("%d %d", &n, &r);
	map<string, data> arr;
	
	string name;
	int base, size, num, lower[10], upper[10];
	while (n--){
		cin >> name;
		scanf("%d%d%d", &base, &size, &num);
		for (int i = 0; i < num; i++)
			scanf("%d%d", &lower[i], &upper[i]);
		arr[name].num = num;
		arr[name].c[num-1] = size;

		for (int i = num - 2; i >= 0; i--){
			arr[name].c[i] = arr[name].c[i+1]*(upper[i+1] - lower[i+1] + 1);
		}
		arr[name].base = base;
		for (int i = 0; i < num; i++){
			arr[name].base -= arr[name].c[i] * lower[i];
		}
	}

	int offset;
	int x;
	while (r--){
		cin >> name;
		offset = arr[name].base;
		cout << name;
		printf("[");
		for (int i = 0; i < arr[name].num - 1; i++){
			scanf("%d", &x);
			offset += x*arr[name].c[i];
			printf("%d, ", x);
		}
		scanf("%d", &x);
		offset += x*arr[name].c[arr[name].num - 1];

		printf("%d] = %d\n", x, offset);
	}
}