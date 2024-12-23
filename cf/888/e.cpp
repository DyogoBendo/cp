#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;

    vector<long long> costs;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        costs.push_back(x);
    }
    
    vector<pair<long long, long long>> hq;    

    for (long long i = 0; i < k; i++)
    {
        long long x;
        cin >> x;        
        x --;
        hq.push_back({0ll, x});
        push_heap(hq.begin(), hq.end());
    }

    vector<vector<long long>> need (n, vector<long long>());
    vector<vector<long long>> used (n, vector<long long>());

    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;        
        hq.push_back({-costs[i], i});
        push_heap(hq.begin(), hq.end());
        
        for (long long j = 0; j < a; j++)
        {
            long long b;
            cin >> b;
            need[i].push_back(b - 1); 
            used[b - 1].push_back(i);
        }
        
    }
    
    vector<long long> final_prices(n, 0);
    for (long long i = 0; i < n; i++)
    {
        final_prices[i] = costs[i];        
    }

    vector<long long> price_together(n);
    for (long long i = 0; i < n; i++)
    {
        price_together[i] = 0;
        for (auto j: need[i])
        {            
            price_together[i] += costs[j];
        }        
    }
        

    vector<long long> visited(n, 0); 

    while(hq.size() > 0){
        pop_heap(hq.begin(), hq.end());
        auto top = hq.back();
        hq.pop_back();
        long long w = -top.first;
        long long i = top.second;
        if(visited[i]){
            continue;
        }        

        visited[i] = 1;
        final_prices[i] = w;

        for (auto u : used[i])
        {            
            price_together[u] -= (costs[i] - w);            
            if(price_together[u] < costs[u]){
                hq.push_back({-price_together[u], u});
                push_heap(hq.begin(), hq.end());
            }
        }
        
    }

    for (long long i = 0; i < n; i++)
    {
        cout << final_prices[i] << " ";
    }
    cout << endl;
    

}

int main(){
    long long t;
    cin >> t;
    while(t--) solve();
}