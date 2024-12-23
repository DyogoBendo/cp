#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> c;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        c.push_back({a, b});
    }

    sort(c.begin(), c.end());

    vector<int> start;
    vector<int> end;
    for (int i = 0; i < n; i++)
    {
        start.push_back(c[i].first);        
        end.push_back(c[i].second);
    }
    
    sort(end.begin(), end.end());
    
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        int v = end[i];


        long long qtd = lower_bound(start.begin(), start.end(), v) - start.begin() - i;
        
        ans = max(ans, qtd);
    }
    
    cout << ans <<endl;
    
}