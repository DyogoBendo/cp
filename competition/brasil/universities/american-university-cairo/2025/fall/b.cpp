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

void solve(){
    string s;
    cin >> s;

    // só podemos trocar caracteres quando a maior posição é da mesma potencia de 2
    // se for acima, sempre vai manter ativo o bit do maior então vai ser maior que o minimo
    // se for da mesma, como ele passa a ser 0, certamente é menor, ou seja, trocamos dentro de uma janela sempre
    /*
        1
        2 3 
        4 5 6 7 
    */

    for(int i = 0; (1 << i) <= sz(s); i++){
        int first = (1 << i) - 1;
        int lst = min(sz(s), first+ (1 << i));
        dbg(first, lst);
        sort(s.begin() + first, s.begin() + lst);
    }
    cout << s << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}