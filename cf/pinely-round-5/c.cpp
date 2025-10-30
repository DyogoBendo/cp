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
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    vector<int> ans;
    for(int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    ll tot = 0;
    for(r = n - 1; r >= 0; r--){
        if(v[r] == x){            
            ans.push_back(x);
            tot += x;
        } else break;
    }

    int curr = 0;
    while(l <= r){                
        if(v[r] + curr >= x){
            ans.push_back(v[r]);
            tot += v[r];
            curr += v[r];
            curr %= x;
            r--;
        } else{
            ans.push_back(v[l]);
            curr += v[l];
            l++;
        }
    }
    cout << tot << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}