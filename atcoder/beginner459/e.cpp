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

mint comb(ll n, ll k){
    if(n < 0 or k > n or k < 0) return 0;
    mint ans = 1;
    for(ll i = n; i> n-k; i--)ans *= i;
    for(ll i = 1; i <= k; i++) ans /= i;    
    return ans;
}


signed main(){
    darvem;
    int n;
    cin >> n;

    vector<vector<int>> children(n+1);
    for(int i = 0; i < n-1;i++){
        int x;
        cin >> x;
        children[x].push_back(i+2);
    }

    vector<int> candies(n+1);
    for(int i = 1; i <= n; i++) cin>> candies[i];
    
    vector<int> directions(n+1);
    for(int i = 1; i <= n; i++) cin>> directions[i];   
    
    vector<ll> removed(n+1), tot(n+1);

    function<mint(int)> dfs = [&](int curr){        
        mint cnt = 1;
        tot[curr] = candies[curr];
        for(auto c : children[curr]){            
            cnt *= dfs(c);
            removed[curr] += removed[c];
            tot[curr] += tot[c];            
        } 

        cnt *= comb(tot[curr] - removed[curr], directions[curr]);

        removed[curr] += directions[curr];
        return cnt;
    };
    cout << dfs(1) << endl;    
}