#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e18;

signed main(){
    freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);

    int n, t;
    cin >> n >> t;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int x, s;
        cin >> x >> s;
        v[i] = -(s * t + x);
    }

    vector<int> lds(n, INF);    
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p = upper_bound(lds.begin(), lds.end(), v[i]) - lds.begin();

        ans = max(ans, p + 1);

        lds[p] = v[i];
    }
    
    cout << ans << endl;
}