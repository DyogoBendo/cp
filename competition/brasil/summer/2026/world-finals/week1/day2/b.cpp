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

const int MOD = 998244353;
const int MAXV = 4000;
const int MAXN = 1000 + 10;
const int NSYMBOLS = 7;

string v[MAXV];
map<string, int> mp;

string characters[] = {
    "I",
    "V",
    "X",
    "L",
    "C",
    "D",
    "M"
};

string units[] = {
    "",
    "I",
    "II",
    "III",
    "IV", 
    "V",
    "VI",
    "VII",
    "VIII",
    "IX"
};

string tens[] = {
    "",
    "X",
    "XX",
    "XXX",
    "XL",
    "L",
    "LX",
    "LXX",
    "LXXX",
    "XC"
};

string hundreds[] = {
    "",
    "C",
    "CC",
    "CCC",
    "CD",
    "D",
    "DC",
    "DCC",
    "DCCC",
    "CM"
};

string thousands[] = {
    "",
    "M",
    "MM",
    "MMM",    
};

int aut[MAXV][NSYMBOLS];

void init(){
    v[0] = "";
    mp[""] = 0;
    for(int i = 1; i < MAXV; i++){
        int x = i;

        int u = x % 10;

        x/= 10;
        int d = x % 10;

        x/= 10;
        int h = x % 10;

        x/= 10;
        int t = x % 10;

        string roman = thousands[t] + hundreds[h] + tens[d] + units[u];

        mp[roman] = i;
        v[i] = roman;
    }

    for(int i = 0; i < MAXV; i++){
        string curr = v[i];

        for(int j = 0; j < NSYMBOLS; j++){
            string tmp = curr + characters[j];

            int bst = 0;
            for(int k = sz(tmp) - 1; k >= 0; k--){            
                string suffix = tmp.substr(k);

                if(mp[suffix])  bst = mp[suffix];
            }
            aut[i][j] = bst;
        }
    }
}

const int MAXSZ = 16;

ll dp[MAXV][MAXN][MAXSZ];
int visited[MAXV][MAXN];

ll expo(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e % 2) ret = ret * b % MOD;
        e /= 2, b = b * b % MOD;
    }
    return ret;
}
ll inv(ll b) { return expo(b, MOD-2); }

signed main(){
    darvem;
    init();

    int n;
    cin >> n;
            

    queue<tuple<int, int>> q;

    q.push({0, 0});

    ll tot = 0;
    ll sz_sum = 0;
    visited[0][0] = 1;
    dp[0][0][0] = 1;

    while(!q.empty()){
        auto [x, s] = q.front(); q.pop();        

        int curr_sz = sz(v[x]);        

        for(int i = 0; i < MAXSZ; i++) if(i < curr_sz) dp[x][s][curr_sz] = (dp[x][s][curr_sz] + dp[x][s][i]) % MOD;
        
        for(int i = curr_sz; i < MAXSZ; i++){
            if(s == n){
                tot = (tot + dp[x][s][i]) % MOD;
                sz_sum = (sz_sum + (i*dp[x][s][i]) % MOD) % MOD;
            } else{
                for(int j = 0; j < NSYMBOLS; j++){
                    int prox = aut[x][j];
                    if(!visited[prox][s+1]){
                        q.push({prox, s+1});
                        visited[prox][s+1] = 1;
                    }
                    dp[prox][s+1][i] = (dp[prox][s+1][i] + dp[x][s][i]) % MOD;
                }
            }
        }
    }

    cout << ((sz_sum * inv(tot)) % MOD) << endl;
}