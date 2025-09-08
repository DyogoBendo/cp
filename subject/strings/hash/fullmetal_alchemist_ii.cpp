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

const int M = 1e9+9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]        
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|
typedef str_hash<M> shash;

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<string> v(n);
    vector<shash> vhash;
    int tot = 0;
    for(int i = 0; i < n; i++){        
        cin >> v[i];
        vhash.push_back(shash(v[i]));
        tot += sz(v[i]);
    }     

    auto check = [&](int l, int r, int x){
        if(x == 0) return true;
        int suffix_end = sz(v[l]) - 1;
        int suffix_start = suffix_end - x + 1;                
        ll suffix = vhash[l](suffix_start, suffix_end);
        ll prefix = vhash[r](0, x - 1);

        return suffix == prefix;
    };

    auto calc = [&](int l, int r){
        // da esquerda queremos sufixo, da direita queremos prefixo        
        int ans = 0;

        for(int i = 1; i <= min(sz(v[l]), sz(v[r])); i++){
            if(check(l, r, i)) ans = i;
        }
        return ans;        
    };

    auto check_substring = [&](int base, int to_check){
        int sz_base = sz(v[base]), sz_check = sz(v[to_check]);
        if(sz_base < sz_check) return false;

        ll expected = vhash[to_check](0, sz_check - 1);
        for(int i = 0; i + sz_check <= sz(v[base]); i++){
            if(vhash[base](i, i + sz_check - 1) == expected) return true;
        }
        return false;
    };

    vector<vector<int>> dp(n, vector<int>(n));    

    vector<int> remove(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){            
            dp[i][j] = calc(i, j);    
            bool is_sub = check_substring(i, j);            
            if( is_sub && (dp[i][j] < sz(v[i]) or j > i)){ // i contem j
                remove[j] = 1;
            }
        }
    }

    vector<int> permutation;
    for(int i = 0; i < n; i++){
        if(remove[i]) tot -= sz(v[i]);
        else permutation.push_back(i);
    }
    
    int ans = 0;
    do
    {
        int cur = 0;               
        for(int i = 0; i < sz(permutation) - 1; i++){
            cur += dp[permutation[i]][permutation[i+1]];
        }        
        ans = max(ans, cur);        
    } while (next_permutation(permutation.begin(), permutation.end()));
        
    cout << tot - ans << endl;
}