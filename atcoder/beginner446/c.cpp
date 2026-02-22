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
    int n, d;
    cin >> n >> d;

    vector<int> purchased(n), used(n);

    for(int i = 0; i < n; i++) cin >> purchased[i];
    for(int i = 0; i < n; i++) cin >> used[i];
    
    queue<int> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < purchased[i]; j++) q.push(i);
        for(int j = 0; j < used[i]; j++) q.pop();
        
        while(!q.empty() and q.front() <= i - d) q.pop();
    }

    cout << sz(q) << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}