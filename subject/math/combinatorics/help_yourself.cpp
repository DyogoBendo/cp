#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int mul(int x, int y){
    return 1LL * x * y % MOD;
}

int add(int x, int y){
    return (x+y) % MOD;
}

int main(){
    setIO("help");

    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        events.push_back({r, 1});
        events.push_back({l, 0});
    }
    sort(events.begin(), events.end());

    int ans = 0, to_add = 1;
    for(auto [pos, t] : events){        
        if(t == 0){
            ans = add(add(ans, ans), 1);            
            ans = add(ans, (to_add + MOD - 1) % MOD);
        } else{
            to_add = add(to_add, to_add);
        }
    }
    cout << ans << endl;
}