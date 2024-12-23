#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> par_sum(n - 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        par_sum[i] = v[i] + v[i + 1];
    }


    vector<int> maior_par_sum(n, 0);
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        while(curr < n - 1 && par_sum[curr] <= v[i]){
            curr ++;
        }

        maior_par_sum[i] = curr;
    }

    int ans = n + 1;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, n - i - 1 + maior_par_sum[i]);
    }
    
    cout << ans << endl;

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}