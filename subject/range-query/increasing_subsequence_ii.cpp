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

const int MOD = 1e9+7;

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] = (bit[i] + x) % MOD;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret = (ret + bit[i]) % MOD;
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return (pref(r) - pref(l - 1) + MOD) % MOD; 
	}	
};

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> v2 = v;

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    map<int, int> mp;
    int cnt=0;
    for(auto x : v2) mp[x] = cnt++;

    Bit b(sz(mp) + 1);

    ll ans = 0;
    for(int i = n-1; i>=0; i--){
        int curr = mp[v[i]];
        dbg(i, curr);

        ll s = b.query(curr+1, sz(mp)) + 1;

        ans = (ans + s)  % MOD;
        b.update(curr, s);
        dbg(i, curr, s);
    }
    cout << ans << endl;
}