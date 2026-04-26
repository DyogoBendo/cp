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

#define int ll

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<pair<int, int>, int> mp_ab, mp_ac, mp_bc;    

    map<tuple<int, int, int>, int> mp_abc;

    int a = 0, b = 0, c = 0;
    int ab = 0, ac = 0, bc = 0, abc = 0;
    mp_ab[{0, 0}] = 1;
    mp_ac[{0, 0}] = 1;
    mp_bc[{0, 0}] = 1;
    mp_abc[{0, 0, 0}] = 1;
    
    for(int i = 0; i < n; i++){
        a += s[i] == 'A';
        b += s[i] == 'B';
        c += s[i] == 'C';

        ab += mp_ab[{a - min(a, b), b - min(a, b)}];
        ac += mp_ac[{a - min(a, c), c - min(a, c)}];
        bc += mp_bc[{b - min(b, c), c - min(b, c)}];
        abc += mp_abc[{a - min({a, b, c}), b - min({a, b, c}), c - min({a, b, c})}];        
        
        mp_ab[{a - min(a, b), b - min(a, b)}]++;
        mp_ac[{a - min(a, c), c - min(a, c)}]++;
        mp_bc[{b - min(b, c), c - min(b, c)}]++;
        mp_abc[{a - min({a, b, c}), b - min({a, b, c}), c - min({a, b, c})}]++;        
    }

    ll tot = (n * (n+1)) / 2;

    dbg(ab, ac, bc, abc);
    ll repeated = ab + ac + bc - 2*abc;
    dbg(tot, repeated);

    tot -= repeated;
    cout << tot << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}