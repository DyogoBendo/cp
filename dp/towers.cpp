#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int lis = 0;

    vector<int> dp(n, INF);

    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();

        dp[pos] = v[i];

        lis = max(lis, pos + 1);
    }
    
    cout << lis << endl;
}