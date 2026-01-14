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

const int MAXN = 5e5 + 5;
vector<int> values;

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
	void update(int pos, ll x) { // soma x na posicao i
        int i = upper_bound(values.begin(), values.end(), pos) - values.begin();
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int pos) { // soma [0, i]
        int i = upper_bound(values.begin(), values.end(), pos) - values.begin();        
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
};

Bit bt(MAXN);

signed main(){
    darvem;
    
    int n, q;
    cin >> n >> q;

    vector<int> salaries(n);
    for(int i = 0; i < n; i++) cin >> salaries[i];
    for(int i = 0; i < n; i++) values.push_back(salaries[i]);

    vector<tuple<char, int, int>> v;

    for(int i = 0; i < q; i++){
        char c;
        int a, b;
        cin >> c >> a >> b;


        if(c == '!') values.push_back(b);        

        v.push_back({c, a, b});
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());        

    for(int i = 0; i < n; i++) bt.update(salaries[i], 1);    

    for(auto [c, a, b] : v){
        if(c == '!'){  
            a--;          
            bt.update(salaries[a], -1);            
            bt.update(b, 1);
            salaries[a] = b;
        } else{                              
            cout << bt.query(a,b) << endl;
        }
    }
}