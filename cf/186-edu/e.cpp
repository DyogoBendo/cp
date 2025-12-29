#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define int long long

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> boxes(m);
    for(int i = 0; i < m; i++) cin >> boxes[i];

    vector<pair<int, int>> people(n); 
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        people[i] = {x, z - y};
        k -= y;
    }

    sort(people.begin(), people.end());
    sort(boxes.begin(), boxes.end());

    priority_queue<pair<int, int>> pq;
    int pos = 0;
    int ans = 0;

    for(int i = 0; i < m; i++){
        int curr= boxes[i];

        while(pos < n and people[pos].first <= curr){
            pq.push({people[pos].second, people[pos].first});
            pos++;
        }

        if(!pq.empty()){
            pq.pop();
            ans++;
        }
    }

    vector<int> v;
    while(!pq.empty()){
        v.push_back(pq.top().first);
        pq.pop();
    }

    for(int i = pos; i < n; i++) v.push_back(people[i].second);

    sort(v.begin(), v.end());

    for(auto e : v) if(e <= k){
        k -= e;
        ans++;
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}