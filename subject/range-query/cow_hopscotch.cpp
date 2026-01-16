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

const int MOD = 1e9+7;

struct Bit {
	int n;
	vector<ll> bit;
    vector<int> base_pos;    
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()+2), bit(n + 3) {
        base_pos.push_back(-1);
        for(auto x : v) base_pos.push_back(x);
        base_pos.push_back(2e9);        
	}
    
    int get_pos(int i){
        return upper_bound(base_pos.begin(), base_pos.end(), i) - base_pos.begin() - 1;
    }
    
	void update(int i, ll x) { // soma x na posicao i
        int pi = i;
        i = get_pos(i);
        assert(base_pos[i] <= pi and pi <= base_pos[i+1]);
        dbg("update", pi, i);
		for (i++; i <= n; i += i & -i) bit[i] = (bit[i] + x) % MOD;
	}
	ll pref(int i) { // soma [0, i]
        int pi = i;
        i = get_pos(i);
		ll ret = 0;
        dbg("pref", pi, i, base_pos[i], base_pos[i+1]);                
        assert(base_pos[i] <= pi and pi <= base_pos[i+1]);
		for (i++; i; i -= i & -i) ret = (ret + bit[i]) % MOD;
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(get_pos(r)) - pref(get_pos(l) - 1); 
	}
};

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
	darvem;
    setIO("hopscotch");

    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> grid(r, vector<int>(c));

    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> grid[i][j];

    vector<vector<int>> colors_columns(k+1);

    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            int current_color = grid[j][i];

            if(colors_columns[current_color].empty() or colors_columns[current_color].back() != i) colors_columns[current_color].push_back(i);
        }
    }
    
    
    vector<Bit> color_bits(k+1);
    for(int i = 1; i <= k; i++){
        color_bits[i] = Bit(colors_columns[i]);

    }

    vector<int> all_columns(c);
    for(int i = 0; i < c; i++) all_columns[i] = i;
    Bit full(all_columns);

    full.update(0, 1);
    color_bits[grid[0][0]].update(0, 1);

    for(int i = 1; i < r-1; i++){
        for(int j = c-2; j > 0; j--){
            int current_color = grid[i][j];
            ll prev = full.pref(j-1);
            ll remove = color_bits[current_color].pref(j-1);

            ll val = (prev - remove + MOD) % MOD;

            dbg(i, j, prev, remove, val);

            full.update(j, val);
            color_bits[current_color].update(j, val);
        }
    }

    ll ans = (full.pref(c-1) - color_bits[grid[r-1][c-1]].pref(c-1) + MOD) % MOD;

    cout << ans << endl;
}