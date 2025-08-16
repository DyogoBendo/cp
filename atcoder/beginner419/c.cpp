#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
ll tx = 0, ty = 0;

int ans(int m, vector<int> &v){
    return max(m - v[0], v.back() - m);
}

signed main(){
    darvem;
    int n;
    cin >> n;

    vector<int> xs(n), ys(n);

    for(int i = 0; i < n; i++){
        cin >> xs[i] >> ys[i];
        tx += xs[i];
        ty += ys[i];
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int mx = (xs.back() - xs[0]) / 2 + xs[0];
    int my = (ys.back() - ys[0])/2 + ys[0];

    int x = min(ans(mx, xs), ans(mx+1, xs));
    int y = min(ans(my, ys), ans(my+1, ys));

    cout << max(x, y) << endl;
}