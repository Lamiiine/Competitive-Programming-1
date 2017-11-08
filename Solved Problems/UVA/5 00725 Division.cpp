#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
char s[20] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 };
vector<ii>ans;
bool unique(int i, int j){
	bool used[10] = { 0 };
	for (int k = 0; k < 5; ++k)
	{
		int temp;
		temp = i % 10; i /= 10;
		if (used[temp]) return false;
		used[temp] = true;
		temp = j % 10; j /= 10;
		if (used[temp]) return false;
		used[temp] = true;
	}
	return true;
}
void init(int N){
	ans.clear();
	char s[6]; s[5] = 0; int x, y;
	for (char i = '0'; i <= '9'; ++i){
		s[0] = i;
		for (char j = '0'; j <= '9'; ++j){
			s[1] = j;
			for (char k = '0'; k <= '9'; ++k){
				s[2] = k;
				for (char l = '0'; l <= '9'; ++l){
					s[3] = l;
					for (char m = '0'; m <= '9'; ++m)
					{
						s[4] = m;
						sscanf(s, "%d", &y);
						x = y * N;
						if (x < 100000 && unique(x, y))
							ans.push_back(ii(x, y));
					}
				}
			}
		}
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int N;
	bool first = true;
	while (scanf("%d", &N), N){
		if (!first) printf("\n");
		first = false;
		init(N);
		if (ans.empty()) printf("There are no solutions for %d.\n", N);
		else {
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); ++i){
				ii temp = ans[i];
				if (temp.first <= 9999) printf("0");
				printf("%d / ", temp.first);
				if (temp.second <= 9999) printf("0");
				printf("%d = %d\n", temp.second, N);
			}
		}
	}
	return 0;
}