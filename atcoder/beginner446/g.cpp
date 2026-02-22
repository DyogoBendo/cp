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

#define int long long
const int MOD =998244353;

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> idxes(n+1);
    vector<int> precnt(n+1);    

    for(int i = 0; i < n; i++){
        cin >> v[i];        
        precnt[i] = idxes[v[i]].size();        
        idxes[v[i]].push_back(i);                
    }    
    
    vector<int> acc(n+1);

    int ans = 0;
    for(int i = 0; i < n; i++){
        int val;
        int cnt = precnt[i];
        if(cnt < v[i] - 1){
            // nao tem como eu terminar um bloco nessa posição
            val = 0;
        } else if(cnt == v[i] - 1){
            // é o primeiro bloco com o valor v[i] que eu encontro
            // posso combinar com qualquer resposta que encontrei até a primeira posição que apareci
            // e tenho que adicionar mais a possibilidade de deixar essa sequência sozinha
            val = ((acc[idxes[v[i]][0]]) + 1 + MOD) % MOD;
        } else{ 
            // ja tivemos um bloco de valor v[i], precisamos considerar apenas as respostas "novas" que surgiram entre i e i+1            
            int curr = acc[idxes[v[i]][cnt - v[i] + 1]];
            int prev = acc[idxes[v[i]][cnt - v[i]] + 1];                            
            val = (curr - prev + MOD) % MOD;
        }        

        ans = (ans + val) % MOD;
        acc[i+1] = (acc[i] + val) % MOD;
    }

    cout << ans << endl;
}