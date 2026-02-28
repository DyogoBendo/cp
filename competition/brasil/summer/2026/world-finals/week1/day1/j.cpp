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

const int MOD = 998244353;
const int MAXN = 3000 + 10;

ll p2[MAXN], p3[MAXN];


signed main(){
    darvem;

    p2[0] = p3[0] = 1;
    for(int i = 1; i < MAXN; i++){
        p2[i] = (p2[i-1]*2LL)%MOD;
        p3[i] = (p3[i-1]*3LL)%MOD;
    }

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    ll ans = 0;
    int p = 1, q = 2, x1 = v[0], x2, x3;
    for(int i = 1; i < n; i++){        
        x2 = v[i];
        while(p < n and v[p] < x1 + x2) p++;        

        q = p;
        for(int j = i+1; j < p; j++){
            ll curr = 1;            

            x3 = v[j];
            while(q < n and v[q] < x1 + x3) q++;                        

            if(v.back() >= x2 + x3) continue;

            int qtd_between_i_j = j - i - 1;
            int qtd_between_j_p = p - j - 1;            
            int qtd_between_p_q = q - p;
                
            curr = (curr * p2[qtd_between_i_j]) % MOD; // can place on stack 1 or 2
            curr = (curr * p3[qtd_between_j_p]) % MOD; // can place on stack 1, 2 or 3
            curr = (curr * p2[qtd_between_p_q]) % MOD; // can place on stack 1 or 2

            ans = (ans + curr) % MOD;
        }
    }

    cout << ans << endl;
}