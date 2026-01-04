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

    map<int, ll> fmp3, fmp7;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int p3 = v[i] / 3;
        int p5 = v[i] / 5;
        int p7 = v[i] / 7;


        dbg(i, p3, p5, p7);
        if(v[i] % 5 == 0){            
            ll calc = fmp3[p5] * fmp7[p5];
            dbg(calc);
            ans += calc;
        }
        if(v[i] % 3 == 0) fmp3[p3]++;
        if(v[i] % 7 == 0) fmp7[p7] ++;        
        
    }

    dbg(ans);
    
    map<int, ll> smp3, smp7;
    for(int i = n-1; i >= 0; i--){
        int p3 = v[i] / 3;
        int p5 = v[i] / 5;
        int p7 = v[i] / 7;

        if(v[i] % 5 == 0){
            dbg(i);
            ll calc = smp3[p5] * smp7[p5];
            dbg(calc);
            ans += calc;
        }
        if(v[i] % 3 == 0) smp3[p3]++;
        if(v[i] % 7 == 0) smp7[p7] ++;        
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}