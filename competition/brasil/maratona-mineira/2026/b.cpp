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
    string s;
    cin >> s;

    vector<int> energy(n + 1, -1), jumps(n+1, 0);    
    energy[0] = 0;

    for(int i = 0; i < n; i++){
        dbg(i, s[i], energy[i], jumps[i]);
        if(energy[i] == -1 or s[i] == '.') continue;
        if(s[i+1] != '.') energy[i+1] = energy[i]+1, jumps[i+1] = jumps[i];
        else{
            for(int j = 0; j <= energy[i] + 1 and i+j <= n; j++){
                if(s[i + j] != '.' and energy[i+j] == -1){
                    energy[i+j] = 0;
                    jumps[i+j] = jumps[i] + 1;
                }
            }
        }        
    }

    if(energy[n] == -1) cout << -1 << endl;
    else cout << jumps[n] << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}