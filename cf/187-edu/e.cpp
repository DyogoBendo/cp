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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

const int MOD = 998244353;
const ll INF = 1e18;

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % MOD;
			e /= 2, b = b * b % MOD;
		}
		return ret;
	}
ll inv(ll b) { return expo(b, MOD-2); }

void solve(){
    int n;
    cin >> n;

    vector<ll> v(n), v2(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        v2[i] = v[i];
    }

    sort(v2.begin(), v2.end());    

    Bit bit(n+1);

    ord_set<ll> os;

    auto get_pos = [&](ll x){
        return lower_bound(v2.begin(), v2.end(), x) - v2.begin();
    };

    for(int i = 0; i < 2; i++){
        int pos = get_pos(v[i]);
        os.insert(v[i]);
        bit.update(pos, v[i]);
    }

    // calcula o valor do prefixo atual para o k-ésimo elemento
    auto calc_pref = [&](int k){
        if(k < 0) return 0LL;

        ll curr = *os.find_by_order(k);
        int pos = get_pos(curr);
        
        ll sum_pref = bit.pref(pos-1);
        ll ans = k*curr - sum_pref;        
        
        return ans;
    };
    
    auto calc_suf = [&](int k){
        int tot = sz(os);
        if(k >= tot) return 0LL;
        
        ll curr = *os.find_by_order(k);
        int pos = get_pos(curr);
        
        ll sum_suf = bit.query(pos, n);
        ll ans = sum_suf - (tot - k)*curr;        

        return ans;
    };

    // a função check verifica se o késimo elemento atual tem o prefixo < sufixo
    auto check = [&](int k){
        ll pref = calc_pref(k-1);
        ll suf = calc_suf(k+1);
        
        return pref < suf;
    };
    
    for(int i = 2; i < n; i++){
        int pos = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
        os.insert(v[i]);
        bit.update(pos, v[i]);

        int lo = 1, hi = i;

        while(lo < hi){
            int m = (hi - lo) / 2 + lo;            

            if(check(m)){
                lo = m + 1;
            } else{
                hi = m;
            }
        }

        ll x1, x2;

        x1 = max(calc_pref(lo-2), calc_suf(lo));
        x2 = max(calc_pref(lo-1), calc_suf(lo+1));        

        cout << ((min(x1, x2) % MOD) * inv(i-1)) % MOD << endl;

    }
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}