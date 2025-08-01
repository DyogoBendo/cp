#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

vector<int> toposort(vector<vector<int>> &g, int n){
    vector<int> in(n+1);
    for(int i = 1; i <=n; i++){
        for (auto e : g[i])
        {
            in[e]++;
        }        
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 1; i <= n; i++) if(in[i] == 0) q.push(i);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        ans.push_back(curr);
        for (auto e : g[curr])
        {
            if(--in[e] == 0) q.push(e);
        }        
    }
    return ans;
}

signed main(){
    darvem;

    int n1, m1, n2, m2;
    cin >> n1 >> n2 >> m1 >> m2;

    vector<vector<int>> g1(n1+1), g2(n2+1);

    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cin >> a >> b;
        g1[a].push_back(b);
    }

    for (int i = 0; i < m2; i++)
    {
        int a, b;
        cin >> a >> b;
        g2[a].push_back(b);
    }

    vector<int> o1 = toposort(g1, n1), o2 = toposort(g2, n2);

    vector<vector<int>> dp1(n1+1, vector<int>(n1+1)), dp2(n2+1, vector<int>(n2+1));
    vector<int> v1, v2;

    dp1[1][0] = 1;
    for(int x : o1){        
        for(auto e : g1[x]){
            for(int i = 0; i< n1; i++){
                dp1[e][i+1] |= dp1[x][i];
            }
        }
        if(x ==n1) for(int i = 0; i <= n1; i++) if(dp1[x][i]) v1.push_back(i);                    
    }

    dp2[1][0] = 2;
    for(int x : o2){
        for(auto e : g2[x]){
            for(int i = 0; i< n2; i++){                
                dp2[e][i+1] |= dp2[x][i];
            }
        }
        if(x ==n2)for(int i = 0; i <= n2; i++) if(dp2[x][i]) v2.push_back(i);                    
    }    

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        bool found = false;
        for(int k : v1){            
            int y = x - k;
            auto pos = lower_bound(v2.begin(), v2.end(), y);
            if(pos != v2.end() && (*pos) + k == x){
                found = true;
                break;
            }
        }

        cout << (found? "Yes" : "No") << endl;

    }

}