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

const int MAXN = 1e6 + 10;
const int MOD =  998244353;

int dp[MAXN], extras[MAXN];

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int add(int a, int b){
    return (a+b) % MOD;
}

signed main(){
    darvem;

    dp[1] = 5; // 1, 4, 6, 8, 9
    extras[2] = 1; // 91
    extras[3] = 4; // 901, 981, 649, 949
    extras[4] = 5; //9801, 9081, 6049, 6649, 9469
    extras[5] = 4; // 60049, 66049, 66649, 94669
    extras[6] = 3; // 600049, 660049, 666049
    extras[7] = 3; // 6000049, 6600049, 6660049

    int pow3 = 1;

    for(int i = 2; i < MAXN; i++){
        dp[i] = mul(4, dp[i-1]); // podemos extender qualquer antiprime adicionando um par no final, certamente não iremos gerar um primo
        dp[i] = add(dp[i], mul(2, pow3)); // podemos adicionar um número de tamanho i que seja composto apenas por 0, 6, 9 e que termine em 9 - temos duas possibilidades pro primeiro digito (6 ou 9), uma sequência que podemos pegar 0,6 ou 9 e depois pegar um 9
        dp[i] = add(dp[i], extras[i]); // adicionamos os extras especiais encontrados por brute force
        dp[i] = add(dp[i], 2); // adicionamos os números especiais 800..01 e 466...669
        pow3 = mul(pow3, 3);
    }

    int n;
    cin >> n;
    cout << dp[n] << endl;
}