#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

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
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, mint>> v;

    vector<tuple<int, int, mint>> events;
    for(int i = 0; i < n; i++){
        int l, r;
        mint p, q;
        cin >> l >> r >> p >> q;
        l--;
        r--;        
        v.push_back({l, r, p/q});
        events.push_back({l, i, mint(p/q)});
        events.push_back({r, i, mint(1)});
    }
    
    sort(events.begin(), events.end(), [](tuple<int, int, mint> a, tuple<int, int, mint> b){
        int p1 = get<0>(a), i1 = get<1>(a);
        int p2 = get<0>(b), i2 = get<1>(b);
        
        return p1 < p2 or (p1 == p2 && i1 < i2);
    });
    vector<int> st(n);
    vector<mint> prefix(2*n+1, 1);
    vector<mint> dp(m);
    mint ans =0;
    for(int i = 1; i < 2*n; i++){
        auto [pos, idx, p] = events[i];
        if(p != 1){
            st[idx] = i;
        } else{
            auto [l, r, q] = v[idx];
            mint prob = prefix[i-1]/(prefix[st[idx]] * q);
            mint calc =prob*dp[l];
            if(pos+1 == m){
                ans += calc;
            } else{
                dp[pos+1] += calc;
            }
        }
        prefix[i] = prefix[i-1] * p;
    }   

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    // cin >> t;

    while(t--) solve();
}