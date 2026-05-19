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

#define int ll

void solve(){
    int n;
    cin >> n;    
    int ans = 0;
    int can_use_with_alone = 0;
    int alone = 0;    
    int cnt = 0;
    int tot = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1) alone++;
        else{
            ans+=x;
            can_use_with_alone += (x-2) / 2;            
            cnt++;
        }
        tot += x;
    }    

    if(tot < 3){
        cout << 0 << endl;
        return;
    }

    if(cnt == 1) can_use_with_alone ++;
    ans += min(can_use_with_alone, alone);

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}