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

    
    vector<vector<int>> rel(n + 2);
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x <= n) rel[x].push_back(i);
        else rel[n+1].push_back(i);
    }

    if(sz(rel[0]) == 1){
        cout << "NO" << endl;
        return;
    }
    
    vector<char> ans(n);        
    bool finished = false;
    for(int i = 0; i <= n+1; i++){
        if(finished) for(auto idx : rel[i]) ans[idx] = 'C';
        else{
            for(int j = 0; j < sz(rel[i]); j++){                
                if(j == 0) ans[rel[i][j]] = 'A';
                else if(j == 1) ans[rel[i][j]] = 'B';
                else ans[rel[i][j]] = 'C';
            }
        }
        if(sz(rel[i]) <= 2) finished = true;
    }    
    cout << "YES" << endl;
    for(char c : ans) cout << c;
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}