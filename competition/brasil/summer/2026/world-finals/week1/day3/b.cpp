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

vector<int> get_z(string s) {
	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}

const int M1 = 1e9+7;

void solve(){
    string a, b;
    cin >> a >> b;
    
    vector<ll> dp(sz(b), -1);

    vector<int> z = get_z(b + "#" + a);

    vector<int> p(b.size()), border(b.size());
	for (int i = 1, j = 0; i < b.size(); i++) {
		while (j and b[j] != b[i]) j = p[j-1];
		if (b[j] == b[i]) j++;
		p[i] = j;
        
        border[i] = !j or border[j-1] == 0 ? j : border[j-1];                
	}	

    vector<ll> suf_sum(sz(b) + 1);
    for(int i = sz(b) + 1; i < sz(z); i++){
        int x = z[i];
        suf_sum[x] ++;
    }
    for(int i = sz(b) - 1; i >= 0; i--) suf_sum[i] += suf_sum[i+1];
    
    for(int i = 0; i < sz(b); i++){                        
        ll x = border[i] == 0 ? i+1 : border[i];
        ll y = suf_sum[x];                    
        cout << ((y) * (y+1)/ 2) * x << " ";
    }
    
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}