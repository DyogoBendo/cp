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

    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, pair<int, int>>> rec(n);
    for(int i = 0; i < n; i++) cin >> rec[i].first.first >> rec[i].first.second >> rec[i].second.first >> rec[i].second.second; 

    vector<pair<int, int>> pts(m);
    for(int i = 0; i < m; i++) cin >> pts[i].first >> pts[i].second;

    vector<int> values;
    auto add = [&](pair<int, int> p){
        values.push_back(p.first);
        values.push_back(p.second);
    };

    for(auto [p1, p2] : rec){
        add(p1);
        add(p2);
    }
    for(auto p : pts) add(p);

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    map<int, int> mp;
    int cnt = 0;
    for(auto v : values) mp[v] = ++cnt;
    
    vector<tuple<int, int, pair<int, int>>> events;
    for(int i = 0; i < n; i++){
        auto &[p1, p2] = rec[i];
        events.push_back({mp[p1.first], i, {mp[p1.second], mp[p2.second]}});
        events.push_back({mp[p2.first], i, {mp[p1.second], mp[p2.second]}});
    }
    for(auto &p : pts) events.push_back({mp[p.first], -1, {mp[p.second], mp[p.second]}});        

    sort(events.begin(), events.end());

    vector<int> tot(n), checked(n);
    ld ans = 0;

    vector<int> v(cnt + 10);
    Bit bit(v);

    ld all = 1.0 * m * m;
    for(auto [x, idx, y] : events){
        if(idx == -1){
            bit.update(y.first, 1);
        } else{            
            tot[idx] = bit.query(y.first, y.second) - tot[idx];            
            if(checked[idx]){
                ld all_cross = 2.0 * tot[idx] * (m - tot[idx]);
                dbg(idx, tot[idx], m - tot[idx], all_cross);
                ans += all_cross / all;
            } else{
                checked[idx] = 1;
            }
        }
    }

    cout << setprecision(12) << ans << endl;
}