#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#define S 33	// maximum number of streets/Avenues
#define V_MAX (S << 2)	// maximum number of vertices (2 * (S + A))
#define M_MAX (M << 3)	// maximum number of edges (each route adds up to 8 implications)
using namespace std;
inline const int st(const int i){
	return i;
}
inline const int av(const int i){
	return i + S;
}
inline const int no(const int i){
	return (i + (S << 1)) % V_MAX;
}
inline const int east(const int i){
	return i;
}
inline const int west(const int i){
	return no(i);
}
inline const int south(const int i){
	return i;
}
inline const int north(const int i){
	return no(i);
}
bool dist[V_MAX][V_MAX];
inline void floyd(){
	for (int k = 0; k < V_MAX; ++k)
	for (int i = 0; i < V_MAX; ++i)
		for (int j = 0; j < V_MAX; ++j)
			dist[i][j] |= (dist[i][k] & dist[k][j]);
}
inline void addEdge(const int x, const int y)
{
	dist[x][y] = true;
}
int s, a, m;	// number of streets, avenues, and routes
string explain(int i){
	string s = "";
	if (i >= S << 1)s = "no_";
	i %= (S << 1);
	if (i >= S) s += "av_";
	else s += "st_";
	return s;
}
inline void init(void) {
	memset(dist, 0, sizeof dist);
}
void route(int a, int b, int c, int d) {
	addEdge(no(c), a);
	addEdge(no(c), b);
	addEdge(no(d), a);
	addEdge(no(d), b);
	addEdge(no(a), c);
	addEdge(no(a), d);
	addEdge(no(b), c);
	addEdge(no(b), d);
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		init();
		scanf("%d%d%d", &s, &a, &m);
		for(int a, b, c, d; m--;) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			int s1 = st(a), a1 = av(b);
			int s2 = st(c), a2 = av(d);
			if (s1 == s2 && a1 == a2)
				continue;
			// YOU WROTE 's1 < s1' INSTEAD OF 's1 < s2'!!!!!!!!!!!!!!!!!!!!!!!!!!
			bool South = s1 < s2, East = a1 < a2;
			if (s1 == s2) {
				// same street
				if (East)
					// street has to go east
					addEdge(west(s1), east(s1));
				// street has to go west
				else
					addEdge(east(s1), west(s1));
				continue;
			}
			if (a1 == a2) {
				// same avenue
				if (South)
					// avenue has to go south
					addEdge(north(a1), south(a1));
				// avenue has to go north
				else
					addEdge(south(a1), north(a1));
				continue;
			}
			if (South)
				if (East)
					// south and east
					route(south(a1), east(s2), east(s1), south(a2));
				else
					// south and west
					route(south(a1), west(s2), west(s1), south(a2));
			else
				if (East)
					// north and east
					route(north(a1), east(s2), east(s1), north(a2));
				else
					// north and west
					route(north(a1), west(s2), west(s1), north(a2));
		}
		floyd();
		bool flag = true;
		for (int i = 0; i < V_MAX && flag; ++i)
			if (dist[i][no(i)] && dist[no(i)][i]) flag = false;
		// YOU WROTE "YES" INSTEAD OF "Yes"!!!
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}

