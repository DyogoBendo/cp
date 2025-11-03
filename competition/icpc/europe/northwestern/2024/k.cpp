#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

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

ll INF = 1e18;
int n, m, k;    
vector<vector<pair<int, int>>> g;
vector<ll> diquistra(int st){
    priority_queue<pair<ll, int>> pq;
    pq.push({0, st});
    vector<ll> dist(n, INF);
    vector<int> visited(n);
    while(!pq.empty()){
        auto [dst, curr] = pq.top(); pq.pop();
        dst = -dst;
        if(visited[curr]) continue;

        visited[curr] = 1;
        dist[curr] = dst;

        for(auto e : g[curr]) if(!visited[e.first]) pq.push({-(e.second + dst), e.first});
    }
    return dist;
}

signed main(){
    darvem;

    cin >> n >> m >> k;

    g.resize(n);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<double> p(n);    
    vector<int> always;
    set<int> has;
    for(int i = 0; i < k; i++){
        int a;
        double pro;
        cin >> a >> pro;
        a--;
        p[a] = pro;
        has.insert(a);
        if(pro == 1) always.push_back(a);
    }

    if(sz(always) == 0){
        cout << "impossible" << endl;
        return 0;
    }

    auto d0 = diquistra(0);
    auto dn = diquistra(n-1);

    ll bst = INF;
    for(auto a : always){
        ll dst = d0[a] + dn[a];
        bst = min(dst, bst);
    }
    
    vector<pair<ll, int>> pick;
    for(int i = 0; i < n; i++){
        ll dst = d0[i] + dn[i];
        if(dst >= bst) continue;
        if(has.count(i)) pick.push_back({dst, i});
    }
    sort(pick.begin(), pick.end());

    double curr_p = 1;

    double ans = 0;
    for(auto [dst, curr] : pick){
        double pro = p[curr];
        dbg(ans, curr, curr_p, pro, dst, curr_p*pro*dst);
        ans += (curr_p * pro * dst);
        curr_p *= (1 - pro);
    }
    dbg(bst, curr_p);
    ans += curr_p * bst;

    cout << setprecision(12) <<fixed << ans << endl;
}