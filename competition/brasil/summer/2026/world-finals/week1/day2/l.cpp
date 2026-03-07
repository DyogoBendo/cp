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

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> pxor(n+1);
    vector<vector<int>> cnt(n+1, vector<int>(30));

    for(int i = 0; i < n; i++){
        pxor[i+1] = pxor[i] ^ v[i];        
        for(int j = 29; j >= 0; j--) cnt[i+1][j] = cnt[i][j];
        for(int j = 29; j >= 0; j--) if((v[i] >> j) & 1){            
            cnt[i+1][j]++;
            break;
        } 

    }

    while(q--){
        int l, r;
        cin >> l >> r;
        
        int bst, x;
        bst = x = pxor[r] ^ pxor[l-1];        

        dbg(x);

        for(int b = 29; b >= 0; b--){
            if(cnt[r][b] - cnt[l-1][b]){
                int mov = (1 << (b+1)) - 1;
                dbg(b, mov, bst);
                bst = max(bst, bst ^ mov);
            }
        }

        cout << bst << endl;
    }
}