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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

const int MAXN = 2e5 + 100;
mint fat[MAXN];
mint ifat[MAXN];
mint p2[MAXN];

mint comb(int n, int k){
    return fat[n] * ifat[n-k] * ifat[k];
}

signed main(){
    darvem;

    fat[0] = 1;
    for(int i = 1; i < MAXN; i++) fat[i] = fat[i-1] * i;

    ifat[MAXN-1] = 1 / fat[MAXN-1];
    for(int i = MAXN-2; i >= 0; i--) ifat[i] = ifat[i+1] * (i + 1);

    p2[0] = 1;
    for(int i = 1; i < MAXN; i++) p2[i] = p2[i-1]*2;    

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    vector<int> cnt(n+2);

    for(int i = 0; i < n; i++) cnt[v[i].first] ++, cnt[v[i].second + 1]--;
    for(int i = 1; i <= n; i++) cnt[i] += cnt[i-1];

    vector<vector<pair<int, int>>> v2(n+1);

    for(int i = 0; i < n; i++){
        v2[v[i].first].push_back({v[i].second, i});
    }

    for(int i = 1; i <= n; i++) dbg(i, cnt[i]);

    ord_set<pair<int, int>> os;
    
    mint ans = 0;
    for(int i = 1; i <= (n-1)/2; i++){
        for(auto x : v2[i]) os.insert(x);

        int b = (n - i);
        int tota = cnt[i];
        int totb = cnt[b];
        int intersc = sz(os) - os.order_of_key({b, -1});

        dbg(i, tota, totb, intersc);

        if(tota + totb - intersc == n){
            int fixed_a = tota - intersc;         
                        
            int av_a = tota - fixed_a;        
            int av_pos = i - fixed_a;    
            
            int fixed_b = totb - intersc;
            int av_b = totb - fixed_b;
            int av_pos2 = n - i - fixed_b;    

            if(av_pos < 0 or av_pos2 < 0) continue;

            mint add = 2*comb(intersc, av_pos); 
            dbg(fixed_a, av_a, av_b, av_pos, add);

            ans += add;
        }
    }

    if(n%2 == 0){
        if(cnt[n/2] == n) ans += comb(n, n/2);
    }

    cout << ans << endl;
}