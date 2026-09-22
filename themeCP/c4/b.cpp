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
    string s;
    cin >> n >> s;

    // 4 possibilidades no maximo, posicoes impares precisam sempre alternar assim como as pares
    
    int ans = 0;
    for(int i = 0; i <= 1; i++){
        for(int j = 0; j<= 1; j++){
            bool can = true;
            for(int k = 0; k < n; k++){
                if(k & 1){
                    if(k % 4 == 1 and s[k] != '?' and s[k] - '0' != j) can = false;
                    else if(k % 4 == 3 and s[k] != '?' and s[k] - '0' == j) can = false;
                } else{
                    if(k % 4 == 0 and s[k] != '?' and s[k] - '0' != i) can = false;
                    else if(k % 4 == 2 and s[k] != '?' and s[k] - '0' == i) can = false;
                }   
            }
            ans += can;
        }
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}