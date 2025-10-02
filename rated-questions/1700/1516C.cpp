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
    
    for(int i = 0; i < n; i++){cin >> v[i];} 
    
    auto check = [&](){
        for(int i = 0; i < n; i++){
            if(v[i] % 4) return false;
        }
        return true;
    };
    
    while(check()){
        for(int i = 0; i < n; i++) v[i] /= 4;
    }

    int tot = 0;
    for(int i = 0; i < n; i++) tot += v[i];
    vector<int> dp(tot + 1);

    if(tot % 2){
        cout << 0 << endl;
        return;
    }

    dp[0] = 1;
    bool has_odd = false;
    bool has_mod2 = false;
    for(int i = 0; i < n; i++){
        if(v[i] % 2) has_odd = true;
        if(v[i] % 4 == 2) has_mod2 = true;
        for(int j = tot - v[i]; j >= 0; j--){
            dp[j + v[i]] |=dp[j]; 
        }
    }

    if(!dp[tot/2]) cout << 0 << endl;
    else{
        cout << 1 << endl;
        for(int i = 0; i < n; i++){
            if(has_odd && v[i] % 2){
                cout << i+1 << endl;
                return;
            } else if(!has_odd and has_mod2 and v[i] % 4 == 2){
                cout << i+1 << endl;
                return;
            }            
        } 
    }
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}