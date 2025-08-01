#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<int> out(n+1);
    vector<vector<int>> gi(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        gi[b].push_back(a);
        out[a]++;
    }

    priority_queue<int> pq;
    for(int i = 1; i<= n; i++) if(out[i] == 0) pq.push(i);

    vector<int> ans;

    while(!pq.empty()){
        int curr = pq.top();
        ans.push_back(curr); pq.pop();

        for (auto e : gi[curr])
        {
            out[e]--;
            if(out[e] == 0) pq.push(e);
        }        
    }

    reverse(ans.begin(), ans.end());
    vector<int>tmp(n);
    for(int i = 0; i < n; i++) tmp[ans[i]-1] = i+1;
    for(auto a : tmp) cout << a << " ";
    cout << endl;
    
}