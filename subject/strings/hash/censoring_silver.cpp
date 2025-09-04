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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int M = 1e9+9;
const int u = 918733;
 
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

template<int MOD> int str_hash<MOD>::P = u;

int main(){
	darvem;
    setIO("censor");

    string s, t;
    cin >> s >> t;

    str_hash<M> h1(t);    

    vector<int> keep(sz(s), 1);
    vector<int> powu(sz(s));
    vector<ll> hash(sz(s) + 1);
    powu[0] = 1;
    for(int i = 1; i < sz(s); i++) powu[i] = (1LL * powu[i - 1] * u) % M;     

    auto get = [&](int l, int r){        
        ll ans = hash[r] - (l ? hash[l - 1]*powu[r - l + 1]%M : 0);
		return ans < 0 ? ans + M : ans;
    };

    ll cmp = h1(0, sz(t) - 1);       
    string ans = ""; 
    for(int i = 0; i < sz(s); i++){
        ans += s[i];        
        hash[sz(ans)] = (1LL * hash[sz(ans)-1] * u + s[i]) % M;                                
        if(sz(ans) >= sz(t) && get(sz(ans) - sz(t) + 1, sz(ans)) == cmp){ // queremos remover                    
            for(int j = 0; j < sz(t); j++) {
                ans.pop_back();
            }            
        }
    }
    cout << ans << endl;
}