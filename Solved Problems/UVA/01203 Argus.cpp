#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct inst{
	int t;	// time of next arrival
	int i;	// ID
	int p;	// period
};
inline bool operator < (const inst & a, const inst & b){
	return (a.t != b.t) ? a.t < b.t : a.i < b.i;
}
char s[20];
int main(){
	// freopen("Input.txt", "r", stdin);
	priority_queue<inst>q;
	while(scanf("%s", s), strcmp(s, "#")){
		int x, y; scanf("%d%d", &x, &y);
		q.push(inst{-y, -x, -y});
	}
	int k;
	scanf("%d", &k);
	while(k--){
		inst temp = q.top();
		q.pop();
		printf("%d\n", -temp.i);
		q.push(inst{temp.t + temp.p, temp.i, temp.p});
	}
	return 0;
}

