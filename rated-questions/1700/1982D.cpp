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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> heights(n, vector<int>(m));

    vector<string> snow(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> heights[i][j];
        }
    }
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++){
        cin >> snow[i];
        for(int j = 0; j < m; j++){
            if(snow[i][j] == '1') a += heights[i][j];
            else b += heights[i][j];
        }
    }
    ll diff = abs(b - a);    
    if(diff == 0){
        cout << "YES" << endl;
        return;
    }
    
    vector<vector<int>> psum(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            psum[i][j] = snow[i][j] == '1';
            if(i > 0) psum[i][j] += psum[i-1][j];
            if(j > 0) psum[i][j] += psum[i][j-1];
            if(i>0 and j > 0) psum[i][j] -= psum[i-1][j-1];            
        }        
    }    
    ll curr = 0;
    for(int i = k - 1; i < n; i++){
        for(int j = k - 1; j < m; j++){
            int tot = psum[i][j];
            if(i >= k) tot -= psum[i - k][j];
            if(j >= k) tot -= psum[i][j-k];
            if(i >= k and j >= k) tot += psum[i-k][j-k];
            
            int rest = k*k - tot;
            curr = gcd(curr, abs(tot - rest));            
        }
    }

    dbg(curr, diff);
    if(curr == 0 or diff % curr) cout << "NO" << endl;
    else cout << "YES" << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}