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


int query(ll x){
    char c;
    cout << "? " << x << endl;
    cin >> c;
    return c == 'B';
}   

void answer(ll l){
    cout << "! " << l << endl;
}

ll bb(ll lo, ll hi, int ref){    
    while(lo < hi){        
        ll m = (hi - lo) / 2 + lo;
        int c = query(m);

        if(c == ref) lo = m+1;
        else hi = m;
    }
    return lo;
}

void solve(){
    int st = query(0);
    
    // vamos procurar pelo primeiro que é de outra cor, criando um intervalo r
    
    ll curr_len = 1, l, r;
    int c;    
    do
    {
        c = query(curr_len);
        r = curr_len;
        curr_len *= 2;
    } while (c == st);    
    
    curr_len = 1;    
    do
    {
        c = query(-curr_len);
        l = -curr_len;
        curr_len *= 2;
    } while (c == st);        
    
    ll lf = bb(l, 0, st^1);
    ll rf = bb(0, r, st);
    
    answer(rf-lf);

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}