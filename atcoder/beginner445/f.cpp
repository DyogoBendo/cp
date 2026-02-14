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

int n, p;
ll INF = 1e18;

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b){
    vector<vector<ll>> c (n, vector<ll>(n, INF));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){                
                c[i][j] = min(a[i][k] + b[k][j], c[i][j]);
            }
        }
    }
    return c;
}

vector<vector<ll>> pow(vector<vector<ll>> x, ll y) { // iterativo    
	vector<vector<ll>> ret(n, vector<ll>(n));    
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j) ret[i][j] = INF;

	while (y) {
		if (y & 1) ret = mul(x, ret);
		y >>= 1;
		x = mul(x, x);
	}
	return ret;
}

void solve(){
    cin >> n >> p;

    vector<vector<ll>> m(n, vector<ll>(n));

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> m[i][j];

    auto ans = pow(m, p);

    for(int i = 0; i < n; i++) cout << ans[i][i] << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}