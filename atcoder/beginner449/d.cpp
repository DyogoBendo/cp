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

#define int long long

int even_in_range(int a, int b){
    int add = 0;
    if(a % 2 == 0){
        add ++;
        a ++;
    }
    if(a > b) return 0;
    int diff = b - a + 1;
    return diff/2 + add;
}

ll calc(int l, int r, int d, int u){    
    // d >= 0
    ll tot = 0;    
    for(int i = l; i <= r; i++){
        int x = abs(i);                
        int dominate = max(min(x+1, u+1) - d, 0LL);
        if(x % 2 == 0) tot += dominate, x++;
        tot += even_in_range(max(x, d), u);        
    }
    return tot;
}

void solve(){
    int l, r, d, u;
    cin >> l >> r >> d >> u;

    // passamos por todas as coordenadas x
    // ela domina a y para todos os y<= x
    // depois será alternado para cada y
    
    ll ans = 0;
    int cnt=  0;
    if(u >= 0){
        ans += calc(l, r, max(0LL, d), u);
        cnt++;
    } 
    if(d <= 0){
        ans += calc(l, r, max(0LL, -u), -d);
        cnt++;
    }    
    if(cnt == 2) ans -= calc(l, r, 0, 0);

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}