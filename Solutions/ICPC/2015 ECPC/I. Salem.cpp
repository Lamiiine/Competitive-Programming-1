#define Max 101
#include <stdio.h>
#include<algorithm>
#define LSOne(i) (i & (-i))
using namespace std;
int counter;
int x[Max];
int dist(int x, int y){
	int count = 0;
	while (x || y){
		if ((x & 1) ^ (y & 1)) count++;
		x >>= 1; y >>= 1;
	}
	return count;
}
inline int distance(const int x, const int y){
	int z = x ^ y, ans = 0;
	while(z) ++ans, z -= LSOne(z);
	return ans;
}
int main(){
	int t, n;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		counter = 0;
		while (n--) scanf("%d", &x[counter++]);
		int num = 0;
		for (int i = 0; i < counter - 1; i++)
		for (int j = i + 1; j < counter; j++) num = max(num, dist(x[i], x[j]));
		printf("%d\n", num);
	}
	return 0;
}
