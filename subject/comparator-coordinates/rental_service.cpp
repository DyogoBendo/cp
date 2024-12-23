#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#define int long long

signed main(){
    setIO("rental");
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> cows;
    vector<pair<int, int>> stores;
    vector<int> rents;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cows.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        stores.push_back({y, x});
    }
    
    for (int i = 0; i < r; i++)
    {
        int x;
        cin >> x;
        rents.push_back(x);
    }
    
    sort(cows.begin(), cows.end(), greater<int>());
    sort(stores.begin(), stores.end(), greater<pair<int, int>>());
    sort(rents.begin(), rents.end(), greater<int>());
    
    int current_cow = 0;
    int ans = 0;
    int begin_store = 0;
    int current_store = 0;
    int current_rent = 0;
    while(current_cow < n){
        int remaining = 0;
        int current_milked = 0;
        int current_available = cows[current_cow];

        current_store = begin_store;

        while(current_store < m){            
            int quantity = min(current_available, stores[current_store].second);            
            current_milked += stores[current_store].first * quantity;
            if(quantity == current_available){
                remaining = stores[current_store].second - quantity;
                break;
            } else{
                current_store ++;
                current_available -= quantity;
            }                       
        }
        
        if(current_rent >= r || current_milked > rents[current_rent]){            
            stores[current_store].second = remaining;
            ans += current_milked;
            current_cow ++;
            begin_store = current_store;
        } else{            
            ans += rents[current_rent];
            current_rent ++;
            n --;
        }
    }    

    cout << ans << endl;
}