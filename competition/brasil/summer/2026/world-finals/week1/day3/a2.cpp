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

const int MAXX = 3e5 + 10;
const int MAXK = 21;

ll dp[MAXX][MAXK];


void solve(){
    int x, y, n, m, k, s;
    cin >> x >> y >> n >> m >> k >> s;

    vector<int> av(n), bv(m);
    for(int i = 0; i < n; i++) cin >> av[i];                
    for(int i = 0; i < m; i++) cin >> bv[i];    

    if(s > 50){
        cout << "No" << endl;
        return;
    }
    sort(bv.begin(), bv.end());
    
    vector<vector<int>> divisors(x+1);
    for(auto a : av) for(int j = a; j <= x; j += a) divisors[j].push_back(a);        
    
    dp[x][k] = 1;    
    
    for(int i = x; i > y; i--){
        for(int j = k; j >= 0; j--){                        
            for(auto b : bv){
                if(!j or b >= i ) break;                                        
                dp[i-b][j-1] |= dp[i][j] << 1LL;
            }            
            for(auto d : divisors[i]) dp[i/d][j] |= dp[i][j] << 1LL;            
        }        
    }
    
    vector<int> can_sub(x+1);
    for(int i = 1; i<= x; i++) for(auto b : bv) if(b < i) can_sub[i] = true;
    
    bool ans = false;        
    for(int i = 0; i <= x; i++) for(int j = 0; j <= k; j++){        
        int pos = (dp[i][j] >> (s-1LL)) & 1LL;     
        bool is_end = i <= y or (sz(divisors[i]) == 0 and (!can_sub[i] or j == 0));    
        if(pos and is_end) ans = true;
        dp[i][j] = 0;
    }

    cout << (ans ? "Yes" : "No") << endl;    
}


signed main(){
    darvem;    
    int t = 1;
    cin >> t;

    while(t--) solve();
}