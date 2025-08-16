#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

pair<int, int> calc(pair<int, int> p1, pair<int, int> p2){
    int dx = p2.first - p1.first;
    int dy = p2.second - p1.second;
    int g = __gcd(dx, dy);
    dx /= g;
    dy/= g;
    if(dx == 0) dy = 1;
    if(dy == 0) dx = 1;

    return {dy, dx};
}

int dist(pair<int, int> p1, pair<int, int> p2){
    int dx = p2.first - p1.first;
    int dy = p2.second - p1.second;
    return dx*dx + dy*dy;
}

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);

    for(int i = 0; i < n; i++){
        cin >> pts[i].first >> pts[i].second;
    }

    map<pair<int, int>, int> cnt_tot;
    map<tuple<int, int, int>, int> cnt_remove;
    ll tot = 0, remove = 0;    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            auto p = calc(pts[i], pts[j]);            

            tot += cnt_tot[p];            
            cnt_tot[p]++;
            int d = dist(pts[i], pts[j]);
            remove += cnt_remove[{p.first, p.second, d}];
            cnt_remove[{p.first, p.second, d}] ++;
        }
    }
    remove/=2;
    cout << tot - remove << endl;
}