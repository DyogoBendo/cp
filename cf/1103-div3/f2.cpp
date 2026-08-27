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

const int MOD = 1e9 + 7;
vector<int> primes;
const int MAXN = 5e5 + 100;
int marked[MAXN];

void crivo(){
    for(int i = 2; i < MAXN; i++){
        if(!marked[i]){
            primes.push_back(i);
            for(int j = i; j < MAXN; j += i) marked[j] = i;
        }
    }
}

const int N = 1e5 + 10;
int dp[9][19][37];
int dp2[9][19][37];
map<int, int> cntp_x, pos_px;
vector<int> xp;

void init(int x){    
    xp.clear();
    cntp_x.clear();
    pos_px.clear();        
    while(x > 1){
        int p = marked[x];        
        xp.push_back(p);
        cntp_x[p]++;
        x /= p;
    }
    reverse(xp.begin(), xp.end());
    xp.erase(unique(xp.begin(), xp.end()), xp.end());

    for(int i = 0; i < sz(xp); i++) dp[i][0][0] = dp2[i][0][0] = 1, pos_px[xp[i]] = i;
}

void solve(){
    int n, x;
    cin >> n >> x;    

    init(x);

    vector<int> v(n);
    
    map<int, ll> mp;

    for(int i = 1; i <= n; i++){
        int y;
        cin >> y;        

        int lst_p = -1;
        int cnt_p = 0;
        while(y > 1){
            int p = marked[y];

            if(lst_p != p) lst_p = p, cnt_p = 0;
            cnt_p++;

            if(x % p) mp[p] ++;
            else{
                int pos = pos_px[p];

                for(int j = 0; j < 19; j++){
                    for(int k = 0; k < 37 - cnt_p; k++){
                        if(j < cnt_p) dp[pos][cnt_p][k + cnt_p] = (dp[pos][cnt_p][k + cnt_p] + dp2[pos][j][k]) % MOD;
                        else dp[pos][j][k + cnt_p] = (dp[pos][j][k + cnt_p] + dp2[pos][j][k]) % MOD;
                    }
                }
            }                             
            y = y / p;
        }        
        for(int pos = 0; pos < sz(xp); pos++){
            for(int j = 0; j < 19; j++){
                for(int k = 0; k < 37; k++){                    
                    dp2[pos][j][k] = dp[pos][j][k];
                }
            }
        }        
    }

    ll ans = 1;
    for(auto [a, b] : mp){
        ans = (ans * (b + 1) ) % MOD;
    }    

    for(int pos = 0; pos < sz(xp); pos++){
        int curr = 0;
        for(int j = 0; j < 19; j++){            
            curr = (curr + dp[pos][j][j + cntp_x[xp[pos]]]) % MOD;
        }        
        ans = (ans * curr) % MOD;
    }

    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));

    cout << ans << endl;
}


signed main(){
    crivo();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}