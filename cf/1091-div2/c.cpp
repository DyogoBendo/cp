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

int get_cnt(ll x){
    int c = 0;
    while(x){
        c++;
        x /= 10;
    }
    return c;
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    a/= g;

    if(get_cnt(a) + get_cnt(b) > 18) return 1e18 + 100;

    return a*b;
}

void solve(){
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if(gcd(a, n) > 1 or gcd(m, b) > 1){
        cout << "NO" << endl;
        return;
    }

    ll tot_sq = (n*m);
    
    ll required_stepd = tot_sq;
    
    //dbg(required_stepd, a*m, b*n);    

    
    ll g1 = gcd(a, n);
    ll g2 = gcd(b, m);    
    
    ll l1 = lcm(a, n);
    ll l2 = lcm(b, m);
    ll k1 = l1 / a;
    ll k2 = l2 / b;
    
    ll k = lcm(k1, k2);
    
    if(k < n*m/2){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}


signed main(){
    darvem; 
    int t = 1;
    cin >> t;

    while(t--) solve();
}