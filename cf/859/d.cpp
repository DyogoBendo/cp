#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> cumulative_sum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cumulative_sum[i + 1] = cumulative_sum[i] + x;
    }
    
    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l --;
        r --;

        int result = cumulative_sum[l] + cumulative_sum[n] - cumulative_sum[r + 1] + ((r - l + 1) * k);

        if(result % 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}