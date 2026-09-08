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

const int MAXN=1e4 + 67;

signed main(){
    darvem;

    string s, t;
    cin >> s >> t;

    bitset<MAXN> letters[26];

    for(int i = 0; i < sz(s); i++){
        int p = s[i] - 'A';        
        letters[p].set(i);        
    }

    bitset<MAXN> invalid;
    
    for(int i = 0; i < sz(t); i++){
        int p = t[i] - 'A';        
        invalid |= letters[p] >> i;        
    }

    int ans = 0;
    for(int i = 0; i <= sz(s) - sz(t); i++){
        ans += !invalid[i];
    }
    cout << ans << endl;
}