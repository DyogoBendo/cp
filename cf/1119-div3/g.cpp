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
    int n, k;
    cin >> n >> k;

    vector<int> v(n), ans(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<ll> psum(n+1);
    for(int i = 0; i < n; i++) psum[i+1] = psum[i] + v[i];        


    for(int i = 1; i < n-1; i++){        
        auto check = [&](int x){            
            ll tam = x - i;            
            return (v[x] > v[i-1] + tam * k);
        };

        int l = i + 1, r = n;        

        while(l < r){
            int m = (r - l) / 2 + l;
            if(check(m)) l = m + 1;
            else r = m;
        }
          
        ll y = l - i - 1;
        ll diff = psum[l]- psum[i+1];
        ll x = y*v[i-1];
        ll xm = ((y*(y+1))/2);
        ll xk = k*xm;        
        ans[i] = diff - x - xk;         
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}