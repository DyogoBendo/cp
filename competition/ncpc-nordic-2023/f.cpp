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
    

    set<int> used_numbers; 
    vector<int> ans(n, 0);

    function<ll(int, int, set<int>)> dfs = [&](int curr, int st, set<int> v){
        if(ans[curr]) return -1LL;        

        ll i = 0, tmp = st, p = 1LL;
        while(used_numbers.count(st)){
            if(v.count(primes[i])){
                i++;
                continue;
            } 
            st = tmp;
            st *= primes[i];
            p = primes[i];
            i++;            
        }
        used_numbers.insert(st);
        ans[curr] = st;

        for (auto e : tree[curr])
        {
            int x = dfs(e, st, v);
            if(x != -1){
                v.insert(x);
            }
        }
        return p;
        
    };

    dfs(0, 1, set<int>());

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    
}