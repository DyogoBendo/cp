#include <bits/stdc++.h>

using namespace std;

int main(){
    int s, n;
    cin >> s >> n;

    vector<tuple<int, int, int>> entries;
    for (int i = 0; i < n; i++)
    {
        int v, w, k;
        cin >> v >> w >> k;

        entries.push_back({w, -v, k});
    }

    sort(entries.begin(), entries.end());

    vector<int> used(s + 1);
    vector<int> pw;
    vector<int> pv;

    for (const auto [w, v, k] : entries)
    {                     
        int total = s / w;
        int i = 0;

        while(used[w] < total && i < k){
            used[w] ++;
            i ++;
            pv.push_back(v * -1);
            pw.push_back(w);
        }
    }

    vector<int> dp(s + 1, 0);    

    for (int i = 0; i < pw.size(); i++)
    {
        int v = pv[i], w = pw[i];        
        for (int j = s; j > 0; j--)
        {
            if(j - w >= 0) dp[j] = max(dp[j], dp[j - w] + v);
        }
        
    }

    int ans = 0;

    for (int i = 0; i <= s; i++)
    {
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;
    
}