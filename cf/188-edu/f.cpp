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

typedef mod_int<(int) 998244353> mint;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    vector<int> l (n+1);
    {
        stack<pair<int, int>> st;
        st.push({0, 0});
        for(int i = 1; i <= n; i++){
            while(st.top().first > v[i]) st.pop();            
            l[i] = st.top().second + 1;
            st.push({v[i], i});
        }
    }

    vector<int> r(n+1);
    {
        stack<pair<int, int>> st;
        st.push({0, n+1});
        for(int i = n; i >= 1; i--){            
            while(st.top().first >= v[i]) st.pop();            
            r[i] = st.top().second;
            st.push({v[i], i});
        }
    }

    vector<mint> cnt(n+1);
    for(int i = 1; i <= n; i++){
        mint tam = r[i] - l[i];
        mint pos = i - l[i] + 1;

        cnt[i] = pos * (tam - pos + 1);
    } 

    mint ans = 0;

    for(int i = 1; i <= n; i++){
        mint xn = n;
        mint xi = i;        
        mint xa = v[i];        

        mint tot_oc = xi * (xn - xi + 1);

        ans += (tot_oc - cnt[i]) / xa;
    }

    vector<pair<int, int>> v2(n);
    for(int i = 1; i <= n; i++) v2[i-1] = {v[i], i};
    sort(v2.begin(), v2.end());

    vector<mint> ssum_numerator(n+1), psum_cnt(n+1), psum_int(n+1);    

    for(int i = 0; i < n; i++){
        int idx = v2[i].second;
        mint xa = v[idx];        

        psum_int[i+1] = psum_int[i] + (2*cnt[idx] - xa*cnt[idx]);
        psum_cnt[i+1] = psum_cnt[i] + cnt[idx];
    }
    for(int i = n-1; i >= 0; i--){
        int idx = v2[i].second;
        mint xa = v[idx];    
        ssum_numerator[i] = ssum_numerator[i+1] + (cnt[idx] / xa);        
    }

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        int pos = lower_bound(v2.begin(), v2.end(), make_pair(k, (int) 1e9)) - v2.begin();
        mint xk = k;                
        cout << (ans + (psum_int[pos] + xk * psum_cnt[pos]) + (ssum_numerator[pos] * (xk + 1))) << '\n';
    }
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}