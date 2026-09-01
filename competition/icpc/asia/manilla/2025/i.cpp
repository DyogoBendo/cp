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
		v = 1LL * v * a.v % p;
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

typedef mod_int<(int)1000696967> mint;

signed main(){
    darvem;
    string s;
    cin >> s;

    int n = sz(s);

    vector<vector<mint>> psum(10, vector<mint>(n+1)), ppsum(10, vector<mint>(n+1)), val(10, vector<mint>(n+1));
    vector<vector<int>> prox(10, vector<int>(n+1, n));
    vector<int> lst(10, -1);
    vector<int> cnt(10, 0);

    mint ans= 0;
    for(int i = 0; i < n; i++){
        int d = s[i] - '0';
        for(int j = d + 1; j <= 9; j++) psum[j][i+1] = psum[j][i];        
        for(int j = 1; j < d; j++) psum[j][i+1] = 10*psum[j][i];                

        int c = 0;
        for(int j = d; j <= 9; j++) c += cnt[j];
        
        dbg(c);        
        val[d][i] = 10;
        val[d][i]^= (c-1);
        val[d][i] *= d;
        psum[d][i+1] = val[d][i] * 10 + psum[d][i];

        cnt[d]++;
        for(int j = 1; j<= 9; j++){
            dbg(j, psum[j][i+1]);
            ans += psum[j][i+1], ppsum[j][i+1] = ppsum[j][i] + psum[j][i+1];
        } 
        cout << "--------" << endl;

        if(lst[d] != -1) prox[d][lst[d]] = i;
        lst[d] = i;
    }

    vector<mint> dsum(10);
    for(int i = 1; i <= 9; i++) for(int j = 1; j <= n; j++) dsum[i] += psum[i][j];

    dbg(ans);

    vector<int> cnt2(10, 0);
    vector<mint> removed(10, 0);
    for(int i = 0; i < n; i++){
        // try to remove the digit i now
        // so for every digit that is smaller then it, that appeared after 
        int d = s[i] - '0';
        int p = prox[d][i];    
        
        dbg(i, ans);

        dbg(d, p, ppsum[d][p], ppsum[d][i]);
        dbg(dsum[d]);
        mint p10 = 10;
        p10 ^= cnt2[d];
        dbg(cnt2[d]);
        
        dbg(val[d][i], val[d][p]);
        mint t = ppsum[d][p] - ppsum[d][i];
        if(p != n) t += val[d][p];
        dbg(t);
        t -= removed[d];
        dbg(t, removed[d]);
        mint r = t / p10;       
        dsum[d] -= r;
        dbg(dsum[d], r);
        removed[d] += t;
        cnt2[d] = 0;
        for(int j = 1; j <= d; j++) dsum[j] /= 10, cnt2[j]++;
        for(int j = 1; j <= 9; j++){
            dbg(j, dsum[j]);
            ans += dsum[j];
        } 
    }

    cout << ans << endl;
}