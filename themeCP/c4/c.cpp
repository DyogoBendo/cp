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
    int n;
    cin >> n;

    // posso sempre deixar um filho de fora, porque se não passou em nenhum deles, então precisa ser ele 
    // preciso só saber caminhos de cada um que é um dam, mas pode ser que tenha um que esteja na raiz, ai ele não passa por nenhuma aresta
    // podemos sempre deixar o maior caminho sem fora se a raiz não estiver

    vector<vector<int>> g(n);
    for(int i = 0; i <n-1; i++){
        int u;
        cin >> u;
        u--;
        g[u].push_back(i+1);
    }

    int m;
    cin >> m;
    vector<int> dams(n);
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        x--;
        dams[x] = 1;        
    }

    vector<int> ans;
    function<int(int)> dfs =[&](int curr){
        dbg(curr);
        int cnt = dams[curr];
        for(auto e : g[curr]){
            int c = dfs(e);
            if(c and cnt) ans.push_back(e);            
            cnt += c;
        } 
        return cnt;
    };
    dfs(0);

    cout << sz(ans) << " ";
    for(auto e : ans) cout << e+1 << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}