#pragma GCC optimize("O3")

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
const int MAXN = 1e5 + 10;

int n, k, l, r, ma;
int v[MAXN];
char c;

signed main(){
    darvem;

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> v[i];

    while(k--){
        cin >> c >> l >> r;

        if(c == 'Q'){
            ma = 0;
            for(int i = l; i<= r; i++) ma = max(ma, v[i]);
            cout << ma << '\n';
        } else if(c == 'A'){
            for(int i = l; i <= r; i++) v[i]++;
        } else{
            ma = 0;
            for(int i = 1; i <= n; i++) ma = max(ma, v[i]);
            for(int i = l; i <= r; i++) if(v[i] == ma) v[i] = 0;
        }
    }
}