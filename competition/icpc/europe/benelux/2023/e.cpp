#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main(){
   int n;
   cin >> n;

   vector<int> dp(n+1, -1);
   dp[0] = 0;
   int prev = 0;

   for (int i = 0; i < n; i++)
   {
        int l, p, r, c;
        cin >> l >> p >> r >> c;

        int curr = l - prev;
        
        for (int j = i; j >=0; j--)
        {
            if(dp[j] != -1){
                dp[j] += curr;  
                if(dp[j] >= c)dp[j+1] = max(dp[j+1], dp[j] + r-p - c);
            } 
        }
        prev = r;
   }

   for (int i = n; i >= 0; i--){
        if(dp[i] != -1){
            cout << i << endl;
            return 0;
        }
   }

}