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
    int n, m;
    cin >> n >> m;

    vector<int> va(n), vb(m);
    set<int> s;
    map<int, int> mp;
    
    for(int i = 0; i < n; i++) cin >> va[i];
    for(int i = 0; i < m; i++) cin >> vb[i];

    
    for(int i = 0; i < n; i++){
        s.insert(va[i]);
    } 

    for(int i = 0; i < m; i++) mp[vb[i]]++;


    vector<int> cnt(n + m + 1);

    sort(va.begin(), va.end());
    
    int tot = sz(s);
    for(auto i : s){
        for(int j = i; j <= n + m; j+= i){
            cnt[j]++;
        }
    }
    
    // pra que bob nao possa usar ele, significa que todos os x dividem y
    int a = 0, b = 0, both = 0;
    for(auto [x, c] : mp){
        int cnt2 = cnt[x];

        if(cnt2 == tot) a += c;
        else if(cnt2 == 0) b += c;
        else both += c;
    }

    int st = both & 1;

    if(a > b) cout << "Alice" << endl;
    else if(b > a) cout << "Bob" << endl;
    else if(st == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}