#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long

signed main() {
    darvem;

    int n;
    cin >> n;    

    ll ax, ay, az;
    cin >> ax >> ay >> az;

    ll sx, sy, sz;
    cin >> sx >> sy >> sz;

    vector<pair<ll, ll>> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].first >> polygon[i].second;
    }
    
    ll dx_r = ax * sz - az * sx;
    ll dy_r = ay * sz - az * sy;
    ll dz_r = sz - az; 

    bool spills = false;

    for (int i = 0; i < n; i++) {
        ll px = polygon[i].first;
        ll py = polygon[i].second;
        ll nx = polygon[(i + 1) % n].first;
        ll ny = polygon[(i + 1) % n].second;
        
        ll vec1_x = nx - px;
        ll vec1_y = ny - py;
        
        ll ry_comp = dy_r - py * dz_r;
        ll rx_comp = dx_r - px * dz_r;
        
        ll cross_scaled = vec1_x * ry_comp - vec1_y * rx_comp;
        
        if (cross_scaled > 0) {
            spills = true;
            break;
        }
    }

    if (spills) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}