    #include<limits.h>
    #include<stdio.h>
    #include<ctype.h>
    #include<algorithm>
    #include<string.h>
    #include<iostream>
    #include<map>
    #include<string>
    #define MAX 100005
    using namespace std;
    int head[MAX];
    int to[MAX];
    int nxt[MAX];
    int en;
    int S, F;
    int n;	// number of family members
    map<string, int> m;
    bool root[MAX];
    int ns, nf;
    inline void init(){
    	ns = nf = n = en = 0;
    	memset(head, 0xFF, sizeof head);
    	memset(root, 1, sizeof root);
    	m.clear();
    }
    inline int index(char * s){
    	map<string, int>::iterator x = m.find(s);
    	return (x == m.end()) ? m[s] = n++ : x->second;
    }
    inline void addEdge(const int i, const int j){	// 'j' is a prerequisite for 'i'
    	nxt[en] = head[i];
    	head[i] = en;
    	root[to[en++] = j] = false;
    }
    int memo[MAX][2][2];	// i, paid, family
    inline int dp(const int i, const bool paid){	// has this person been paid for?
    	int pF = F, pS = paid ? 0LL : S;
    	for (int j = head[i]; j != -1; j = nxt[j]){
    		int k = to[j];
    		pS += dp(k, 0);
    		pF += dp(k, 1);
    	}
    	return min(memo[i][paid][1] = pF, memo[i][paid][0] = pS);
    }
    inline void compute(const int i, const bool paid){
    	int p[2];
    	memcpy(p, memo[i][paid], 2 * sizeof(int));
    	if (p[0] < p[1]) {
    		if (!paid) ++ns;
    		for (int j = head[i]; j != -1; j = nxt[j])
    			compute(to[j], 0);
    	}
    	else {
    		++nf;
    		for (int j = head[i]; j != -1; j = nxt[j])
    			compute(to[j], 1);
    	}
    }
    inline const bool e(const char * s){	// empty?
    	char c;
    	for (int i = 0; c = s[i]; ++i) if (!isspace(c)) return false;
    	return true;
    }
    int main(){
    	// freopen("Input.txt", "r", stdin);
    	int tc = 0;
    	char line[1100000];
    	fgets(line, INT_MAX, stdin); while (e(line)) fgets(line, INT_MAX, stdin);
    	while (true){
    		sscanf(line, "%d%d", &S, &F);
    		if (!S && !F) break;
    		init();
    		printf("%d. ", ++tc);
    		while (true){
    			fgets(line, INT_MAX, stdin); while (e(line)) fgets(line, INT_MAX, stdin);
    			if (isdigit(line[0])) break;
    			char * name = strtok(line, " \t\v\r\n\f\\");
    			int i = index(name);
    			while (name = strtok(NULL, " \t\v\r\n\f\\"))
    				addEdge(i, index(name));
    		}
    		int price = 0;
    		for (int i = 0; i < n; ++i) if (root[i]) price += dp(i, 0), compute(i, 0);
    		printf("%d %d %d\n", ns, nf, price);
    	}
    	return 0;
    } 
