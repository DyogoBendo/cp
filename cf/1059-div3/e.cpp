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
    vector<int> cnt(n+1);
    vector<int> lst(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
        lst[v[i]] = i;
    } 

    vector<int> ans;
    for(int i = 1; i <= n && sz(ans) < k; i++){
        if(cnt[i] == 0){
            lst[i] = n + sz(ans);
            ans.push_back(i);
        }
    }

    vector<pair<int, int>> ap;
    for(int i = 1; i <= n; i++){
        ap.push_back({lst[i], i});
    }

    sort(ap.begin(), ap.end());

    int idx = 0;
    while(sz(ans) < k){
        ans.push_back(ap[idx].second);
        idx++;
    }

    for(auto a : ans) cout << a << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}