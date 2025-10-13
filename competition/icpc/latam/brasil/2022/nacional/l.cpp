#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int d, idx;
int pi(string s) {
	vector<int> p(1);    
    int i = 1;
	for (int j = 0; i + idx < s.size(); i++) {
		while (j and s[idx + j] != s[idx + i]) j = p[j-1];
		if (s[idx + j] == s[idx + i]) j++;        
        int k = i - j + 1;
        if(k > d) return i;
        p.push_back(j);		
	}    
	return  i;
}

signed main(){
    darvem;

    string s;
    cin >> s >> d;

    int tot = 0;
    while(idx < sz(s)){
        tot++;        
        idx += pi(s);
    }
    cout << tot << endl;
}