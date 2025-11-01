#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> days(n+1);    
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        days[i].first = x;
        days[i].second = i;        
    } 

    sort(days.begin(), days.end());

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 1e18));
    vector<vector<ll>> ndp(n+1, vector<ll>(k+1));
    for(int i = 0; i <= k; i++) dp[0][i] = 0;

    dbg(n, k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){                      
            if(j > 1){
                dp[i][j] = dp[i-1][j-1];
                ndp[i][j] = i-1;
            } 
            ll curr = 0;
            for(int a = i - 1; a > 0; a--){
                ll diff = days[i].first - days[a].first;
                curr += diff*diff; 
                if(k > 1 && dp[a-1][j-1] + curr < dp[i][j]){
                  dp[i][j] = dp[a-1][j-1] + curr;  
                  ndp[i][j] = a-1;             
                  dbg(a-1, j-1, dp[a-1][j-1]);
                } 
            }               
            if(curr < dp[i][j]){
                dp[i][j] = curr;
                ndp[i][j] = 0;
            }            
            dbg(i, j, dp[i][j], ndp[i][j]);
        }
    }

    int pos = n, av = k;
    vector<int> choices;
    while(pos != 0){
        choices.push_back(days[pos].first);
        pos = ndp[pos][av];
        dbg(pos);
        av--;
    }
    vector<int> ans(n+1);    
    reverse(choices.begin(), choices.end());
    int curr = 0;
    for(int i = 1; i <= n; i++){
        while(days[i].first > choices[curr]) curr++;
        ans[days[i].second] = choices[curr];
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}