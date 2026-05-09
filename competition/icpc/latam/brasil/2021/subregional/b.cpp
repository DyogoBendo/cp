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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int M1 = 1e9+7, M2 = 1e9+9;
 
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

    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<string> words(m);
    for(int i = 0; i < m; i++) cin >> words[i];

    s += s;
    str_hash<M1> sh1(s);
    str_hash<M2> sh2(s);
    vector<str_hash<M1>> wh1;
    vector<str_hash<M2>> wh2;
    for(int i = 0; i < m; i++) wh1.push_back(str_hash<M1>(words[i])), wh2.push_back(str_hash<M2>(words[i]));


    auto check = [&](int x){
        if(x == 0) return true;        
        set<pair<ll, ll>> all_subs;

        for(int i = 0; i < m; i++){
            for(int j = 0; j <= sz(words[i]) - x; j++){
                all_subs.insert({wh1[i](j, j+x-1), wh2[i](j, j+x-1)});
            }
        }

        vector<int> can(n+1);

        for(int i = 0; i < n; i++){
            if(all_subs.count({sh1(i, i+x-1), sh2(i, i+x-1)})){                
                int l = max(i+x - n, 0);                
                can[l]++;
                can[i+1]--;

                if(i + x < n) can[i+x]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(can[i] == 0) return false;
            can[i+1] += can[i];
        }
        return true;
    };

    int lo = 0, hi = n+1;
    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;
        if(check(mid)) lo = mid+1;
        else hi = mid;
    }

    cout << lo-1 << endl;
}