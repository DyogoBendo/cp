#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MAXN = 501;
const ll INF = 1e17;

ll g[MAXN][MAXN];

signed main(){
    darvem;
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) if(i != j) g[i][j] = INF;

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = min( (ll) w, g[a][b]);
        g[b][a] = min( (ll)w, g[b][a]);
    }

    for(int k = 1; k <= n; k++) for(int i = 1; i<=n;i++) for(int j = 1; j<=n;j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for(int i = 1; i<= n; i++) for(int j = 1; j <= n; j++) if(g[i][j] == INF) g[i][j] = -1;
    
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << g[a][b] << endl;
    }
}