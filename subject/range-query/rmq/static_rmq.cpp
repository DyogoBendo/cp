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

const int MAXN = 5e5 + 10;
const int MAXL = 25;
int sparse_table[MAXL][MAXN];

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> sparse_table[0][i];
    }

    for(int i = 1; i < MAXL; i++){
        for(int j = 0; j < n; j++){
            sparse_table[i][j] = sparse_table[i-1][j];
            int prox = j + (1 << (i-1));
            if(prox < n) sparse_table[i][j] = min(sparse_table[i][j], sparse_table[i-1][prox]);            
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;        

        int diff = r - l;

        int msb = __builtin_clz(1) - __builtin_clz(diff);
        
        cout << min(sparse_table[msb][l], sparse_table[msb][r - (1 << msb)]) << endl;
    }

}