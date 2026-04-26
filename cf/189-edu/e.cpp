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

int uniform(int l, int r){    
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
    ll n, r;
    cin >> n >> r;

    vector<pair<int, int>> pts(n);
    for(int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    ll w = 2*r;
    ll h = ceil(sqrt(3)* r);
    
    int cov;
    vector<pair<int, int>> ans;
    do
    {
        cov = 0;
        ans.clear();

        int xo = uniform(1, w);
        int yo = uniform(1, h);

        for(auto p : pts){             
            int nearest_row = (p.second - yo) / h;
            
            bool found = false;
            for(ll i = nearest_row - 2; i <= nearest_row + 2 and !found; i++){
                int nearest_column = (p.first - ( xo + (i & 1 ? r : 0))) / w;
                for(ll j = nearest_column - 2; j <= nearest_column + 2 and !found; j++){
                    ll cx = xo + j*w + (i&1 ? r : 0);
                    ll cy = yo + i * h;
                    ll dx = (cx - p.first);
                    ll dy = (cy - p.second);
                    ll dist = dx*dx + dy*dy;
                    if(dist <= r*r) ans.push_back({cx, cy}), cov ++, found = true;                                            
                }  
            }             
        }
        
    } while (cov * 100 < 89 * n);
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << sz(ans) << endl;
    for(auto a: ans) cout << a.first << " " << a.second << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}