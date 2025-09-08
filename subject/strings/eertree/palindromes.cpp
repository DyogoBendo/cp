#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct eertree{
	vector<vector<int>> t;
	int n, last, sz;
	vector<int> s, len, link, qt;

	eertree(int N){
		t = vector(N + 2, vector(26, int()));
		s = len = link = qt = vector<int>(N + 2);
		s[0] = -1;
		link[0] = 1, len[0] = 0, link[1] = 1, len[1] = -1;
		sz = 2, last = 0, n = 1;
	}

	void add(char c){
		s[n++] = c -= 'a';
		while(s[n - len[last] - 2] != c) last = link[last];
		if(!t[last][c]){
			int prev = link[last];
			while(s[n - len[prev] - 2] != c) prev = link[prev];
			link[sz] = t[prev][c];
			len[sz] = len[last] + 2;
			t[last][c] = sz ++;
		}
		qt[last = t[last][c]] ++;
	}
	int size(){return sz - 2;}

	ll propagate(){
		ll ret = 0;
		for (int i = n; i > 1; i--)
		{
			qt[link[i]] += qt[i];
			ret += qt[i];
		}
		return ret;
	}
};

int main(){
	string s;
	cin >> s;
	struct eertree ee(s.size());

	for (char c: s)
	{
		ee.add(c);
	}

	ee.propagate();

	ll ans = 0;

	for (int i = 0; i <= s.size() + 1; i++)
	{
		ll len = ee.len[i]; 
		ll q =   ee.qt[i];
		ans = max(ans, len * q);
	}
	
	cout << ans << endl;
	
}