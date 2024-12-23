#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e5;
int v[N], n, seg[4 * N];

int build(int p = 1, int l = 0, int r = n - 1){
    if(l > r) return 0;
    if(l == r){
        return seg[p] = v[l];
    }

    int mid = (r + l) / 2;

    return seg[p] = build(2 * p, l, mid) + build(2*p + 1, mid + 1, r);
}

int update(int k, int u, int p = 1, int l = 0, int r = n - 1){
    if(l > r) return 0;
    if(l == r){
        return seg[p] = u;
    }

    int mid = (l + r) / 2;

    int left = seg[2*p];
    int right = seg[2*p + 1];
    if(k <= mid){
        left = update(k, u, 2*p, l, mid);
    } else{
        right = update(k, u, 2*p + 1, mid + 1, r);
    }

    return seg[p] = left + right;
}

int query(int a, int b, int p = 1, int l = 0, int r = n-1){
    if(l > b) return 0;
    if(r < a) return 0;

    if(l >= a && r <= b) return seg[p];

    int mid = (l + r ) / 2;

    int left = query(a, b, 2*p, l, mid);
    int right = query(a, b, 2*p + 1, mid + 1, r);

    return left + right;
}

signed main(){
    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    build();

    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if(t == 1){
            update(a, b);
        } else{
            b--;
            cout << query(a, b) << endl;
        }
    }
    
}