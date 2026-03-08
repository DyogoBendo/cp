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

int dp[MAXX][MAXK];


void solve(){
    int x, y, n, m, k, s;
    cin >> x >> y >> n >> m >> k >> s;

    vector<int> av(n), bv(m);

    for(int i = 0; i < n; i++) cin >> av[i];            
    
    for(int i = 0; i < m; i++) cin >> bv[i];    
    sort(bv.begin(), bv.end());
    
    dp[x][k] = 1;
    bool ans = false;        

    vector<vector<int>> divisors(x+1);

    for(auto a : av) for(int j = a; j <= x; j += a) divisors[j].push_back(a);    

    int cnt = 2;
    while(!ans){
        bool found = false;
        for(int i = y + 1; i <= x and !ans; i++){
            for(int j = 0; j <= k and !ans; j++) if(dp[i][j]) {                
                found = true;   
                bool mov = false;  
                if(j > 0){
                    for(auto b : bv){
                        if(b >= i ) break;
                        mov = true;
                        int go = i - b;
                        if(go <= y and cnt == s){
                            ans = true;
                            break;
                        }
                        dp[go][j-1] = 1;
                    }
                }                  
                for(auto d : divisors[i]) {
                    mov = true;
                    int go = i/d;
                    if(go <= y and cnt == s){
                        ans = true;
                        break;
                    }
                    dp[go][j] = 1;
                }  
                if(!mov and cnt-1 == s) ans = true;
                dp[i][j] = 0;
            }
        }
        cnt++;
        if(!found) break;
    }

    if(x == y and s == 1) ans = true;

    cout << (ans ? "Yes" : "No") << endl;
    
    for(int i = 0; i <= x; i++) for(int j = 0; j <= k; j++) dp[i][j] = 0;
}


signed main(){
    darvem;    
    int t = 1;
    cin >> t;

    while(t--) solve();
}