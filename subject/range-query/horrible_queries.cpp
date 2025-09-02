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

#define int long long

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
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}	
};

void solve(){
    int n, c;
    cin >> n >> c;
    Bit b1(n), b2(n);

    while(c--){
        int op, p, q, v;
        cin >> op >> p >> q;
        p--;q--;
        if(op == 0){            
            cin >> v;
            b1.update(p, v);
            b1.update(q+1, -v);

            b2.update(p, (p - 1) * v);
            b2.update(q+1, q*(-v));
        } else{            
            ll l = b1.pref(p-1) * (p-1) - b2.pref(p-1);
            ll r = b1.pref(q) * q - b2.pref(q);

            cout << r - l << endl;
        }
    }
}

signed main(){
    darvem;

    int t;
    cin >> t;
    while(t --){
        solve();
    }
}