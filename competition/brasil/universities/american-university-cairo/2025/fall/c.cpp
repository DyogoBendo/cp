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

ll dp[MAXN];
ll divisores[MAXN];

void init(){
    for(ll i = 1; i < MAXN; i++){
        for(int j = i; j < MAXN; j+=i){
            divisores[j]++;
        }

        // posso combinar com todos que tem até agora - menos os meus divisores, ou seja temos i caras, e posso combinar com eles
        dp[i] = dp[i-1] + 2*(i - divisores[i]);
    }

}

void solve(){
    int n;
    cin >> n;

    // t(a) + t(b) < t(gcd(a, b)) + t(lcm(a, b))
    // todos os divisores a vão aparecer no lcm 
    // todos os divisores de b vão aparecer no lcm
    // então só precisamos saber quantos divisores temos do gcd, mas sempre vai ser pelo menos 1, assim, todos os pares são válidos
    // só não podemos pegar quando um é multiplo de outro, porque nesse caso, é equivalente
    // porque gcd(a, b) = a e lcm(a, b) = b, então eles são iguais. Ou seja, podemos pegar com qualquer cara que não é múltiplo
    // podemos fazer isso encontrando todos os múltiplos de um número, e então subtrair eles do total e somar todos os outros 
    // problema que isso é O(n)
    // vamos contar todos os caras menores que ele que podemos pegar, então sempre que adicionamos um número, contamos ele e o par oposto com os menores
    cout << dp[n] << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    init();

    while(t--) solve();
}