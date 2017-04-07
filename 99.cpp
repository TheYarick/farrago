#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> prefix_function(string s) {
	int n = s.length();
	vector <int> pi(n);
	pi[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  
			++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
	string S, T;
	cin >> S;
	cin >> T;
	int ts = T.size();
	T.append("#");
	T.append(S);
	vector <int> pf = prefix_function(T);
	int pfs = pf.size();
	for (int i = ts; i < pfs; ++i) 
		if (pf[i] == ts) 
			cout << i - 2 * ts << ' ';
	return 0;
}
