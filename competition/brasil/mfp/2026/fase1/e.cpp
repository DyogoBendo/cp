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
int t1, t2, t3;
int d1, d2, d3;
int p;
const int INF =  1e9;

const int MAXN = 1000;
const int MAXS = 10;

int dp[MAXN][MAXS];
int calculamos[MAXN][MAXS];

// n = voltas
// s = numero de pit stops
int f(int n, int s){
    if(n == 0) return 0;
    if(s < 0)return INF;

    if(calculamos[n][s])return dp[n][s];

    int ans = INF;

    // vamos tentar usar o macio
    int voltas_macio = min(d1, n);
    int tempo_macio = voltas_macio * t1;

    ans = min(ans, f(n - voltas_macio, s - 1) + tempo_macio + (voltas_macio < n ? p : 0));

    // vamos tentar usar o medio
    int voltas_medio = min(d2, n);
    int tempo_medio = voltas_medio * t2;
    ans = min(ans, f(n - voltas_medio, s - 1) + tempo_medio + (voltas_medio < n ? p : 0));

    // vamos tentar usar o duro
    int voltas_duro = min(d3, n);
    int tempo_duro = voltas_duro * t3;
    ans = min(ans, f(n - voltas_duro, s - 1) + tempo_duro + (voltas_duro < n ? p : 0));

    calculamos[n][s] = 1;
    dp[n][s] = ans;
    return dp[n][s];
}

signed main(){
    darvem;
    int n, s;

    cin >> n >> p >> s;

    cin >> t1 >> t2 >> t3;

    cin >> d1 >> d2 >> d3;

    cout << f(n, s) << endl;
}