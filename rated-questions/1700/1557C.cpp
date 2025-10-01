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

typedef mod_int<(int)1e9+7> mint;

const int MAX = 2e5 + 10;

mint fat[MAX], ifat[MAX];

mint comb(int n, int k){    
    return fat[n] * (ifat[k] * ifat[n-k]);
}

void solve(){
    int n, k;
    cin >> n >> k;

    mint tot = 0;
    for(int i = 0; i < n; i+=2){        
        tot += comb(n, i);
    }
    tot += n%2;    
    dbg(tot);
    
    mint p = 1;
    for(int i = 0; i < k; i++) p *= tot;
    mint ans = p;

    mint p2 = 1, pn = 1;
    for(int i = 0; i < n; i++) p2 *= 2;

    if(n% 2 == 0){
        for(int i = 0; i < k; i++){
            p/= tot;
            ans += pn * p;
            pn *= p2;
        }
    }

    cout << ans << endl;
}


signed main(){
    fat[0] = 1;
    for(int i = 1; i < MAX; i ++){
        fat[i] = fat[i-1] * i;
    }
    ifat[MAX-1] = mint(1) / fat[MAX-1];

    for(int i = MAX-2; i >= 0; i--){
        ifat[i] = ifat[i+1] * (i + 1);
    }

    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}