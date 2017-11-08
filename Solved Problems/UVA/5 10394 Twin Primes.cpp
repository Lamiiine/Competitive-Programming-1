#include<stdio.h>
#include<bitset>
#include<vector>
#define MAX 18500000
using namespace std;
typedef pair<int, int> ii;
typedef long long int ll;
ii ans[100005];
int counter = 0;
void sieve(void){
	bitset<MAX + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; ; ++i)
		if (bs[i])
		{
			if (bs[i-2])
			{
				ans[counter++] = ii(i-2, i);
				if (counter > 100000) break;
			}
			if ((ll) i * i <= MAX)
				for (int j = i * i; j <= MAX; j += i)
					bs[j] = 0;
		}
}
int main(void){
	sieve();
	// freopen("Input.txt", "r", stdin);
	ii temp;
	for (int x; scanf("%d", &x) != EOF;)
		temp = ans[x - 1], printf("(%d, %d)\n", temp.first, temp.second);
	return 0;
}

