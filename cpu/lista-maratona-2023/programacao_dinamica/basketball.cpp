#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;
    vector<long long> t1(n);
    vector<long long> t2(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> t1[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> t2[i];
    }
    
    vector<long long> dp1(n);
    vector<long long> dp2(n);
    dp1[0] = t1[0];
    dp2[0] = t2[0];

    for (size_t i = 1; i < n; i++)
    {
        dp1[i] = max(dp1[i - 1], max(dp1[i - 1] - (t1[i - 1] - t1[i]), dp2[i - 1] + t1[i]));
        dp2[i] = max(dp2[i - 1], max(dp2[i - 1] - (t2[i - 1] - t2[i]), dp1[i - 1] + t2[i]));
    }

    cout << max(dp1[n - 1], dp2[n - 1]) << endl;
    
}