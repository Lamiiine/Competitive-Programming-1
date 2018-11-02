#include<bits/stdc++.h>
using namespace std;
int x;
vector<int> c;	// my coefficients
const char space[7] = " \n\t\v\f\r";
inline int horner(void){
	int ans = 0;
	for (unsigned int i = 0; i < c.size(); ++i)
		ans = ans*x + c[i];
	return ans;
}
inline bool read(void){
	c.clear();
	if (scanf("%d", &x) == EOF) return false;
	string line;
	getline(cin, line);
	getline(cin, line);
	for (char * s = strtok(const_cast<char*>(line.c_str()), space); s; s = strtok(0, space))
		c.push_back(atoi(s));
	c.pop_back();
	const int n = c.size();
	for (int i = 0; i < n; ++i)
		c[i] *= (n - i);
	return true;
}
int main(void){
	while(read())
		printf("%d\n", horner());
	return 0;
}

