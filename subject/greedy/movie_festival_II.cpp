#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].second >> movies[i].first;
    }
    
    sort(movies.begin(), movies.end());

    multiset<int> available;

    for (int i = 0; i < k; i++)
    {
        available.insert(0);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto current = available.upper_bound(movies[i].second);

        if(current == available.begin()) continue;
        
        available.erase(--current);
        available.insert(movies[i].first);
        ans ++;
    }
    
    cout << ans << endl;
}