#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<map<int, vector<pair<int, int>>>> g(n);
    vector<map<int, int>> psum(n);
    for(int i = 0; i < m; i++){
        int a, b, c, p;
        cin >> a >> b >> c >> p;
        a--;b--;
        g[a][c].push_back({b, p});
        g[b][c].push_back({a, p});        
        psum[a][c] += p;
        psum[b][c] += p;
    }

    vector<int> dp(n, -1);
    dp[0] = 0;
    vector<map<int, int>> dp2(n);

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});

    vector<int> dst(n, -1);
    while(!pq.empty()){
        auto [d, v, pc] = pq.top(); pq.pop();        

        if(pc){
            if(dp2[v][pc] != d) continue;

            for(auto [u, w] : g[v][pc]){
                int cost = psum[v][pc] - w;
                if(dp[u] == -1 or dp[u] > cost + d){
                    dp[u] = cost + d;
                    pq.push({d + cost, u, 0});
                }
            }
        } else{
            if(dp[v] != d) continue;
            for (auto &[c, e] : g[v])
            {
                for (auto [u, w] : e)
                {
                    // caso 1, vou trocar de cor agora e depois outra cor será trocada
                    if(dp[u] == -1 or dp[u] > d + w){
                        dp[u] = d + w;
                        pq.push({dp[u], u, 0});
                    }

                    // caso 2, não troco de cor
                    if(dp[u] == -1 or dp[u] > d + psum[v][c] - w){
                        dp[u] = d + psum[v][c] - w;
                        pq.push({dp[u], u, 0});
                    }

                    // caso 3, vou trocar de cor, mas não agora e sim no proximo
                    if(!dp2[u].count(c) or dp2[u][c] > d){
                        dp2[u][c] = d;
                        pq.push({d, u, c});
                    }
                }
                
            }
            
        }    
    }
    
    cout << dp.back() << endl;
}