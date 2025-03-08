#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, p;
    cin >> n >> p;

    vector<double> vp(n);
    vector<double> qtd(n);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        int a = r / p;
        int b = (l - 1) / p;

        vp[i] = (a - b);
        qtd[i] = r - l + 1;
    }

    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        int prox = (i + 1) % n;
        
        double p1 = (qtd[i] - vp[i]) / qtd[i];
        double p2 = (qtd[prox] - vp[prox]) / qtd[prox];

        ans += 1 - p1*p2;
    }

    ans *= 2000;
        
    printf("%.9lf\n", ans);
}

signed main(){
    int t;
    t = 1;

    while(t--) solve();
}