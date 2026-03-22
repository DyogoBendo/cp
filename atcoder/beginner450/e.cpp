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


const ll MAXR = 1e18 + 100;
const int MAXN = 1e4 + 10;

string x, y;
ll total_sz[100];
ll letter_occ[100][26];
ll occ_x[MAXN][26], occ_y[MAXN][26];
int lst = 0;

void init(){
    ll c1 = sz(x);
    total_sz[1] = c1;
    for(int i = 0; i < sz(x); i++){
        for(int j = 0; j < 26; j++){
            occ_x[i+1][j] = occ_x[i][j] + (x[i] == j + 'a');
        }        
    }

    ll c2 = sz(y);
    total_sz[2] = c2;
    for(int i = 0; i < sz(y); i++){
        for(int j = 0; j < 26; j++){
            occ_y[i+1][j] = occ_y[i][j] + (y[i] == j + 'a');
        }        
    }
    for(int i = 0; i < 26; i++){
        letter_occ[1][i] = occ_x[sz(x)][i];
        letter_occ[2][i] = occ_y[sz(y)][i];
    }
        
    ll tot = c2 + c1;
    int curr = 3;
    while(tot < MAXR){                   
        total_sz[curr] = tot = (c1 + c2);

        for(int i = 0; i < 26; i++) letter_occ[curr][i] = letter_occ[curr-1][i] + letter_occ[curr-2][i];        

        c1 = c2;
        c2 = tot;
        curr++;
        lst = curr;
    }

}

ll go(int c, ll n, int k){
    if(k == 1) return occ_x[n][c];
    if(k == 2) return occ_y[n][c];    

    ll tot_pref = total_sz[k-1];

    if(tot_pref > n) return go(c, n, k-1);
    ll ans = letter_occ[k-1][c];
    if(tot_pref < n) ans += go(c, n - tot_pref, k-2);

    return ans;
}

ll calc(int c, ll n){    
    return go(c, n, 99);
}

void solve(){
    cin >> x >> y;

    init();

    int q;
    cin >> q;

    while(q--){
        ll l, r;
        char c;
        cin >> l >> r >> c;

        c -= 'a';                
        cout << calc(c, r) - calc(c, l-1) << endl;
    }
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}