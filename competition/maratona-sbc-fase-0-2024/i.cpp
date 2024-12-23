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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> blocks (n);
    // build blocks
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            blocks[j] += s[j*m + i] - '0';
        }
    }
    //for (auto b: blocks) cout << b << '\n';

    // borders for easier implementation
    vector<pair<int, int>> borders (n);
    for (int i=0; i<n; i++) borders[i] = {i*m, (i+1)*m};

    vector<int> appeared (n*m);
    bool ans = true;
    // update every block
    for (int i=0; i<m; i++){
        for (auto b: blocks){
            if (appeared[b]) ans = false;
            appeared[b] = 1;
        }
        for (auto b: blocks){
            appeared[b] = 0;
        }

        if (ans == false) break;

        for (int j=0; j<n; j++){
            borders[j].first %= n*m;
            borders[j].second %= n*m;
            blocks[j] -= s[borders[j].first] - '0';
            blocks[j] += s[borders[j].second] - '0';
            borders[j].first++;
            borders[j].second++;
        }
    }

    if (ans) cout << 'S';
    else cout << 'N';
    cout << '\n';
}