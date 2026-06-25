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
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++)cnt[v[i]]++;

    for(int i = n; i > 0; i--){
        if(!cnt[i]) continue;
        if(cnt[i] % 2 == 0){
            cout << "YES" << endl;
            return;
        }
        for(int j = i-1; j >= i - k and j > 0; j--){
            if(cnt[j]){
                cout << "YES" << endl;
                return;
            }   
        }
    }

    cout << "NO" << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}