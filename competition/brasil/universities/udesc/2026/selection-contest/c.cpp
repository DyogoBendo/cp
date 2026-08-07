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

const int MOD = 998244353;

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
		v = 1LL* v * (a.v) % p;
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

typedef mod_int<MOD> mint;


signed main(){
    darvem;

    int n, k;
    cin >> n >> k;    

    vector<vector<mint>> nCr(k+1, vector<mint>(k+1));
    vector<mint> C(k+1), p(1<<n);    
    vector<vector<int>> cnt(k+1, vector<int>(1 << n));
    vector<int> tmp(k+1);

    for (int i = 0; i <= k; ++i) {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; ++j) nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]);
    }    

    for(int i = 0; i < (1 << n); i++){        
        for(int j = 0; j < k; j++) cin >> tmp[j];
        for(int j = 0; j < (1 << k); j++){
            int msk = 0;            
            for(int l =0; l < k; l++) if((j >> l) & 1) msk |= tmp[l];            
            cnt[__builtin_popcount(j)][msk]++;
        }
    }

    for (int a = 0; a <= k; a++) {
        for (int i = 0; i < n; i++) {
            for (int msk = 0; msk < (1 << n); ++msk) {
                if ((msk >> i) & 1) cnt[a][msk] += cnt[a][msk ^ (1 << i)];
            }
        }
    }    

    for (int msk = 0; msk < (1<<n); ++msk) {
        for (int a = 0; a <= k; a++) {
            for (int b = a; b <= k; b++) {
                mint t = (nCr[b][a] * cnt[b][msk]);
                if ((b - a) & 1) C[a] -= t;
                else C[a] += t;                
            }
        }
        
        mint ways = 1;        
        if (C[0].v > 0) ways = 0, C[0] = 0;
        for (int a = 1; a <= k; a++){
            mint b = a;
            b^= C[a].v;                
            ways = ways * b;                                         
            C[a] = 0;
        } 
        
        p[msk] = ways;
    }

    for (int i = 0; i < n; ++i) {
        for (int msk = 0; msk < (1 << n); ++msk) {
            if ((msk >> i) & 1) p[msk] = p[msk] - p[msk ^ (1 << i)];            
        }
    }

    int ans = 0;
    for (int msk = 0; msk < (1 << n); ++msk) ans ^= p[msk].v;

    cout << ans << "\n";
}