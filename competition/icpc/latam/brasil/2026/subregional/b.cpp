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

typedef mod_int<(int)1e9+7> mint;

signed main(){
    darvem;

    
    int n;
    cin >> n; 

    vector<int> l(n+1), r(n+1);

    vector<int> all;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        all.push_back(l[i]);
        all.push_back(r[i] + 1);
    }
    sort(all.begin(), all.end());

    all.erase(unique(all.begin(), all.end()), all.end());
    int m = sz(all);    

    vector<vector<mint>> dp(n+1, vector<mint>(m));

    auto in_range = [&](int i, int j){                
        if(all[j-1] >= l[i] and all[j] -1 <= r[i])  return true;
        return false;
    };

    for(int j = 0; j < m; j++) dp[0][j] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){            
            int s = all[j] - all[j-1];
            mint tot = 1;            
            dp[i][j] = dp[i][j-1];
            for(int k = i; k > 0; k--){
                if(!in_range(k, j)) break;
                
                int cnt = i - k + 1;
                tot *= (s - cnt + 1);
                tot /= cnt;                                          

                dp[i][j] += tot*dp[k-1][j-1];
            }            
        }        
    }
    
    cout << dp[n][m-1] << endl;
}