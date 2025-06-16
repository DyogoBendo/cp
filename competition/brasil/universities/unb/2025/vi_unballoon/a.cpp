#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> restricts(n);
    vector<int> cnt(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        restricts[a].push_back(b);
        cnt[b]++;
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if(cnt[i] == 0) pq.push(-i);
    }

    vector<int> ans;
    while(!pq.empty()){
        int curr = pq.top(); pq.pop();
        ans.push_back(-curr);

        for (auto x: restricts[-curr])
        {
            cnt[x]--;
            if(cnt[x] == 0){
                pq.push(-x);
            }
        }        
    }

    if(ans.size() < n) cout << -1 << endl;
    else{
        for (auto x: ans)
        {
            cout << x+1 << " ";
        }

        cout << endl;        
    }
    
}