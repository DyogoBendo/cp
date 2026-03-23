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

const int MAXN = 200 + 10;

ld dp[MAXN][MAXN][MAXN]; // dp[i][j_s][j_b] - número de formas de escolher j_s discos pequenos e j_b discos grandes de gerações que não são maiores do que i, de forma que não tenha dois discos na mesma geração
ld q[MAXN][MAXN]; // q[j_s][j_b] - probabilidade que após j_s + j_b seleções, j_s discos pequenos e j_b discos grandes serão selecionados
ld pr[MAXN][MAXN]; // pr[j_s][j_b] - probabilidade que após selecionar os j_s menores discos e j_b maiores discos, não haverá dois discos da mesma geração
ld ns[MAXN]; // ns[i] - número de pequenos na geração i
ld nb[MAXN]; // nb[i] - número de grandes na geração i
ld C[MAXN][MAXN];

signed main(){
    darvem;

    for(int i = 0; i < MAXN; i++){
    C[i][0] = 1;
    for(int j = 1; j <= i; j++){
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

    int n, k, s, b;
    cin >> n >> k >> s >> b;
    vector<pair<int, int>> entries(n);
    for(int i = 0; i < n; i++) cin >> entries[i].first >> entries[i].second;

    int cnt_s = 0, cnt_b = 0;

    for(int i = 0; i < n; i++)  cnt_s += !entries[i].second, cnt_b += entries[i].second, ns[entries[i].first] += !entries[i].second, nb[entries[i].first] += entries[i].second;

    dbg(cnt_s, cnt_b);
    for(int i = 1; i <= n; i++ ) dbg(i, ns[i], nb[i]);    
    q[0][0] = 1;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(i + j >= k) continue;            

            int rs = max(cnt_s - i, 0);
            int rb = max(cnt_b - j, 0);            

            q[i+1][j] += q[i][j] * rs * s / (rs * s + rb * b);
            q[i][j+1] += q[i][j] * rb * b / (rs * s + rb * b);            
        }
    }

    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int x = 0; x <= k; x++){
            for(int y = 0; y <= k; y++){                
                dp[i+1][x][y] = dp[i][x][y];                
                if(x > 0) dp[i+1][x][y] += dp[i][x-1][y]* ns[i+1];
                if(y > 0) dp[i+1][x][y] += dp[i][x][y-1] * nb[i+1];
            }
        }
    }

    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= k; j++){            
            ld total_combinations = C[cnt_s][i] * C[cnt_b][j];
            if(total_combinations > 0) pr[i][j] = dp[n][i][j] / total_combinations;            
        }
    }

    ld sum = 0;
    for(int i = 0; i <= k; i++){        
        sum += pr[i][k-i] * q[i][k-i];
    }

    ld result = 1.0 - sum;
    cout << setprecision(30) << result << endl;
    
}