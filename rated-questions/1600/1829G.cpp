#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
vector<vector<int>> dp;
const int MAXN = 1e6 + 1;

void init(){
    int row = 0;
    int curr = 1;    
    int curr_sz = 1;
    while(curr < MAXN){        
        vector<int>v(curr_sz);
        for (int i = 0; i < curr_sz && curr < MAXN; i++, curr++)
        {
            v[i] = (curr * curr);
            if(row){                
                if(i < curr_sz - 1){
                    v[i] += dp[row-1][i];
                }
            }
        }         
        dp.push_back(v);
        row++;
        curr_sz++;
    }       
}

void solve(){
    int n;
    cin >> n;

    int row = 0, sz = 1, curr = 1;

    while(n >= curr){        
        row++;
        curr += sz;
        sz ++;
    }
    row--;
    int col = n - (curr - sz + 1);

    int ans = 0;
    while(col >= 0 && row >= 0){
        ans += dp[row][col];
        row--;
        col--;
    }

    cout << ans << endl;
}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}