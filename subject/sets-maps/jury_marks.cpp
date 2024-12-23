#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;    

    unordered_map<int, int> ap_ps;
    unordered_map<int, int> ap_score;

    int curr = 0;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        curr += x;
        ap_ps[curr]++;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ap_score[x]++;
    }
    
    unordered_map<int, int> ap;
    for (auto &ps : ap_ps)
    {
        for (auto &score : ap_score)
        {
            int a = min(score.second, ps.second);
            ap[score.first - ps.first] ++;
        }
        
    }

    int ans =0;

    for (auto &a : ap)
    {
        if(a.second == n) ans ++;
    }

    cout << ans <<endl;
}