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

const int MAXN = 20;

ll fat[MAXN];

void solve(){
    int n;
    cin >> n;
    int m = 32 - __builtin_clz(n);
    vector<pair<int, string>> entries(m);
    for(int i = 0; i < m; i++){
        cin >> entries[i].second;
        int cnt = 0;
        for(int j = 0; j < n; j++) cnt += entries[i].second[j] == '1';
        entries[i].first = cnt;
    } 

    sort(entries.rbegin(), entries.rend());

    vector<int> v(n + 1);
    bool can = true;
    vector<int> cnt(n + 1);
    for(int i = 0; i < n; i++){
        int curr = 0;
        for(int j = 0; j < m; j++){
            curr += ((entries[j].second[i] - '0') << j);
        }
        if(curr == 0 or curr > n) can = false;
        else v[curr] = 1;
    }


    for(int i = 0; i < m; i++) cnt[entries[i].first]++;

    for(int i = 1; i <= n; i++) if(!v[i]) can = false;

    if(!can){
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    for(int i = 0; i <= n; i++){
        ans *= fat[cnt[i]];
    } 
    
    cout << ans << endl;
}


signed main(){
    darvem;
    fat[0] = 1;
    for(ll i = 1; i < MAXN; i++) fat[i] = fat[i-1] * i;
    int t = 1;
    cin >> t;

    while(t--) solve();
}