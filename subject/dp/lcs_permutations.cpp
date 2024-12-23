#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;

int main(){
    int n, ans = 0;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    vector<int>pa(n + 1);
    vector<int>pb(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pa[a[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        pb[b[i]] = i;
    }

    vector<int> lis(n + 1, INF);

    for (int i = 0; i < n; i++)
    {
        int v = a[i];
        int p1 = pa[v];
        int p2 = pb[v];

        int p = lower_bound(lis.begin(), lis.end(), p2) - lis.begin();

        ans = max(p, ans);
        lis[p] = p2;
    }
    
    cout << ans + 1<< endl;
}