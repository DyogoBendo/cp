#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
    int n;
    cin >> n;

    vector<int> s1(n + 1);
    vector<int> s2(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> s2[i];
    }
    
    vector<vector<int>> dp1(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp1[i][j] = max({dp1[i - 1][j], dp1[i][j - 1], dp1[i - 1][j - 1] + (abs(s1[i] - s2[j]) <= 4)});
        }
    }
    

    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > 0; j--)
        {
            int a = 0;
            int b = 0;
            int c = 0;
            if(i < n) a = dp2[i + 1][j];
            if(j < n) b = dp2[i][j + 1];
            if(i < n && j < n) c = dp2[i + 1][j + 1];
            dp2[i][j] = max({a, b, c + (abs(s1[i] - s2[j]) <= 4)});
        }
        
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int d = 0;
            if(i < n && j < n) d = dp2[i + 1][j + 1];
            ans = max(ans, dp1[i][j] + d);
        }
        
    }
    
    cout << ans << endl;
    
}