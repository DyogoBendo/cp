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
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];
    
    vector<int> psum(n+1);

    for(int i = 0; i < n; i++){
        if(v[i] == -1 or v[i] == 0) continue;
        int l = max(i - v[i] + 1, 0);
        int r = min(n, v[i] + i); 
                
        psum[l] += 1;
        psum[r] += -1;
    }

    for(int i = 1; i < n; i++) psum[i] += psum[i-1];
    
    vector<int> t(n);
    for(int i = 0; i < n; i++) if(psum[i] == 0) t[i] = 1;


    int lst_l = -1;
    vector<int> dist(n);
    for(int i = 0; i < n; i++){
        if(t[i] == 1) lst_l = i;        
        int d = lst_l == -1 ? 1e9 : i - lst_l;
        dist[i] = d;
    }    

    lst_l = -1;
    for(int i = n-1; i >= 0; i--){
        if(t[i] == 1) lst_l = i;
        int d = lst_l == -1 ? 1e9 : lst_l - i;        
        dist[i] = min(d, dist[i]);
    }

    for(int i = 0; i < n; i++){
        if(v[i] == -1) continue;
        if(dist[i] != v[i]){            
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 0; i < n; i++) cout << t[i];
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}