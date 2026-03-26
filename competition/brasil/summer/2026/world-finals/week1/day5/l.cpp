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

const int MAXX = 1e5;
const int MAXN = 1e4;
const int MAXB = 64;

ll masks[MAXB], curr[MAXB];

void calc_masks(){
    for(int b = 9; b < MAXB; b+=2){
        ll m = 0;
        for(ll i = 1; i < MAXX and __builtin_popcountll(m) < m/2 + 1; i++){            
            m |= (1LL << (i*i) % b);
        }
        masks[b] = m;
    }
}

signed main(){
    darvem;

    calc_masks();

    for(int i = 0; i < MAXN; i++){
        int x;
        cin >> x;

        for(int b = 9; b < MAXB; b+= 2){
            curr[b] |= (1LL << (x % b)); 
        }        
    }

    int ans = 0;
    for(int i = 9; i < MAXB; i+=2){
        if((curr[i] | masks[i]) == masks[i]) ans = i+1;
    }

    cout << ans << endl;
}