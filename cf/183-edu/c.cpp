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

void solve(){
    int n;
    string s;

    cin >> n >> s;

    int cnta = 0, cntb = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') cnta++;
        else cntb++;
    }    

    int diff = abs(cntb - cnta);

    if(diff == 0){
        cout << 0 << endl;
        return;
    }

    char letter = cntb > cnta ? 'b' : 'a';

    if(diff == n){
        cout << -1 << endl;
        return;
    }

    map<int, int> ap, l;
    ap[0] = 1;
    l[0] = -1;

    int curr = 0;
    int ans = n;    
    for(int i = 0; i < n; i++){
        if(s[i] == letter) curr++;
        else curr--;        

        int need = curr - diff;        
        if(ap[need]) ans = min(ans, i - l[need]);
        
        ap[curr] = 1;
        l[curr] = i;

        dbg(i, curr, need);
    }

    if(ans == n) ans = -1;
    cout << ans << endl;
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}