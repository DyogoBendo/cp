#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define int long long


void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> points(n);

    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }

    map<ll, ll> cnt;

    for (int i = 0; i < n; i++)
    {
        ll qtd_ponto = (i + 1) * (n - i) - 1;         
        cnt[qtd_ponto]++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        ll intervalo = points[i + 1] - points[i] - 1;
        ll qtd_intervalo = (i + 1) * (n - i - 1);         
        cnt[qtd_intervalo]+= intervalo;
    }

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;

        cout << cnt[k] << " ";
    }
    cout << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}