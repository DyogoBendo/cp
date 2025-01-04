// https://atcoder.jp/contests/abc179/tasks/abc179_d

#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

#define int long long

signed main(){
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> sections;

    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        sections.push_back({l, r});
    }

    vector<int> ans(n + 1, 0);
    vector<int> sum(n + 1, 0);
    ans[1] = 1;


    for (int i = 1; i <= n; i++)
    {        
        sum[i] += sum[i - 1];        
        sum[i] %= M;

        ans[i] += sum[i];
        ans[i] %= M;        
        for (auto s : sections)
        {
            if(s.first + i <= n){                
                sum[s.first + i] += ans[i];                
                sum[s.first + i] %= M;

            }
            if(s.second + i < n){
                sum[s.second + i + 1] -= ans[i];
                sum[s.second + i + 1] = (sum[s.second + i + 1] + M) % M;
            }
        }                
    }

    cout << ans[n] << endl;

}