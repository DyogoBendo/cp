#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

bool can(int x, vector<int> &p)
{
    int n = p.size();

    vector<pair<int, int>> prox;
    int cur = x;
    for (auto piz : p)
    {
        if (piz <= cur){
            cur += piz;
            while (!prox.empty() && prox.back().first <= cur){
                cur += prox.back().second;
                prox.pop_back();
            }
        }
        else{
            prox.push_back({piz, cur - x + piz});
            cur = x;
        }
    }

    return prox.empty();
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n * 2);
    for (int i = 0; i < n; i++){
        cin >> p[i];
        p[i + n] = p[i];
    }

    int l = -1, r = 1e13;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (can(m, p)) r = m;
        else l = m;
    }

    cout << r << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}