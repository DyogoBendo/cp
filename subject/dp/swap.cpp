#include <bits/stdc++.h>

using namespace std;

const int LETTERS = 3;
const int MAX_SWAPS = 465;

int main(){
    string s;
    cin >> s;

    int k;
    cin >> k;

    int n = (int) s.size();
    vector<int> count(LETTERS);
    for(char &x: s){
        if(x == 'K') count[0] ++;
        else if(x == 'E') count[1] ++;
        else count[2] ++;
    }

    vector<vector<int>> pref(n + 1, vector<int>(LETTERS));
    vector<vector<int>> pos(LETTERS);

    for (int i = 0; i < n; i++)
    {
        pref[i][0] = (i - 1 >= 0 ? pref[i - 1][0] : 0) + (s[i] == 'K');
        pref[i][1] = (i - 1 >= 0 ? pref[i - 1][1] : 0) + (s[i] == 'E');
        pref[i][2] = (i - 1 >= 0 ? pref[i - 1][2] : 0) + (s[i] == 'Y');

        if(s[i] == 'K') pos[0].push_back(i);
        if(s[i] == 'E') pos[1].push_back(i);
        if(s[i] == 'Y') pos[2].push_back(i);

    }

    vector<vector<vector<vector<long long>>>> dp(
        MAX_SWAPS,
        vector<vector<vector<long long>>>(
            count[0] + 1, vector<vector<long long>>(
                count[1] + 1, vector<long long>(
                    count[2] + 1, 0
                )
            )
        )
    );

    dp[0][0][0][0] = 1;
    long long ans = 0;

    for (int ks = 0; ks <= count[0]; ks++)
    {
        for (int es = 0; es <= count[1]; es++)
        {
            for (int ys = 0; ys <= count[2]; ys++)
            {
                for (int cur = 0; cur < MAX_SWAPS; cur++)
                {
                   if(ks < count[0]){
                        int cost = max(0, pref[pos[0][ks]][1] - es) + max(0, pref[pos[0][ks]][2] - ys);
                        if(cur + cost < MAX_SWAPS){
                            dp[cur + cost][ks + 1][es][ys] += dp[cur][ks][es][ys];
                        } 
                   }
                   if(es < count[1]){
                        int cost = max(0, pref[pos[1][es]][0] - ks) + max(0, pref[pos[1][es]][2] - ys);
                        if(cur + cost < MAX_SWAPS){
                            dp[cur + cost][ks][es + 1][ys] += dp[cur][ks][es][ys];
                        } 
                   }
                   if(ys < count[2]){
                       int cost = max(0, pref[pos[2][ys]][0] - ks) + max(0, pref[pos[2][ys]][1] - es);
                        if(cur + cost < MAX_SWAPS){
                            dp[cur + cost][ks][es][ys + 1] += dp[cur][ks][es][ys];
                        }  
                   }
                   if(ks + es + ys == n && cur <= k){
                    ans += dp[cur][ks][es][ys];
                   }
                }
                
            }
            
        }
    }
    
    cout << ans << endl;
    
}