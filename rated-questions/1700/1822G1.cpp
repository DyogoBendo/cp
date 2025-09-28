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

const int MAX = 1e6 + 10;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int cnt[MAX] = {0};
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    } 

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll ans = 0;
    for(int i = 0; i < sz(v); i++){
        ll c = cnt[v[i]];
        if(c > 2){
            ans += c * (c - 1) * (c-2);
        }
                
        for(int j = 2; j * j * v[i] < MAX; j++){  
            ll curr = c * cnt[v[i] * j] * cnt[v[i] * j *j];            
            ans += curr;
        }        
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}