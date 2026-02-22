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

const int MAXM = 1000;

int visited[MAXM*MAXM + 1];
vector<int> g[MAXM*MAXM + 1];

void solve(){
    int m,a,b;
    cin >> m >> a >> b;    

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){        
            int x = (a*j + b*i) % m;

            int pos = (i*m) + j;
            int prox = (j*m) + x;            
            
            if(x == 0 or i == 0 or j == 0){
                g[m*m].push_back(pos);
            } else{
                g[prox].push_back(pos);
            }
        }
    }
    
    int ans = 0;
    function<void(int)> dfs = [&](int curr){
        for(auto e : g[curr]) if(!visited[e]){
            ans++;
            visited[e] = 1;
            dfs(e);
        }
    };

    dfs(m*m);

    int tot = m*m;

    cout << tot - ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}