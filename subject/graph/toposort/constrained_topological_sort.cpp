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
    //darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    vector<int> in(n+1);
    vector<int> l(n+1);
    vector<int> r(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        in[b] ++;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }    

    vector<int> ord = toposort(g, n);


    bool possible = (int) ord.size() == n;

    if(!possible){
        cout << "No" << endl;
        return 0;
    }
    
    for(int i = n-1; i>= 0; i--){        
        int x = ord[i];        

        for (auto e : g[x])
        {
            r[x] = min(r[x], r[e] - 1);
        }
        if(r[x] < l[x]) possible=false;
    }    

    if(!possible){
        cout << "No" << endl;
        return 0;
    }
 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >  pq1, pq2;

    for (int i = 1; i <= n; i++)
    {
        if(in[i] == 0){
            if(l[i] == 1) pq1.push({r[i], i});
            else pq2.push({l[i], i});
        }
    }
        
    vector<int> ans;
    int cnt = 1;
    while(!pq1.empty()){
        auto [rx, idx] = pq1.top(); pq1.pop();
        if(cnt < l[idx] or cnt > r[idx]){
            possible = false;
            break;
        } 
        ans.push_back(idx);

        for (auto e : g[idx])
        {
            in[e]--;
            if(in[e] == 0) pq2.push({l[e], e});
        }

        cnt++;
        while(!pq2.empty()){
            auto [lx, idx2]= pq2.top();
            if(lx > cnt) break;
            pq2.pop();
            pq1.push({r[idx2], idx2});
        }
        
    }

    if(ans.size() != n) possible = false;

    if(!possible) cout << "No" << endl;
    else{
        cout << "Yes" << endl;        
        vector<int> tmp(n);
        for(int i = 0; i < n; i++)tmp[ans[i]-1] = i+1;
        for (auto a : tmp) cout << a << " ";
        cout << endl;        
    }
    
}