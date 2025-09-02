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

signed main(){
    darvem;

    int n;
    cin >> n;
    
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    int mx = v.back().first;
    Bit b(mx);

    auto lower = [&](int x, int hi){
        int lo = 0;
        while(lo < hi){
            int mid = (hi - lo) / 2 + lo;
            if(b.pref(mid) < x){
                hi = mid;
            } else{
                lo = mid + 1;
            }
        }
        return lo;
    };

    for(int i = 0; i < n; i++){
        auto [h, k] = v[i];

        int lst = h - k;
        int val = b.pref(lst);
        int idx1 = lower(val, h); // qual a primeira posição em que com certeza é menor que o que iremos usar, então todos eles aumentarão em 1
        int idx2 = lower(val+1, h); // qual a primeira posição que é igual ao maior que vamos atualizar, precisamos atualizar aqui pra manter ordenada a BIT

        // atualizamos desde essa posição até a última 
        b.update(idx1, 1); 
        b.update(h, -1);

        // precisamos atualizar agora os que faltaram que não fizemos completo
        b.update(idx2, 1);
        b.update(idx2 + k - (h - idx1), -1);
    }

    ll res = 0;    

    for(int i = 0; i < mx; i++){
        ll sail_num = b.pref(i);
        res += (sail_num) * (sail_num - 1) / 2;
    }

    cout << res << endl;
}