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

#define int long long

void solve(){
    int n;
    cin >> n;
    ll ans = 0;

    map<int, int> mp;
    int tot = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
        if(mp[x] == 2){
            mp[x] = 0;
            ans += x;
            tot++;
        }
    }

    ans*=2;

    int x1= 0, x2 = 0;
    int prev = 0;
    for(auto [a, cnt] : mp) if(cnt){
        if(ans + prev > a){
            x1 = a;
            x2 = prev;
        } 
        prev = a;
    }
    if(!x1 && tot == 1) ans = 0;
    else ans += x1 + x2;
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}