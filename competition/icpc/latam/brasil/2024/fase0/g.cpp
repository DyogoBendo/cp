#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

struct P{
    ll x, y;
};

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

signed main(){
    fastio;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> conn (n+1);
    vector<int> dis (n+1);
    vector<int> ran (n+1);
    dis[0] = 0;
    ran[0] = k;
    for (int i=1; i<=n; i++){
        cin >> dis[i];
    }
    for (int i=1; i<=n; i++){
        cin >> ran[i];
        ran[i] += dis[i];
    }

    int ans = 0;
    int cur = 0;
    int best = 0;
    for (int i=1; i<=n; i++){
        if (dis[i] <= ran[cur]){
            if (ran[i] >= ran[best]) best = i;
        }
        else{
            cur = best;
            ans++;
            if (dis[i] <= ran[cur]){
                if (ran[i] >= ran[best]) best = i;
            }
            else{
                ans = -1;
                break;
            }
        }
    }

    cout << ans << '\n';
}