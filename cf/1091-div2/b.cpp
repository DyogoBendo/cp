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
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int x, p;
    cin >> p;
    p--;
    x = v[p];

    int l = n;
    for(int i = 0; i < p; i++){
        if(v[i] != x){
            l = i;
            break;
        }
    }
    int r = 0;
    for(int i = n-1; i > p; i--){
        if(v[i] != x){
            r = i;
            break;
        }
    }
    int prev = -1;    
    int c1 = 0;
    for(int i = l; i < p; i++){
        if(v[i] != prev) c1++;        
        prev = v[i];
    }

    dbg(l, cnt);

    prev = -1;
    int c2 = 0;
    for(int i = r; i > p; i--){
        if(v[i] != prev) c2 ++;        
        prev = v[i];
    }
    dbg(r, cnt);

    int cnt = max(c1, c2);
    if(cnt & 1) cnt++;
    cout << cnt << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}