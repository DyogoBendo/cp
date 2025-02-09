// https://codeforces.com/contest/1360/problem/E
#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    vector<int> cnt(n + 1);
    set<pair<int, int>> s;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        s.insert({x, y});
        cnt[x]++;
    }

    int ans=  0;

    for(int i = 0; i <= n; i++) if(cnt[i] == 2) ans += n - 2;

    for(auto p : s){
        int x1 = p.first;
        int y1 = p.second ^ 1;

        pair<int, int> a = {x1-1,y1};
        pair<int, int> b = {x1+1,y1};

        if(s.find(a) != s.end() && s.find(b) != s.end()){
            ans ++;
        }
    }

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}