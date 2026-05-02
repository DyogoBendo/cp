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

typedef tuple<int, int, int> Q;

const int MAX2 = 20; 
const int MAX = 2e5 + 100;

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	void update(int i, int x) {
		for (i++; i <= n; i += i & -i) bit[i] = max(bit[i], x);
	}
	int pref(int i) {
		int ret = 0;
		for (i++; i; i -= i & -i) ret = max(bit[i], ret);
		return ret;
	}	    

    void clear(int i){        
        for (i++; i <= n; i += i & -i) bit[i] = 0;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        queries.push_back({a, b, i});
    }

    vector<int> ans(q);
    Bit bit(n+10);

    vector<int> dp(n+10), suffix_min(n+10), prefix_max(n+10);

    function<void(int, int, vector<Q>)> go = [&](int l, int r, vector<Q> curr){
        dbg(l, r);
        if(curr.empty()) return;
        if(l > r) return;
        if(l == r){
            for(auto c : curr) ans[get<2>(c)] = 1;            
            return;
        }

        int m = (r - l) / 2 + l;
        vector<Q> lq, rq, cross;        

        for(auto c : curr){
            if(get<1>(c) <= m) lq.push_back(c);
            else if(get<0>(c) > m) rq.push_back(c);
            else cross.push_back(c);
        }

        vector<int> dpr;             
        int bst_r = 0;
        prefix_max[m] = 0;
        for(int i = m+1; i <= r; i++){
            auto pos = lower_bound(dpr.begin(), dpr.end(), v[i]);
            int tot = pos - dpr.begin() + 1;
            if(pos == dpr.end()) dpr.push_back(v[i]);
            else *pos = v[i];
            bst_r = max(bst_r, tot);
            dp[i] = bst_r;
            prefix_max[i] = max(prefix_max[i-1], v[i]);
        }
        
        int bst_l = 0;
        suffix_min[m+1] = 1e9;
        for(int i = m; i>= l; i--){     
            int inv = n - v[i];
            int tot = bit.pref(inv) + 1;            
            bit.update(inv, tot);
            bst_l = max(bst_l, tot);
            dp[i] = bst_l;
            suffix_min[i] = min(suffix_min[i+1], v[i]);
        }


        for(auto [a, b, idx] : cross){
            int ans_l = dp[a];
            int ans_r = dp[b];

            dbg(ans_l, ans_r);

            if(ans_l == 1 and ans_r == 1){
                if(suffix_min[a] < prefix_max[b]) ans[idx] = 2;
                else ans[idx] = 1;
            } else{
                int resp = (ans_l + ans_r) * 2;
                resp += (3-(resp%3)) % 3;
                resp/= 3;

                ans[idx] = resp;
            }
        }

        for(int i = l; i <= m; i++) bit.clear(n - v[i]);    

        go(l, m, lq);
        go(m+1, r, rq);
    };

    go(0, n-1, queries);

    for(auto a : ans) cout << a << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}