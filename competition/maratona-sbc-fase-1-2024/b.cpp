#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> movie_actors(n);
    vector<vector<int>> actor_movies(m+1);

    for (int i = 0; i < n; i++)
    {
        int qtd;
        cin >> qtd;        
        while(qtd--){
            int x;
            cin >> x;
            movie_actors[i].push_back(x);
            actor_movies[x].push_back(i);
        }
    }
    
    vector<vector<pair<int, int>>> g(n);    

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {            
            for (auto k : movie_actors[i])
            {
                auto idx = lower_bound(movie_actors[j].begin(), movie_actors[j].end(), k);
                if(idx != movie_actors[j].end() && *idx == k){
                    g[i].push_back({j, k});
                    g[j].push_back({i, k});
                    break;
                }
            }            
        }        
    }
    
    vector<vector<int>> dst;
    vector<vector<pair<int, int>>> rollback;
    for (int i = 0; i < n; i++)
    {
        vector<int> visited(n, -1);        
        vector<pair<int, int>> roll(n);
        
        queue<tuple<int, int, int, int>> q;
        q.push({i, 1, i, -1});

        while(!q.empty()){
            auto [idx, d, prevm, preva] = q.front(); q.pop();

            if(visited[idx] != -1) continue;

            visited[idx] = d;
            roll[idx] = {prevm, preva};

            for (auto e : g[idx])
            {
                if(visited[e.first] == -1) q.push({e.first, d+1, idx, e.second});
            }            
        }
        dst.push_back(visited);
        rollback.push_back(roll);
    }
    
    int q;
    cin >> q;

    while(q--){
        int x, y;
        cin >> x >> y;

        bool found = false, bst_found = false;
        int bst = n + 10, idx1 = -1, idx2 = -1;
        for (auto m1 : actor_movies[x])
        {
            for (auto m2 : actor_movies[y])
            {                
                if(dst[m1][m2] != -1){
                    found = true;
                    if(dst[m1][m2] < bst ){
                        bst = dst[m1][m2];
                        idx1 = m1;
                        idx2 = m2;                        
                    }
                }
                if(bst == 1){
                    bst_found = true;
                    break;
                }
            }
            if(bst_found) break;            
        }

        if(!found){
            cout << -1 << endl;
            continue;
        }
        
        queue<pair<int, vector<int>>> q;                

        vector<int> ans;
        int curr = idx2;

        ans.push_back(y);
        while(curr != idx1){
            ans.push_back(curr+1);            
            ans.push_back(rollback[idx1][curr].second);
            curr = rollback[idx1][curr].first;
        }
        ans.push_back(idx1+1);
        ans.push_back(x);

        reverse(ans.begin(), ans.end());
        cout << bst+1 << endl;
        for (auto a : ans)
        {
            cout << a << " ";
        }
        cout << endl;        
        
    }

}