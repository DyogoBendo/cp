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
		v = v * 1LL*(a.v) % p;
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

const int MAX = 3200;
int divi[MAX];
vector<int> primes;

ll pow(ll x, ll y, ll m) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}


void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    map<int, pair<int, int>> pmax;    

    vector<vector<tuple<int, int, int>>> prime_fact(n);    
    vector<pair<int, int>> pmax_lo(sz(primes));

    for(int i = 0; i < n; i++){
        int x = v[i];
        for(int j = 0; j < sz(primes); j++){
            int p = primes[j];
            if(x == 1) break;
            if(p > x) break;            

            int cnt = 0;
            while(x % p == 0){
                x /= p;
                cnt++;                
            }
            
            auto curr = pmax_lo[j];            
            if(cnt > curr.first){
                curr.second = curr.first;
                curr.first = cnt;                
            } else if(cnt > curr.second){
                curr.second = cnt;
            }
            pmax_lo[j] = curr;
            if(cnt) prime_fact[i].push_back({p, cnt, j});
        }
        if(x > 1){
            auto curr = pmax[x];
            if(1 > curr.first){
                curr.second = curr.first;
                curr.first = 1;                
            } else if(1 > curr.second){
                curr.second = 1;
            }
            pmax[x] = curr;
            prime_fact[i].push_back({x, 1, -1});
        }
    }       

    mint ans = 1;
    for(int i = 0; i < sz(primes); i++) ans *= pow(primes[i], pmax_lo[i].first);
    for(auto [p, x] : pmax){        
        ans *= pow(p, x.first);        
    }    
        
    for(int i = 0; i < n; i++){        
        mint curr_ans = ans;
        for(auto [p, cnt, idx] : prime_fact[i]){
            pair<int, int> curr;
            if(p < MAX) curr = pmax_lo[idx];
            else curr = pmax[p];            
            if(cnt and cnt == curr.first){
                curr_ans /= pow(p, cnt - curr.second);                            
            }
        }        
        cout << curr_ans << " ";
    }       
    
    cout << endl;
}


signed main(){
    darvem;
    crivo(MAX - 1);
    dbg(sz(primes));
    int t = 1;
    cin >> t;

    while(t--) solve();
}