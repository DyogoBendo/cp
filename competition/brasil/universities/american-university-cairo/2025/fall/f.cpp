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

signed main(){
    darvem;
    vector<int> divisores[MAXN];

    for(int i = 1; i < MAXN; i++){
        for(int j = i; j < MAXN; j+=i){
            divisores[j].push_back(i);
        }
    }

    // sempre vai ser possível chegar no final porque podemos ir de um em um
    int n;
    cin >> n;

    vector<int> v(n+1);

    for(int i = 0; i <= n; i++) cin >> v[i];

    vector<int> dp(n+1, 1e9);
    dp[n] = 0;

    for(int i = n; i > 0; i--){
        for(auto d : divisores[v[i]]){
            if(i - d < 0) break;

            dp[i - d] = min(dp[i-d], dp[i] + 1);
        }
    }
    cout << dp[0] << endl;

    // olho para todos os divisores dos números, então eu ja sei a partir de quais que eu poderia ter chegado nele

}