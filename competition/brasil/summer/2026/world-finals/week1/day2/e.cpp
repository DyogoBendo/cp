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

// Aritmetica Modular
//
// O mod tem q ser primo

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = 1LL * v * (a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<(int)998244353> mint;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);

    for(int i = 0; i < n-1;i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<mint>> dp(n+1, vector<mint>(n+1));    

    function<void(int, int)> dfs = [&](int curr, int p){                
        int cnt = 0;
        for(auto e : g[curr]) if(e != p){            
            dfs(e, curr);
            cnt++;
        }         

        vector<vector<mint>> prefix(sz(g[curr]) + 1, vector<mint>(n+1, 1));
        vector<vector<mint>> suffix(sz(g[curr]) + 1, vector<mint>(n+1, 1));

        for(int i = 0; i < sz(g[curr]); i++){
            int e= g[curr][i];
            
            mint acc = 0;
            for(int j = 0; j <= n; j++){
                acc += dp[e][j];

                prefix[i+1][j] = prefix[i][j] * acc;
            }
        }

        for(int i = sz(g[curr]) - 1; i >= 0; i--){
            int e= g[curr][i];            
            mint acc = 0;
            for(int j = 0; j <= n; j++){
                acc += dp[e][j];

                suffix[i][j] = suffix[i+1][j] * acc;
            }
        }
        
        for(int i = 0; i < sz(g[curr]); i++){
            int e = g[curr][i];
            for(int j = 0; j < n; j++){
                dp[curr][j+1] += prefix[i][j+1]*suffix[i+1][j]*(dp[e][j] + dp[e][j+1]); 
            }
        }
        dp[curr][0] = 1;
        dp[curr][cnt] += 1;
    };  

    dfs(1, 1);

    mint ans = 0;
    for(int i = 0; i <= n; i++) ans += dp[1][i];

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}