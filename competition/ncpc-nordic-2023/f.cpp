#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> primes = {2};
    for (int i = 3; primes.size() < 60; i+=2)
    {
        bool isprime = true;

        for (int j : primes)
        {
            if(i % j == 0) isprime = false;
        }

        if(isprime) primes.push_back(i);        
    }
    
    vector<int> ans(n, 0);
    vector<int> parent(n, 0);

    function<pair<int, int>(int, int, int)> dfs = [&](int curr, int p, int d){   
        parent[curr] = p;
        if(ans[curr]) d = 0;
        int mx_d = d, mx_s = curr;
        for (auto e : tree[curr])
        {
            if(e == p) continue;
            auto[df, sf] = dfs(e, curr, d+1);

            if(df > mx_d){
                mx_d = df;
                mx_s = sf;
            }
        }
        return make_pair(mx_d, mx_s);
    };


    ans[0] = 1;
    int idx = 0;
    auto [prof, who] = dfs(0, 0, 0);
    while(prof > 0){
        stack<int> st;
        while(ans[who] == 0){
            st.push(who);
            who = parent[who];
        }
        int curr = ans[who];
        while(!st.empty()){
            who = st.top(); st.pop();
            curr *= primes[idx];
            ans[who] = curr;
        }
        idx++;
        auto [prof1, who1] = dfs(0, 0, 0);
        prof = prof1;
        who = who1;
    }

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    
}