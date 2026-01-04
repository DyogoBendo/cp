#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define int long long

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
		v = 1LL *  v  * a.v % p;
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
const int MAXN = 7e5 + 10;

int n, m;
vector<int> r(65);
mint fat[MAXN], ifat[MAXN], p2[MAXN];


mint comb(int x, int k){    
    return fat[x] * ifat[x-k] * ifat[k];
}

mint calc_comb_sum(int x, int k){
    mint tot= 0;    
    for(int i = 0; i <= k; i++) tot += comb(x, i);    
    return tot;
}

mint calc(ll x, int pos, int tot, int diff){    
    if(pos < 0) return 1;
    int cnt= 0;
    for(int i = pos; i >= 0 and pos - diff>= 0; i--){
        dbg(i, pos, diff);
        if((x & (1LL << (pos - diff))) == 0) break;         
        diff++;
        cnt++;
    }


    int curr = r[pos];    

    // cnt indica quantos temos que colocar no mínimo do atual, e se colocarmos um a mais teremos todos 
    mint ans = curr >= cnt ? (p2[curr] - calc_comb_sum(curr, cnt)) * (p2[tot - curr]) : 0;    

    if(curr >= cnt) ans += comb(curr, cnt) * calc(x, pos - 1, tot - curr, diff);    
    return ans;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < 64; i++) r[i] = 0;


    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        r[x]++;
    }

    while(m--){
        ll op, x;
        cin >> op >> x;

        if(op == 1){
            n++;
            r[x]++;
        } else if(op == 2 && r[x]){
            n--;
            r[x]--;
        } else{            
            cout << (calc(x, 60, n, 0)) << endl;
        }        
    }

}


signed main(){
    darvem;
    fat[0] = 1;
    for(int i = 1; i < MAXN; i++) fat[i] = fat[i - 1] * i;
    ifat[MAXN - 1] = 1 / fat[MAXN-1];
    for(int i = MAXN-2; i >= 0; i--) ifat[i] = ifat[i+1] * (i+1);    

    p2[0] = 1;
    for(int i = 1; i < MAXN; i++) p2[i] = p2[i-1] * 2;

    int t = 1;    
    while(t--) solve();
}