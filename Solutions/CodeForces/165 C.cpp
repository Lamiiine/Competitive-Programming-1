#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <iostream>
#define MAX 1000005
using namespace std;
typedef long long LL;
int main() {
	int k;
	char c;
	char s[MAX];
	scanf("%d%c", &k, &c);
	scanf("%s", s);
	int left[MAX];
	int Count = 0;
	int L = 1;
	int index;
	for (index = 0; s[index]; ++index){
		if (s[index] == '1') {
			left[Count++] = L;
			L = 1;
			continue;
		}
		++L;
	}
	long long num = 0;
	left[Count] = L;
	if (!k){
		for (int i = 0; i <= Count; ++i)
			// you wrote left[Count] instead of left[i]
			num += LL((LL(left[i]-1)*LL(left[i]))/LL(2));		// type cast to long long!
		cout << num;
		return 0;
	}
	for (int i = 0; i <= Count - k; ++i){
		num += LL(left[i])*LL(left[i+k]);
	}
	cout << num;
	return 0;
}
