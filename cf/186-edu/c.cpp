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

const int MAXN = 5010; 

int a[MAXN], b[MAXN], c[MAXN];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];


    vector<int> comb_ij, comb_jk;
    for(int i = 0; i < n; i++){
        bool possible = true;
        for(int j = 0; j < n and possible; j++){
            int pos = (j + i) % n;
            if (b[pos] <= a[j]) possible = false;
        }

        if(possible) comb_ij.push_back(i);
    }
    for(int i = 0; i < n; i++){
        bool possible = true;
        for(int j = 0; j < n and possible; j++){
            int pos = (j + i) % n;  
            if (c[pos] <= b[j]) possible = false;   
        }

        if(possible) comb_jk.push_back(i);
    }
    ll ans = 1LL * sz(comb_ij) * sz(comb_jk) * n;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}