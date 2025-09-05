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

signed main(){
    darvem;

    string s, t;
    cin >> s >> t;

    int n = sz(s);    
    int m = sz(t);

    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }

    str_hash<M> hash(t);    

    int ans = 0;
    for(int i = 1; i < m; i++){
        // se o tamanho da string de 0 for i, então temos que o tamanho da string de 1 é
        ll r = (m - 1LL * i*cnt0);
        if(r <= 0) continue;        
        if(r % cnt1 != 0) continue;
        int k = r / cnt1;

        ll h0 = -1, h1 = -1;
        int prev = 0;
        bool possible = true;        
        for(int j = 0; j < n; j++){
            if(s[j] == '0'){
                ll tmp = hash(prev, prev + i - 1);
                if(h0 == -1) h0 = tmp;
                if(h0 != tmp) possible = false;
                prev += i;
            } else{
                ll tmp = hash(prev, prev + k - 1);
                if(h1 == -1) h1 = tmp;
                if(h1 != tmp) possible = false;
                prev += k;
            }
        }
        if(h0 == h1) possible = false;
        dbg(i, k, possible);
        ans += possible;
    }
    cout << ans << endl;
}